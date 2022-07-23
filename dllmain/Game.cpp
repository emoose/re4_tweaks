#include "dllmain.h"
#include "Game.h"
#include "Patches.h"

std::string gameVersion;
bool gameIsDebugBuild = false;

std::unordered_map<int, std::string> EmNames =
{
	{0x00, "Player"},
	{0x50, "EmObj"},
	{0x51, "EmDoor"},
	{0x52, "EmWep"},
	{0x53, "EmBox"},
	//0x54 unused?
	{0x55, "EmRack"},
	{0x56, "EmWindow"},
	{0x57, "EmTorch"},
	{0x58, "EmBarrel"},
	{0x59, "EmTree"},
	{0x5A, "EmRock"},
	{0x5B, "EmSwitch"},
	{0x5C, "EmItem"},
	{0x5D, "EmHit"},
	{0x5E, "EmBarred"},
	{0x5F, "EmMine"},
	{0x60, "EmShield"},
	{0x61, "EmBar"},
};

// a lot missing from here sadly ;_;
std::unordered_map<int, std::string> UnitBeFlagNames =
{
	{ 0x1, "Alive1" },
	{ 0x2, "Trans" },
	{ 0x20, "Move" },
	{ 0x200, "Alive200" },
	{ 0x800, "NoSuspend" }
};

std::string cEmMgr::EmIdToName(int id)
{
	if (EmNames.count(id))
		return EmNames[id];
	std::stringstream ss;
	ss << "Em" << std::setfill('0') << std::setw(2) << id;
	return ss.str();
}

std::string cUnit::GetBeFlagName(int flagIndex)
{
	int flagValue = (1 << flagIndex);
	if (UnitBeFlagNames.count(flagValue))
		return UnitBeFlagNames[flagValue];
	return "Bit" + std::to_string(flagIndex);
}

std::string GameVersion()
{
	return gameVersion;
}

bool GameVersionIsDebug()
{
	return gameIsDebugBuild;
}

uint32_t* ptrLastUsedDevice = nullptr;
InputDevices LastUsedDevice()
{
	return *(InputDevices*)(ptrLastUsedDevice);
}

uint32_t* ptrMouseSens = nullptr;
int g_MOUSE_SENS()
{
	return *(int8_t*)(ptrMouseSens);
}

uint32_t* ptrMouseAimMode = nullptr;
MouseAimingModes GetMouseAimingMode()
{
	return *(MouseAimingModes*)(ptrMouseAimMode);
}

void SetMouseAimingMode(MouseAimingModes newMode)
{
	*(int8_t*)(ptrMouseAimMode) = (int8_t)newMode;
	return;
}

static uint32_t* ptrKey_btn_on;
uint64_t  Key_btn_on()
{
	return *(uint64_t*)(ptrKey_btn_on);
}

static uint32_t* ptrKey_btn_trg;
uint64_t  Key_btn_trg()
{
	return *(uint64_t*)(ptrKey_btn_trg);
}

GLOBALS** pG_ptr = nullptr;
GLOBALS* GlobalPtr()
{
	if (!pG_ptr)
		return nullptr;

	return *pG_ptr;
}

DAMAGE* pD_ptr = nullptr;
DAMAGE* DamagePtr() {
	if (!pD_ptr)
		return nullptr;

	return pD_ptr;
}

SYSTEM_SAVE** pSys_ptr = nullptr;
SYSTEM_SAVE* SystemSavePtr()
{
	if (!pSys_ptr)
		return nullptr;

	return *pSys_ptr;
}

cPlayer** pPL_ptr = nullptr;
cPlayer* PlayerPtr()
{
	if (*pPL_ptr == nullptr)
		return nullptr;

	if (**(int**)pPL_ptr < 0x10000)
		return nullptr;

	return *pPL_ptr;
}

cPlayer** pAS_ptr = nullptr;
cPlayer* AshleyPtr()
{
	if (*pAS_ptr == nullptr)
		return nullptr;

	if (**(int**)pAS_ptr < 0x10000)
		return nullptr;

	return *pAS_ptr;
}

uint8_t** g_GameSave_BufPtr = nullptr;
uint8_t* GameSavePtr()
{
	if (!g_GameSave_BufPtr)
		return nullptr;

	return *g_GameSave_BufPtr;
}

cEmMgr* EmMgr_ptr = nullptr;
cEmMgr* EmMgrPtr()
{
	return EmMgr_ptr;
}

// Original game funcs
bool(__cdecl* game_KeyOnCheck_0)(KEY_BTN a1);
void(__cdecl* game_C_MTXOrtho)(Mtx44 mtx, float PosY, float NegY, float NegX, float PosX, float Near, float Far);

bool Init_Game()
{
	// Detect game version
	auto pattern = hook::pattern("31 2E ? ? ? 00 00 00 6D 6F 76 69 65 2F 64 65 6D 6F 30 65 6E 67 2E 73 66 64");
	int ver = injector::ReadMemory<int>(pattern.count(1).get(0).get<uint32_t>(2));

	if (ver == 0x362E30) {
		gameVersion = "1.0.6";
	}
	else if (ver == 0x302E31) {
		gameVersion = "1.1.0";
	}
	else {
		::MessageBoxA(NULL, "This version of RE4 is not supported.\nre4_tweaks will be disabled.", "re4_tweaks", MB_ICONERROR | MB_SYSTEMMODAL | MB_SETFOREGROUND);
		return false;
	}

	// Check for part of gameDebug function, if exists this must be a debug-enabled build
	pattern = hook::pattern("6A 00 6A 00 6A 08 68 AE 01 00 00 6A 10 6A 0A");
	if (pattern.size() > 0)
	{
		gameVersion += "d";
		gameIsDebugBuild = true;
	}

	#ifdef VERBOSE
	con.AddConcatLog("Game version = ", GameVersion().data());
	#endif

	// LastUsedDevice pointer
	pattern = hook::pattern("A1 ? ? ? ? 85 C0 74 ? 83 F8 ? 74 ? 81 F9");
	ptrLastUsedDevice = *pattern.count(1).get(0).get<uint32_t*>(1);

	// g_MOUSE_SENS pointer
	pattern = hook::pattern("0F B6 05 ? ? ? ? 89 85 ? ? ? ? DB 85 ? ? ? ? DC 35");
	ptrMouseSens = *pattern.count(1).get(0).get<uint32_t*>(3);

	// Mouse aiming mode pointer
	pattern = hook::pattern("80 3D ? ? ? ? ? 0F B6 05");
	ptrMouseAimMode = *pattern.count(1).get(0).get<uint32_t*>(2);

	// Pointer to Key_btn_on
	pattern = hook::pattern("A1 ? ? ? ? 33 C9 83 E0 ? 83 3D");
	ptrKey_btn_on = *pattern.count(1).get(0).get<uint32_t*>(1);

	// Pointer to Key_btn_trg
	pattern = hook::pattern("A1 ? ? ? ? 25 ? ? ? ? 0B C1 74 ? 88 0D");
	ptrKey_btn_trg = *pattern.count(1).get(0).get<uint32_t*>(1);

	// Grab pointer to pG (pointer to games Global struct)
	pattern = hook::pattern("A1 ? ? ? ? B9 FF FF FF 7F 21 48 ? A1");
	pG_ptr = *pattern.count(1).get(0).get<GLOBALS**>(1);

	// pDamage pointer
	pattern = hook::pattern("8A 8B C3 4F 00 00 89 45 0C");
	pD_ptr = *pattern.count(1).get(0).get<DAMAGE*>(-0xB);

	// pSys pointer
	pattern = hook::pattern("00 80 00 00 83 C4 ? E8 ? ? ? ? A1 ? ? ? ?");
	pSys_ptr = *pattern.count(1).get(0).get<SYSTEM_SAVE**>(13);

	// pPL pointer
	pattern = hook::pattern("A1 ? ? ? ? D8 CC D8 C9 D8 CA D9 5D ? D9 45 ?");
	pPL_ptr = *pattern.count(1).get(0).get<cPlayer**>(1);

	// pAS pointer
	pattern = hook::pattern("A8 02 74 16 8B 15");
	pAS_ptr = *pattern.count(1).get(0).get<cPlayer**>(6);

	// g_GameSave_BufPtr pointer (not actual name)
	pattern = hook::pattern("89 15 ? ? ? ? C7 05 ? ? ? ? A0 FA 0F 00");
	g_GameSave_BufPtr = *pattern.count(1).get(0).get<uint8_t**>(2);

	// Pointer to the original KeyOnCheck
	pattern = hook::pattern("E8 ? ? ? ? 83 C4 ? 84 C0 74 ? C7 86 ? ? ? ? ? ? ? ? 5E B8 ? ? ? ? 5B 8B E5 5D C3 53");
	ReadCall(injector::GetBranchDestination(pattern.count(1).get(0).get<uint32_t>(0)).as_int(), game_KeyOnCheck_0);

	// pointer to EmMgr (instance of cManager<cEm>)
	pattern = hook::pattern("81 E1 01 02 00 00 83 F9 01 75 ? 50 B9 ? ? ? ? E8");
	EmMgr_ptr = *pattern.count(1).get(0).get<cEmMgr*>(0xD);

	return true;
}
