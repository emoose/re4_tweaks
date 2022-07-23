#pragma once

// Button definitions used by tool menus
enum class GamePadButton
{
	DPad_Left = 1,
	DPad_Right = 2,
	DPad_Down = 4,
	DPad_Up = 8,
	RT = 0x10,
	RB = 0x20,
	LB = 0x40,
	LT = 0x80,
	A = 0x100,
	B = 0x200,
	X = 0x400,
	Y = 0x800,
	Start = 0x1000,
	Back = 0x2000,
	RS = 0x4000,
	LS = 0x8000,
	LS_Left = 0x10000,
	LS_Right = 0x20000,
	LS_Down = 0x40000,
	LS_Up = 0x80000,
	RS_Left = 0x100000,
	RS_Right = 0x200000,
	RS_Down = 0x400000,
	RS_Up = 0x800000,
};

enum class Flags_DEBUG
{
	DBG_TEST_MODE = 0, // 0x80000000 (@ 0x0)
	DBG_SCR_TEST = 1, // 0x40000000 (@ 0x0)
	DBG_BACK_CLIP = 2, // 0x20000000 (@ 0x0)
	DBG_DBG_CAM = 3, // 0x10000000 (@ 0x0)
	DBG_SAT_DISP = 4, // 0x8000000 (@ 0x0)
	DBG_EAT_DISP = 5, // 0x4000000 (@ 0x0)
	DBG_EVENT_TOOL = 6, // 0x2000000 (@ 0x0)
	DBG_SLOW_ON = 7, // 0x1000000 (@ 0x0)
	DBG_SHADOW_POLYGON = 8, // 0x800000 (@ 0x0)
	DBG_SCE_AT_DISP = 9, // 0x400000 (@ 0x0)
	DBG_SCR2_TEST = 10, // 0x200000 (@ 0x0)
	DBG_SHADOW_FRAME = 11, // 0x100000 (@ 0x0)
	DBG_MIRROR_POLYGON = 12, // 0x80000 (@ 0x0)
	DBG_GROUND_DISP = 13, // 0x40000 (@ 0x0)
	DBG_SKELETON_DISP = 14, // 0x20000 (@ 0x0)
	DBG_ESPTOOL_ONSCR = 15, // 0x10000 (@ 0x0)
	DBG_CINESCO_OFF = 16, // 0x8000 (@ 0x0)
	DBG_RTP_DISP = 17, // 0x4000 (@ 0x0)
	DBG_ROOM_WIRE_DISP = 18, // 0x2000 (@ 0x0)
	DBG_EM_YARARE_DISP = 19, // 0x1000 (@ 0x0)
	DBG_CAM_AREA_OFF = 20, // 0x800 (@ 0x0)
	DBG_CLOTH_AT_DISP = 21, // 0x400 (@ 0x0)
	// 22, // 0x200 (@ 0x0)
	DBG_ESPTOOL_MEM_USE = 23, // 0x100 (@ 0x0)
	DBG_TEX_RENDER_ALL = 24, // 0x80 (@ 0x0)
	DBG_ESPTOOL_ONEM = 25, // 0x40 (@ 0x0)
	DBG_EMINFO_DISP = 26, // 0x20 (@ 0x0)
	DBG_LIGHT_TOOL = 27, // 0x10 (@ 0x0)
	DBG_EM_COUNT = 28, // 0x8 (@ 0x0)
	// 29, // 0x4 (@ 0x0)
	DBG_EM3F_ADA_SADLER = 30, // 0x2 (@ 0x0)
	DBG_CAM_ANTIGRO_OFF = 31, // 0x1 (@ 0x0)
	DBG_COCKPIT_TOOL = 32, // 0x80000000 (@ 0x4)
	DBG_BOUNDING_DISP = 33, // 0x40000000 (@ 0x4)
	DBG_ADJUST_CAM = 34, // 0x20000000 (@ 0x4)
	DBG_FLAT_FLOOR = 35, // 0x10000000 (@ 0x4)
	DBG_OBJ_SKELETON_ = 36, // 0x8000000 (@ 0x4)
	DBG_DRAW_SH_TEX = 37, // 0x4000000 (@ 0x4)
	DBG_EM_NO_ATK = 38, // 0x2000000 (@ 0x4)
	DBG_NO_EST_CALL = 39, // 0x1000000 (@ 0x4)
	DBG_IN_ESP_TOOL = 40, // 0x800000 (@ 0x4)
	DBG_TERM_TOOL = 41, // 0x400000 (@ 0x4)
	DBG_WARN_LEVEL_LOW = 42, // 0x200000 (@ 0x4)
	// 43, // 0x100000 (@ 0x4)
	// 44, // 0x80000 (@ 0x4)
	// 45, // 0x40000 (@ 0x4)
	// 46, // 0x20000 (@ 0x4)
	DGG_TIMER_STOP = 47, // 0x10000 (@ 0x4)
	DBG_SCREEN_SHOT = 48, // 0x8000 (@ 0x4)
	DBG_SERIES_SHOT = 49, // 0x4000 (@ 0x4)
	DBG_ASHLEY_NO_CATCH = 50, // 0x2000 (@ 0x4)
	DBG_RENSYA = 51, // 0x1000 (@ 0x4)
	DBG_CERO = 52, // 0x800 (@ 0x4)
	// 53, // 0x400 (@ 0x4)
	// 54, // 0x200 (@ 0x4)
	// 55, // 0x100 (@ 0x4)
	DBG_Wii_PAD = 56, // 0x80 (@ 0x4)
	// 57, // 0x40 (@ 0x4)
	// 58, // 0x20 (@ 0x4)
	// 59, // 0x10 (@ 0x4)
	// 60, // 0x8 (@ 0x4)
	// 61, // 0x4 (@ 0x4)
	// 62, // 0x2 (@ 0x4)
	// 63, // 0x1 (@ 0x4)
	DBG_ROOMJMP = 64, // 0x80000000 (@ 0x8)
	DBG_PROC_BAR = 65, // 0x40000000 (@ 0x8)
	DBG_SCA_VIEW = 66, // 0x20000000 (@ 0x8)
	DBG_OBA_VIEW = 67, // 0x10000000 (@ 0x8)
	DBG_SLOW_MODE = 68, // 0x8000000 (@ 0x8)
	DBG_NO_SCE_EXE = 69, // 0x4000000 (@ 0x8)
	DBG_SINGLE_DISK = 70, // 0x2000000 (@ 0x8)
	DBG_BUGCHECK_MODE = 71, // 0x1000000 (@ 0x8)
	DBG_NO_DEATH = 72, // 0x800000 (@ 0x8)
	DBG_INF_BULLET = 73, // 0x400000 (@ 0x8)
	DBG_NO_ENEMY = 74, // 0x200000 (@ 0x8)
	DBG_BGM_STOP = 75, // 0x100000 (@ 0x8)
	DBG_SE_STOP = 76, // 0x80000 (@ 0x8)
	DBG_PL_LOCK_FOLLOW = 77, // 0x40000 (@ 0x8)
	DBG_EM_NO_DEATH = 78, // 0x20000 (@ 0x8)
	DBG_KAIOUKEN = 79, // 0x10000 (@ 0x8)
	DBG_PAD_INFO = 80, // 0x8000 (@ 0x8)
	DBG_UNDER_CONST = 81, // 0x4000 (@ 0x8)
	DBG_EM_WEAK = 82, // 0x2000 (@ 0x8)
	DBG_EM_LIFE_DISP = 83, // 0x1000 (@ 0x8)
	DBG_SHADOW_LIGHT = 84, // 0x800 (@ 0x8)
	DBG_CAPTION_OFF = 85, // 0x400 (@ 0x8)
	DBG_TEST_MODE_CK = 86, // 0x200 (@ 0x8)
	DBG_LIGHT_ERR_CHECK = 87, // 0x100 (@ 0x8)
	DBG_EST_CALL_CHK = 88, // 0x80 (@ 0x8)
	DBG_GX_WARN_ALL = 89, // 0x40 (@ 0x8)
	DBG_GX_WARN_MIDIUM = 90, // 0x20 (@ 0x8)
	DBG_GX_WARN_SEVERE = 91, // 0x10 (@ 0x8)
	DBG_PL_NOHIT = 92, // 0x8 (@ 0x8)
	DBG_SE_ERR_ALL = 93, // 0x4 (@ 0x8)
	DBG_QUICK_EM_STOP = 94, // 0x2 (@ 0x8)
	DBG_AV_TEST = 95, // 0x1 (@ 0x8)
	DBG_INF_BULLET2 = 96, // 0x80000000 (@ 0xc)
	DBG_BATTLE_CAM = 97, // 0x40000000 (@ 0xc)
	DBG_PL_KLAUSER = 98, // 0x20000000 (@ 0xc)
	DBG_MAP_ZOOM_ORG = 99, // 0x10000000 (@ 0xc)
	DBG_SCISSOR_OFF = 100, // 0x8000000 (@ 0xc)
	DBG_LOG_OFF = 101, // 0x4000000 (@ 0xc)
	DBG_SCR_CHECK = 102, // 0x2000000 (@ 0xc)
	DBG_OBJ_SERVER = 103, // 0x1000000 (@ 0xc)
	DBG_START_ST2 = 104, // 0x800000 (@ 0xc)
	DBG_ERRORL_CK = 105, // 0x400000 (@ 0xc)
	DBG_APP_USE_DBMEM = 106, // 0x200000 (@ 0xc)
	DBG_REFRACT_CK = 107, // 0x100000 (@ 0xc)
	DBG_EM_NO_DIE_FLAG = 108, // 0x80000 (@ 0xc)
	DBG_START_ST3 = 109, // 0x40000 (@ 0xc)
	DBG_6e = 110, // 0x20000 (@ 0xc)
	DBG_DOOR_SET_MODE = 111, // 0x10000 (@ 0xc)
	DBG_EFF_NUM_DISP = 112, // 0x8000 (@ 0xc)
	DBG_SET_HITMARK_ALL = 113, // 0x4000 (@ 0xc)
	DBG_FOG_FAR_GREEN = 114, // 0x2000 (@ 0xc)
	DBG_SSCRN_PROC_BAR = 115, // 0x1000 (@ 0xc)
	DBG_NO_ETC_SET = 116, // 0x800 (@ 0xc)
	DBG_NO_DEATH2 = 117, // 0x400 (@ 0xc)
	DBG_NO_PARASITE = 118, // 0x200 (@ 0xc)
	DBG_ESP_CHK = 119, // 0x100 (@ 0xc)
	DBG_NO_EVENT = 120, // 0x80 (@ 0xc)
	DBG_NO_LASER_LINE = 121, // 0x40 (@ 0xc)
	// 122, // 0x20 (@ 0xc)
	DBG_SHOP_FULL = 123, // 0x10 (@ 0xc)
	DBG_ADA_OMAKE_EV = 124, // 0x8 (@ 0xc)
	DBG_FOG_FAR_COLOR = 125, // 0x4 (@ 0xc)
	DBG_TOOL_EMINFO_DISP = 126, // 0x2 (@ 0xc)
	// 127, // 0x1 (@ 0xc)
};

enum class Flags_STOP
{
	SPF_KEY = 0, // 0x80000000 (@ 0x0)
	SPF_CAMERA = 1, // 0x40000000 (@ 0x0)
	SPF_EM = 2, // 0x20000000 (@ 0x0)
	SPF_PL = 3, // 0x10000000 (@ 0x0)
	SPF_ESP = 4, // 0x8000000 (@ 0x0)
	SPF_OBJ = 5, // 0x4000000 (@ 0x0)
	SPF_CTRL = 6, // 0x2000000 (@ 0x0)
	SPF_LIGHT = 7, // 0x1000000 (@ 0x0)
	SPF_SCE = 8, // 0x800000 (@ 0x0)
	SPF_SCE_AT = 9, // 0x400000 (@ 0x0)
	SPF_CCHG = 10, // 0x200000 (@ 0x0)
	SPF_PL_CCHG = 11, // 0x100000 (@ 0x0)
	SPF_NOTSUBSCR = 12, // 0x80000 (@ 0x0)
	SPF_WATER = 13, // 0x40000 (@ 0x0)
	SPF_SPECULAR = 14, // 0x20000 (@ 0x0)
	SPF_EARTHQUAKE = 15, // 0x10000 (@ 0x0)
	SPF_VIBRATION = 16, // 0x8000 (@ 0x0)
	SPF_CINESCO = 17, // 0x4000 (@ 0x0)
	SPF_MIST = 18, // 0x2000 (@ 0x0)
	SPF_SUBCHAR = 19, // 0x1000 (@ 0x0)
	SPF_SE = 20, // 0x800 (@ 0x0)
	SPF_EVT = 21, // 0x400 (@ 0x0)
	SPF_BLOCK = 22, // 0x200 (@ 0x0)
	SPF_ACTBTN = 23, // 0x100 (@ 0x0)
	SPF_DATAREAD_AT = 24, // 0x80 (@ 0x0)
	SPF_ID_SYSTEM = 25, // 0x40 (@ 0x0)
	SPF_ESP_AREA = 26, // 0x20 (@ 0x0)
};

enum class Flags_STATUS
{
	STA_BG_OFF = 0, // 0x80000000 (@ 0x0)
	STA_PL_CHECK = 1, // 0x40000000 (@ 0x0)
	STA_PL_CHECK2 = 2, // 0x20000000 (@ 0x0)
	STA_MOVIE_ON = 3, // 0x10000000 (@ 0x0)
	STA_CUTCHG = 4, // 0x8000000 (@ 0x0)
	STA_MOVIE2_ON = 5, // 0x4000000 (@ 0x0)
	STA_SSCRN_ENABLE = 6, // 0x2000000 (@ 0x0)
	STA_CINESCO = 7, // 0x1000000 (@ 0x0)
	STA_PL_FIRE = 8, // 0x800000 (@ 0x0)
	STA_09 = 9, // 0x400000 (@ 0x0)
	STA_ACT_DONT_FIRE = 10, // 0x200000 (@ 0x0)
	STA_DIEDEMO = 11, // 0x100000 (@ 0x0)
	STA_BLUR = 12, // 0x80000 (@ 0x0)
	STA_SUB_SCRN = 13, // 0x40000 (@ 0x0)
	STA_SHOOTING = 14, // 0x20000 (@ 0x0)
	STA_PAD_SENSITIVE = 15, // 0x10000 (@ 0x0)
	STA_10 = 16, // 0x8000 (@ 0x0)
	STA_PL_ACTION = 17, // 0x4000 (@ 0x0)
	STA_PL_INVISIBLE = 18, // 0x2000 (@ 0x0)
	STA_EVENT = 19, // 0x1000 (@ 0x0)
	STA_ASHLEY_HIDE = 20, // 0x800 (@ 0x0)
	STA_CAM_SHOULDER = 21, // 0x400 (@ 0x0)
	STA_WATER_ALIVE = 22, // 0x200 (@ 0x0)
	STA_CAMERA = 23, // 0x100 (@ 0x0)
	STA_BLACKOUT = 24, // 0x80 (@ 0x0)
	STA_SCOPE_CAMERA = 25, // 0x40 (@ 0x0)
	STA_RIDE_GONDOLA = 26, // 0x20 (@ 0x0)
	STA_WIND_ON = 27, // 0x10 (@ 0x0)
	STA_PL_JUMP_OFF = 28, // 0x8 (@ 0x0)
	STA_MIRROR = 29, // 0x4 (@ 0x0)
	STA_SAND_ALIVE = 30, // 0x2 (@ 0x0)
	STA_SELF_SHADOW = 31, // 0x1 (@ 0x0)
	STA_PL_SE_FOOT = 32, // 0x80000000 (@ 0x4)
	STA_PL_SE_WHISTLE = 33, // 0x40000000 (@ 0x4)
	STA_SE_BURST = 34, // 0x20000000 (@ 0x4)
	STA_SUSPEND = 35, // 0x10000000 (@ 0x4)
	STA_TEX_RENDER = 36, // 0x8000000 (@ 0x4)
	STA_THERMO_GRAPH = 37, // 0x4000000 (@ 0x4)
	STA_CAMERA_IN_ROOM = 38, // 0x2000000 (@ 0x4)
	STA_NO_LIGHTMASK = 39, // 0x1000000 (@ 0x4)
	STA_PL_SPEAR_SET = 40, // 0x800000 (@ 0x4)
	STA_PL_SWIM = 41, // 0x400000 (@ 0x4)
	STA_PL_BOAT = 42, // 0x200000 (@ 0x4)
	STA_WATER_CAMERA = 43, // 0x100000 (@ 0x4)
	STA_PL_SWIM_CAMERA = 44, // 0x80000 (@ 0x4)
	STA_PL_LADDER = 45, // 0x40000 (@ 0x4)
	STA_CRITICAL = 46, // 0x20000 (@ 0x4)
	STA_TAKEAWAY = 47, // 0x10000 (@ 0x4)
	STA_PL_CATCHED = 48, // 0x8000 (@ 0x4)
	STA_SHADOW_EQCOL = 49, // 0x4000 (@ 0x4)
	STA_PL_CATCHHOLD = 50, // 0x2000 (@ 0x4)
	STA_NEARCLIP_TOUCH = 51, // 0x1000 (@ 0x4)
	STA_CAMERA_SET_ROOM = 52, // 0x800 (@ 0x4)
	STA_ROOM_RAIN = 53, // 0x400 (@ 0x4)
	STA_USE_CAST_SHADOW = 54, // 0x200 (@ 0x4)
	STA_PROC_SHD_TEX = 55, // 0x100 (@ 0x4)
	STA_ALPHA_DRAW2 = 56, // 0x80 (@ 0x4)
	STA_SET_BG_COLOR = 57, // 0x40 (@ 0x4)
	STA_ESPGEN45_SET = 58, // 0x20 (@ 0x4)
	STA_EFFEM2D_TEXRND = 59, // 0x10 (@ 0x4)
	STA_SUB_LADDER = 60, // 0x8 (@ 0x4)
	STA_SUBCHAR_CTRL = 61, // 0x4 (@ 0x4)
	STA_ITEM_GET = 62, // 0x2 (@ 0x4)
	STA_LASERSITE_NOADD = 63, // 0x1 (@ 0x4)
	STA_PL_DONT_FIRE = 64, // 0x80000000 (@ 0x8)
	STA_PL_EM_ACTION = 65, // 0x40000000 (@ 0x8)
	STA_SUB_CATCHED = 66, // 0x20000000 (@ 0x8)
	STA_CUT_CHANGE = 67, // 0x10000000 (@ 0x8)
	STA_NO_FENCE = 68, // 0x8000000 (@ 0x8)
	STA_SSCRN_REQUEST = 69, // 0x4000000 (@ 0x8)
	STA_ESP_COMPULSION_NOSUSPEND = 70, // 0x2000000 (@ 0x8)
	STA_PL_MISS_SHOT = 71, // 0x1000000 (@ 0x8)
	STA_SUB_BULLDOZER = 72, // 0x800000 (@ 0x8)
	STA_LIT_NO_UPDATE = 73, // 0x400000 (@ 0x8)
	STA_MAP_DISABLE = 74, // 0x200000 (@ 0x8)
	STA_USE_SHADOW_LIGHT = 75, // 0x100000 (@ 0x8)
	STA_EVENT_SYSYTEM = 76, // 0x80000 (@ 0x8)
	STA_INTO_SHOP = 77, // 0x40000 (@ 0x8)
	STA_TIMER_NO_PAUSE = 78, // 0x20000 (@ 0x8)
	STA_EFFAREA_USE_CAM = 79, // 0x10000 (@ 0x8)
	STA_TITLE = 80, // 0x8000 (@ 0x8)
	STA_MAP_CK_UNLIMIT = 81, // 0x4000 (@ 0x8)
	STA_RIFLE_READY = 82, // 0x2000 (@ 0x8)
	STA_LOWPOLY_USE = 83, // 0x1000 (@ 0x8)
	STA_TERMINAL = 84, // 0x800 (@ 0x8)
	STA_HIGH_TEMPERATURE_THERMO = 85, // 0x400 (@ 0x8)
	// 86, // 0x200 (@ 0x8)
	// 87, // 0x100 (@ 0x8)
	// 88, // 0x80 (@ 0x8)
	// 89, // 0x40 (@ 0x8)
	// 90, // 0x20 (@ 0x8)
	// 91, // 0x10 (@ 0x8)
	// 92, // 0x8 (@ 0x8)
	// 93, // 0x4 (@ 0x8)
	// 94, // 0x2 (@ 0x8)
	// 95, // 0x1 (@ 0x8)
	STA_SAVEDATA_NO_UPDATE = 96, // 0x80000000 (@ 0xc)
	STA_BEHIND_CAM = 97, // 0x40000000 (@ 0xc)
	STA_62 = 98, // 0x20000000 (@ 0xc)
	STA_SCISSOR = 99, // 0x10000000 (@ 0xc)
	STA_SLOW = 100, // 0x8000000 (@ 0xc)
	STA_SUB_ASHLEY = 101, // 0x4000000 (@ 0xc)
	STA_BIG_MARKER = 102, // 0x2000000 (@ 0xc)
	// 103, // 0x1000000 (@ 0xc)
	STA_KLAUSER_TRANSFORM = 104, // 0x800000 (@ 0xc)
	// 105, // 0x400000 (@ 0xc)
	// 106, // 0x200000 (@ 0xc)
	// 107, // 0x100000 (@ 0xc)
	// 108, // 0x80000 (@ 0xc)
	// 109, // 0x40000 (@ 0xc)
	// 110, // 0x20000 (@ 0xc)
	// 111, // 0x10000 (@ 0xc)
	// 112, // 0x8000 (@ 0xc)
	// 113, // 0x4000 (@ 0xc)
	// 114, // 0x2000 (@ 0xc)
	STA_SCREEN_STOP_RESERVE = 115, // 0x1000 (@ 0xc)
	STA_TYPEWRITER = 116, // 0x800 (@ 0xc)
	// 117, // 0x400 (@ 0xc)
	// 118, // 0x200 (@ 0xc)
	// 119, // 0x100 (@ 0xc)
	// 120, // 0x80 (@ 0xc)
	// 121, // 0x40 (@ 0xc)
	// 122, // 0x20 (@ 0xc)
	// 123, // 0x10 (@ 0xc)
	// 124, // 0x8 (@ 0xc)
	// 125, // 0x4 (@ 0xc)
	// 126, // 0x2 (@ 0xc)
	// 127, // 0x1 (@ 0xc)
};

enum class Flags_SYSTEM
{
	SYS_OMAKE_ADA_GAME = 0, // 0x80000000 (@ 0x0)
	SYS_OMAKE_ETC_GAME = 1, // 0x40000000 (@ 0x0)
	SYS_EXCEPTION = 2, // 0x20000000 (@ 0x0)
	SYS_RENDER_END = 3, // 0x10000000 (@ 0x0)
	SYS_SP_USED = 4, // 0x8000000 (@ 0x0)
	SYS_SOFT_RESET = 5, // 0x4000000 (@ 0x0)
	SYS_DATA_READ = 6, // 0x2000000 (@ 0x0)
	SYS_ROOMJUMP = 7, // 0x1000000 (@ 0x0)
	SYS_INVISIBLE = 8, // 0x800000 (@ 0x0)
	SYS_DOOR_AFTER = 9, // 0x400000 (@ 0x0)
	SYS_DOORDEMO = 10, // 0x200000 (@ 0x0)
	SYS_TRANS_STOP = 11, // 0x100000 (@ 0x0)
	SYS_CONTINUE = 12, // 0x80000 (@ 0x0)
	SYS_SET_BLACK = 13, // 0x40000 (@ 0x0)
	SYS_SN_PC_READ = 14, // 0x20000 (@ 0x0)
	SYS_SN_PC_READ_TOOL = 15, // 0x10000 (@ 0x0)
	SYS_SSCRN_EXEC = 16, // 0x8000 (@ 0x0)
	SYS_SCREEN_SHOT = 17, // 0x4000 (@ 0x0)
	SYS_NEW_GAME = 18, // 0x2000 (@ 0x0)
	SYS_PS2_ADA_GAME = 19, // 0x1000 (@ 0x0)
	SYS_SCISSOR_ON = 20, // 0x800 (@ 0x0)
	SYS_SCREEN_STOP = 21, // 0x400 (@ 0x0)
	SYS_CARD_ACCESS = 22, // 0x200 (@ 0x0)
	SYS_LOAD_GAME = 23, // 0x100 (@ 0x0)
	SYS_CONTINUE_AFTER = 24, // 0x80 (@ 0x0)
	SYS_START_EVT_SKIP = 25, // 0x40 (@ 0x0)
	SYS_HARD_MODE = 26, // 0x20 (@ 0x0)
	SYS_MESSAGE_INIT = 27, // 0x10 (@ 0x0)
	SYS_PUBLICITY_VER = 28, // 0x8 (@ 0x0)
	SYS_SAVEDATA_EXIST = 29, // 0x4 (@ 0x0)
	SYS_PAL = 30, // 0x2 (@ 0x0)
	SYS_DTV480P = 31, // 0x1 (@ 0x0)
};

enum class Flags_ITEM_SET
{
	ITF_DUMMY = 0, // 0x80000000 (@ 0x0)
	// 1, // 0x40000000 (@ 0x0)
	// 2, // 0x20000000 (@ 0x0)
	// 3, // 0x10000000 (@ 0x0)
	// 4, // 0x8000000 (@ 0x0)
	// 5, // 0x4000000 (@ 0x0)
	// 6, // 0x2000000 (@ 0x0)
	// 7, // 0x1000000 (@ 0x0)
	// 8, // 0x800000 (@ 0x0)
	// 9, // 0x400000 (@ 0x0)
	// 10, // 0x200000 (@ 0x0)
	// 11, // 0x100000 (@ 0x0)
	// 12, // 0x80000 (@ 0x0)
	ITF_R101_IDCARD_A = 13, // 0x40000 (@ 0x0)
	ITF_R10D_IDCARD_B = 14, // 0x20000 (@ 0x0)
	ITF_R10B_IDCARD_C = 15, // 0x10000 (@ 0x0)
};

enum class Flags_SCENARIO
{
	SCF_KEY_ID_A_GET = 0, // 0x80000000 (@ 0x0)
	SCF_KEY_ID_B_GET = 1, // 0x40000000 (@ 0x0)
	SCF_KEY_ID_C_GET = 2, // 0x20000000 (@ 0x0)
	SCF_HOOK_STALKING_R10A = 3, // 0x10000000 (@ 0x0)
	SCF_R10E_BATTLE_END = 4, // 0x8000000 (@ 0x0)
	SCF_R104_ACT_STATUE = 5, // 0x4000000 (@ 0x0)
	SCF_R01E_TEST = 6, // 0x2000000 (@ 0x0)
	SCF_R100_TEST00 = 7, // 0x1000000 (@ 0x0)
	SCF_R100_TEST01 = 8, // 0x800000 (@ 0x0)
	SCF_R100_TEST02 = 9, // 0x400000 (@ 0x0)
	SCF_R106_EVENT = 10, // 0x200000 (@ 0x0)
	SCF_R117_ASHLEY_FIND = 11, // 0x100000 (@ 0x0)
	SCF_R100_DOG_RUN = 12, // 0x80000 (@ 0x0)
	SCF_ST1_SUB_MISSION = 13, // 0x40000 (@ 0x0)
	SCF_R11C_BESIEGED_EVENT = 14, // 0x20000 (@ 0x0)
	SCF_R201_EVENT00 = 15, // 0x10000 (@ 0x0)
	SCF_R108_PUZZLE_CLEAR = 16, // 0x8000 (@ 0x0)
	SCF_R100_KILL_GANADE_1ST = 17, // 0x4000 (@ 0x0)
	SCF_R101_ENTER = 18, // 0x2000 (@ 0x0)
	SCF_R103_ENTER = 19, // 0x1000 (@ 0x0)
	SCF_R106_ENTER = 20, // 0x800 (@ 0x0)
	SCF_R106_CONFINEED_WITH_LUIS = 21, // 0x400 (@ 0x0)
	SCF_R108_CHECK_DOOR = 22, // 0x200 (@ 0x0)
	SCF_R10C_GET_CREST = 23, // 0x100 (@ 0x0)
	SCF_NO_ASHLEY_DIST_CK = 24, // 0x80 (@ 0x0)
	SCF_R11C_BESIEGED_END_EVENT = 25, // 0x40 (@ 0x0)
	SCF_R103_MANURE_RECEPTACLE = 26, // 0x20 (@ 0x0)
	SCF_R103_ITEM_IN_MANURE_RECEPTACLE = 27, // 0x10 (@ 0x0)
	SCF_R11B_END_SALAMANDER = 28, // 0x8 (@ 0x0)
	SCF_ST1_MAP_DAY = 29, // 0x4 (@ 0x0)
	SCF_ST1_MAP_NIGHT = 30, // 0x2 (@ 0x0)
	SCF_ST2_MAP = 31, // 0x1 (@ 0x0)
	SCF_ST3_MAP = 32, // 0x80000000 (@ 0x4)
	SCF_R217_PUZZLE_CLEAR = 33, // 0x40000000 (@ 0x4)
	// 34, // 0x20000000 (@ 0x4)
	SCF_R206_ASHLEY_RESCUE = 35, // 0x10000000 (@ 0x4)
	SCF_R101_IMPRISON = 36, // 0x8000000 (@ 0x4)
	SCF_R103_OPEN_COVER = 37, // 0x4000000 (@ 0x4)
	SCF_R20D_END_OF_ASHLEY_PLAY = 38, // 0x2000000 (@ 0x4)
	SCF_ST1_NIGHT = 39, // 0x1000000 (@ 0x4)
	SCF_ST2_IN = 40, // 0x800000 (@ 0x4)
	SCF_STOCK_ST1_DAY = 41, // 0x400000 (@ 0x4)
	SCF_STOCK_ST1_NIGHT = 42, // 0x200000 (@ 0x4)
	SCF_STOCK_ST2 = 43, // 0x100000 (@ 0x4)
	SCF_R108_OPERATOR = 44, // 0x80000 (@ 0x4)
	SCF_R204_ASHLEY_SPLIT = 45, // 0x40000 (@ 0x4)
	SCF_R11C_OPERATOR = 46, // 0x20000 (@ 0x4)
	SCF_ST3_IN = 47, // 0x10000 (@ 0x4)
	SCF_R119_DOOR_CLOSE = 48, // 0x8000 (@ 0x4)
	SCF_R10C_TO_R10E = 49, // 0x4000 (@ 0x4)
	SCF_ST1_NIGHT_LV_ADD = 50, // 0x2000 (@ 0x4)
	SCF_R307_REGENERATER_APPEAR = 51, // 0x1000 (@ 0x4)
	SCF_R316_TO_R30A_CUTBACK_EVENT = 52, // 0x800 (@ 0x4)
	SCF_R30D_ENTER = 53, // 0x400 (@ 0x4)
	// 54, // 0x200 (@ 0x4)
	// 55, // 0x100 (@ 0x4)
	// 56, // 0x80 (@ 0x4)
	// 57, // 0x40 (@ 0x4)
	SCF_R317_LEON_WOUND = 58, // 0x20 (@ 0x4)
	// 59, // 0x10 (@ 0x4)
	SCF_R22C_BONUS_1 = 60, // 0x8 (@ 0x4)
	SCF_R22C_BONUS_2 = 61, // 0x4 (@ 0x4)
	SCF_R22C_BONUS_3 = 62, // 0x2 (@ 0x4)
	SCF_R22C_BONUS_4 = 63, // 0x1 (@ 0x4)
};

enum class Flags_KEY_LOCK
{
	// 0, // 0x80000000 (@ 0x0)
};

enum class Flags_ROOM
{
};

enum class Flags_ROOM_SAVE
{
};

enum class Flags_EXTRA
{
	CFG_AIM_REVERSE = 0, // 0x80000000 (@ 0x0)
	CFG_WIDE_MODE = 1, // 0x40000000 (@ 0x0)
	CFG_LOCK_ON = 2, // 0x20000000 (@ 0x0)
	CFG_BONUS_GET = 3, // 0x10000000 (@ 0x0)
	CFG_VIBRATION = 4, // 0x8000000 (@ 0x0)
	CFG_KNIFE_MODE = 5, // 0x4000000 (@ 0x0)
	EXT_COSTUME = 6, // 0x2000000 (@ 0x0)
	EXT_HARD_MODE = 7, // 0x1000000 (@ 0x0)
	EXT_GET_SW500 = 8, // 0x800000 (@ 0x0)
	EXT_GET_TOMPSON = 9, // 0x400000 (@ 0x0)
	EXT_GET_ADA = 10, // 0x200000 (@ 0x0)
	EXT_GET_HUNK = 11, // 0x100000 (@ 0x0)
	EXT_GET_KLAUSER = 12, // 0x80000 (@ 0x0)
	EXT_GET_WESKER = 13, // 0x40000 (@ 0x0)
	EXT_GET_OMAKE_ADA_GAME = 14, // 0x20000 (@ 0x0)
	EXT_GET_OMAKE_ETC_GAME = 15, // 0x10000 (@ 0x0)
};

enum class Flags_CONFIG
{
	CFG_AIM_REVERSE = 0, // 0x80000000 (@ 0x0)
	CFG_WIDE_MODE = 1, // 0x40000000 (@ 0x0)
	CFG_LOCK_ON = 2, // 0x20000000 (@ 0x0)
	CFG_BONUS_GET = 3, // 0x10000000 (@ 0x0)
	CFG_VIBRATION = 4, // 0x8000000 (@ 0x0)
	CFG_KNIFE_MODE = 5, // 0x4000000 (@ 0x0)
};

enum class Flags_DISP
{
	DPF_EM = 0, // 0x80000000 (@ 0x0)
	DPF_PL = 1, // 0x40000000 (@ 0x0)
	DPF_SUBCHAR = 2, // 0x20000000 (@ 0x0)
	DPF_OBJ = 3, // 0x10000000 (@ 0x0)
	DPF_SCR = 4, // 0x8000000 (@ 0x0)
	DPF_ESP = 5, // 0x4000000 (@ 0x0)
	DPF_SHADOW = 6, // 0x2000000 (@ 0x0)
	DPF_WATER = 7, // 0x1000000 (@ 0x0)
	DPF_MIRROR = 8, // 0x800000 (@ 0x0)
	DPF_CTRL = 9, // 0x400000 (@ 0x0)
	DPF_CINESCO = 10, // 0x200000 (@ 0x0)
	DPF_FILTER = 11, // 0x100000 (@ 0x0)
	DPF_GLB_ILM = 12, // 0x80000 (@ 0x0)
	DPF_CAST_SHADOW = 13, // 0x40000 (@ 0x0)
	DPF_CLOTH = 14, // 0x20000 (@ 0x0)
	DPF_COCKPIT = 15, // 0x10000 (@ 0x0)
	DPF_SELF_SHADOW = 16, // 0x8000 (@ 0x0)
	DPF_FOG = 17, // 0x4000 (@ 0x0)
	DPF_ID_SYSTEM = 18, // 0x2000 (@ 0x0)
	DPF_ACTBTN = 19, // 0x1000 (@ 0x0)
	DPF_MESSAGE = 20, // 0x800 (@ 0x0)
	DPF_TEX_RENDER = 21, // 0x400 (@ 0x0)
	DPF_EFFECT_VU1 = 22, // 0x200 (@ 0x0)
};

struct FlagCategoryInfo
{
	const char* CategoryName;
	uint32_t* FlagValues;
	uint16_t Length;
	uint16_t UnkA;
	char** FlagNames;
	uint32_t NumFlagNames;
};

#define NUM_FLAG_CATEGORIES 12

// flag algo from NieR Automata, seems to work exactly the same as RE4's flag system
constexpr uint32_t GetFlagValue(uint32_t flagIndex, uint32_t& offset)
{
	offset = (flagIndex / 32) * 4;
	return 0x80000000 >> (flagIndex & 31);
}

// Only use this on flags with less than 32 values
constexpr uint32_t GetFlagValue(uint32_t flagIndex)
{
	return 0x80000000 >> (flagIndex & 31);
}

inline bool FlagIsSet(uint32_t* flagValues, uint32_t flagIndex)
{
	return flagValues[(flagIndex / 32)] & (0x80000000 >> (flagIndex & 31));
}

inline void FlagSet(uint32_t* flagValues, uint32_t flagIndex, bool state)
{
	uint32_t flag = (0x80000000 >> (flagIndex & 31));
	if (state)
		flagValues[(flagIndex / 32)] |= flag;
	else
		flagValues[(flagIndex / 32)] &= ~flag;
}
