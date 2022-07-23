#include <iostream>
#include "dllmain.h"
#include "Patches.h"
#include "Settings.h"
#include "input.hpp"

uintptr_t* ptrCamXmovAddr;
uintptr_t* ptrKnife_r3_downMovAddr;

static uint32_t* ptrMouseDeltaX;

uint32_t* ptrCamXPosAddr;

int intMouseDeltaX()
{
	return *(int32_t*)(ptrMouseDeltaX);
}

std::vector<uint32_t> mouseTurnModifierCombo;

bool ParseMouseTurnModifierCombo(std::string_view in_combo)
{
	mouseTurnModifierCombo.clear();
	mouseTurnModifierCombo = ParseKeyCombo(in_combo);
	return mouseTurnModifierCombo.size() > 0;
}

bool bPrevMouseTurnState = false;
bool bMouseTurnStateChanged = false;

bool isMouseTurnEnabled()
{
	bool modifierPressed = pInput->is_combo_down(&mouseTurnModifierCombo);

	bool state = pConfig->bUseMouseTurning;

	// Invert mouse turning setting if modifier pressed
	// If mouse turning enabled: modifier disables turning, allows camera movement
	// If mouse turning disabled: modifier enables mouse turning temporarily
	// (if user wants to completely disable mouse turning, they can clear the combination)
	if (modifierPressed)
		state = !state;

	bMouseTurnStateChanged = bPrevMouseTurnState != state;

	// Reset camera position if modifier is pressed
	if (bMouseTurnStateChanged)
	{
		*(float*)(ptrCamXPosAddr) = 0.0f;
		*(int8_t*)(ptrCamXmovAddr) = 0;
	}

	bPrevMouseTurnState = state;

	return state;
}

void MouseTurn()
{
	float SpeedMulti = 900;

	// "Classic" aiming mode (0x00) needs lower sensitivity here.
	if (GetMouseAimingMode() == MouseAimingModes::Classic)
		SpeedMulti = 1300;

	PlayerPtr()->rotation_A0.y += (-intMouseDeltaX() / SpeedMulti) * pConfig->fTurnSensitivity;
}

bool __cdecl KeyOnCheck_hook(KEY_BTN a1)
{
	// Enable the turning animation/action if the mouse is moving

	bool ret = false;
	bool isMovingMouse = false;

	if (a1 == KEY_BTN::KEY_LEFT)
		isMovingMouse = (intMouseDeltaX() < 0);
	else if (a1 == KEY_BTN::KEY_RIGHT)
		isMovingMouse = (intMouseDeltaX() > 0);

	switch (LastUsedDevice()) {
		case InputDevices::DinputController:
		case InputDevices::XinputController:
			ret = game_KeyOnCheck_0(a1);
			break;
		case InputDevices::Keyboard:
		case InputDevices::Mouse:
			if (isMouseTurnEnabled() && isMovingMouse)
				ret = true;
			else
				ret = game_KeyOnCheck_0(a1);
			break;
	}

	return ret;
}

void GetMouseTurnPointers()
{
	auto pattern = hook::pattern("DB 05 ? ? ? ? D9 45 ? D9 C0 DE CA D9 C5");
	ptrMouseDeltaX = *pattern.count(1).get(0).get<uint32_t*>(2);

	pattern = hook::pattern("A2 ? ? ? ? EB ? DD D8 8B 0D ? ? ? ? 8B 81 ? ? ? ? A9");
	ptrCamXmovAddr = *pattern.count(1).get(0).get<uint32_t*>(1);
}

void Init_MouseTurning()
{
	GetMouseTurnPointers();

	// Keep CameraXpos at 0f while isMouseTurnEnabled
	auto pattern = hook::pattern("D9 05 ? ? ? ? DE C2 D9 C9 D9 1D ? ? ? ? D9 85");
	ptrCamXPosAddr = *pattern.count(1).get(0).get<uint32_t*>(2);
	struct CameraPositionWriter
	{
		void operator()(injector::reg_pack& regs)
		{
			float CameraXpos;

			if ((LastUsedDevice() == InputDevices::Keyboard) || (LastUsedDevice() == InputDevices::Mouse))
			{
				if (isMouseTurnEnabled())
					CameraXpos = 0.0f;
				else
					CameraXpos = *(float*)(ptrCamXPosAddr);
			}
			else
				CameraXpos = *(float*)(ptrCamXPosAddr);

			_asm {fld CameraXpos}

		}
	}; injector::MakeInline<CameraPositionWriter>(pattern.count(1).get(0).get<uint32_t>(0), pattern.count(1).get(0).get<uint32_t>(6));

	// Trigger left turn
	pattern = hook::pattern("E8 ? ? ? ? 83 C4 ? 84 C0 74 ? C7 86 ? ? ? ? ? ? ? ? 5E B8 ? ? ? ? 5B 8B E5 5D C3 8A 86");
	InjectHook(pattern.count(1).get(0).get<uint32_t>(0), KeyOnCheck_hook, PATCH_CALL);

	// Trigger right turn
	pattern = hook::pattern("E8 ? ? ? ? 83 C4 ? 84 C0 74 ? C7 86 ? ? ? ? ? ? ? ? 5E B8 ? ? ? ? 5B 8B E5 5D C3 53");
	InjectHook(pattern.count(1).get(0).get<uint32_t>(0), KeyOnCheck_hook, PATCH_CALL);

	// pl_R1_Turn (left and right separated) TODO: Combine them?
	pattern = hook::pattern("A1 ? ? ? ? 83 E0 ? 33 C9 0B C1 75 ? 89 9E");
	struct pl_R1_Turn_left
	{
		void operator()(injector::reg_pack& regs)
		{
			// Code we replaced
			regs.eax = (uint32_t)Key_btn_on();

			switch (LastUsedDevice()) {
			case InputDevices::DinputController:
			case InputDevices::XinputController:
				break;
			case InputDevices::Keyboard:
			case InputDevices::Mouse:
				// Get pointer to cModel->MotInfo_1D8
				MOTION_INFO* mi_ptr = (MOTION_INFO*)(regs.esi + 0x1D8);

				// Check if default key is being pressed
				bool isPressingDefaultKey = ((Key_btn_on() & (uint64_t)KEY_BTN::KEY_LEFT) == (uint64_t)KEY_BTN::KEY_LEFT);

				// Make game go back to the default procedure if the user started to hold the default key after moving the mouse
				if (isPressingDefaultKey && (mi_ptr->motionFlags_40 == 4))
					regs.eax = 0;
				else if (isMouseTurnEnabled() && (intMouseDeltaX() < -8) && !isPressingDefaultKey)
				{
					// Setting this flag to 4 makes MotionMove not apply any rotation/position changes
					// Very lucky for us, but I'm not sure what the real intent of this value/flag even is
					mi_ptr->motionFlags_40 = 4;

					regs.eax = 0x8;

					MouseTurn();
				}
				break;
			}
		}
	}; injector::MakeInline<pl_R1_Turn_left>(pattern.count(1).get(0).get<uint32_t>(0), pattern.count(1).get(0).get<uint32_t>(5));

	pattern = hook::pattern("A1 ? ? ? ? 83 E0 ? 33 C9 0B C1 75 ? 89 8E");
	struct pl_R1_Turn_right
	{
		void operator()(injector::reg_pack& regs)
		{
			// Code we replaced
			regs.eax = (uint32_t)Key_btn_on();

			switch (LastUsedDevice()) {
			case InputDevices::DinputController:
			case InputDevices::XinputController:
				break;
			case InputDevices::Keyboard:
			case InputDevices::Mouse:
				// Get pointer to cModel->MotInfo_1D8
				MOTION_INFO* mi_ptr = (MOTION_INFO*)(regs.esi + 0x1D8);

				// Check if default key is being pressed
				bool isPressingDefaultKey = ((Key_btn_on() & (uint64_t)KEY_BTN::KEY_RIGHT) == (uint64_t)KEY_BTN::KEY_RIGHT);

				// Make game go back to the default procedure if the user started to hold the default key after moving the mouse
				if (isPressingDefaultKey && (mi_ptr->motionFlags_40 == 4))
					regs.eax = 0;
				else if (isMouseTurnEnabled() && (intMouseDeltaX() > 8) && !isPressingDefaultKey)
				{
					// Setting this flag to 4 makes MotionMove not apply any rotation/position changes
					// Very lucky for us, but I'm not sure what the real intent of this value/flag even is
					mi_ptr->motionFlags_40 = 4;

					regs.eax = 0x4;

					MouseTurn();
				}
				break;
			}
		}
	}; injector::MakeInline<pl_R1_Turn_right>(pattern.count(1).get(0).get<uint32_t>(0), pattern.count(1).get(0).get<uint32_t>(5));

	// pl_R1_Turn180
	pattern = hook::pattern("0F B6 86 ? ? ? ? 33 DB 2B C3 74 ? 48 74 ? 8B 16");
	struct TurnHook180
	{
		void operator()(injector::reg_pack& regs)
		{
			regs.eax = *(int8_t*)(regs.esi + 0xFE);

			if (isMouseTurnEnabled() && (LastUsedDevice() == InputDevices::Keyboard) || (LastUsedDevice() == InputDevices::Mouse))
				MouseTurn();
		}
	}; injector::MakeInline<TurnHook180>(pattern.count(1).get(0).get<uint32_t>(0), pattern.count(1).get(0).get<uint32_t>(7));

	// Walk/Run struct
	struct TurnHookWalkRun
	{
		void operator()(injector::reg_pack& regs)
		{
			regs.ebp = *(int32_t*)(regs.esp);
			*(int32_t*)(regs.esp) -= 0x8;

			if (isMouseTurnEnabled() && (LastUsedDevice() == InputDevices::Keyboard) || (LastUsedDevice() == InputDevices::Mouse))
				MouseTurn();
		}
	};

	// pl_R1_Walk
	pattern = hook::pattern("8B EC 83 EC ? 53 56 8B 75 ? 33 DB 38 9E");
	injector::MakeInline<TurnHookWalkRun>(pattern.count(1).get(0).get<uint32_t>(0), pattern.count(1).get(0).get<uint32_t>(5));

	// pl_R1_Run
	pattern = hook::pattern("8B EC 83 EC ? 53 56 8B 75 ? 0F B6 86 ? ? ? ? 33 DB");
	injector::MakeInline<TurnHookWalkRun>(pattern.count(1).get(0).get<uint32_t>(0), pattern.count(1).get(0).get<uint32_t>(5));

	// pl_R1_Back
	pattern = hook::pattern("83 3D ? ? ? ? ? 75 ? D9 05 ? ? ? ? 8B 8E ? ? ? ? 83 EC ? D9");
	struct TurnHookWalkingBack
	{
		void operator()(injector::reg_pack& regs)
		{
			if (isMouseTurnEnabled() && (LastUsedDevice() == InputDevices::Keyboard) || (LastUsedDevice() == InputDevices::Mouse))
				MouseTurn();
		}
	}; injector::MakeInline<TurnHookWalkingBack>(pattern.count(3).get(1).get<uint32_t>(0), pattern.count(3).get(1).get<uint32_t>(7));
	injector::WriteMemory(pattern.count(3).get(1).get<uint32_t>(7), uint8_t(0xEB), true);

	// Cancel the Knife_r3_down animation if we move the mouse (indicating we want to turn ASAP)
	pattern = hook::pattern("A1 ? ? ? ? 25 ? ? ? ? 33 C9 0B C1 74 ? 8B 86 ? ? ? ? 39 48");
	ptrKnife_r3_downMovAddr = *pattern.count(1).get(0).get<uint32_t*>(1);
	struct Knife_r3_downHook
	{
		void operator()(injector::reg_pack& regs)
		{
			regs.eax = *(int32_t*)ptrKnife_r3_downMovAddr;
			if (isMouseTurnEnabled() && (intMouseDeltaX() != 0) && (LastUsedDevice() == InputDevices::Keyboard) || (LastUsedDevice() == InputDevices::Mouse))
				regs.eax = 0x8;
		}
	}; injector::MakeInline<Knife_r3_downHook>(pattern.count(1).get(0).get<uint32_t>(0), pattern.count(1).get(0).get<uint32_t>(5));

	if (pConfig->bUseMouseTurning)
		spd::log()->info("{} -> MouseTurning enabled", __FUNCTION__);
}