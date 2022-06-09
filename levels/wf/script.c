#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/wf/header.h"

// Unlike most levels, some of the level geometry objects in WF are defined as regular objects instead of terrain objects.
// Some of them are still terrain objects, however.
static const LevelScript script_func_local_1[] = {
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/  2305, 2432,  -255, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_04, /*pos*/  3405, 1664, -1791, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_05, /*pos*/  3840,    0, -2303, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_05, /*pos*/  3840,    0, -1279, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_06, /*pos*/     0,    0,     0, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_07, /*pos*/     0, 3450, -2800, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0A, /*pos*/  3840,  794,  2688, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0C, /*pos*/  1408, 2522,  2431, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_WF_GIANT_POLE,     /*pos*/ -1500, 2560,  2512, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGiantPole),
    OBJECT(/*model*/ MODEL_WF_GIANT_POLE,     /*pos*/  1128, 2560, -1024, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGiantPole),
    RETURN(),
};

static const LevelScript script_func_local_2[] = {
    OBJECT(/*model*/ MODEL_WF_SMALL_BOMP,               /*pos*/  3300, 1070,     1, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSmallBomp),
    OBJECT(/*model*/ MODEL_WF_SMALL_BOMP,               /*pos*/  3300, 1070,  1281, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSmallBomp),
    OBJECT(/*model*/ MODEL_WF_LARGE_BOMP,               /*pos*/  3300, 1070,   641, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvLargeBomp),
    OBJECT(/*model*/ MODEL_WF_ROTATING_WOODEN_PLATFORM, /*pos*/  -255, 2560,  2304, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvWfRotatingWoodenPlatform),
    OBJECT(/*model*/ MODEL_WF_SLIDING_PLATFORM,         /*pos*/  3328, 1075, -1791, /*angle*/ 0,  90, 0, /*behParam*/ 0x00020000, /*beh*/ bhvWfSlidingPlatform),
    OBJECT(/*model*/ MODEL_WF_SLIDING_PLATFORM,         /*pos*/  3328, 1075,  -767, /*angle*/ 0,  90, 0, /*behParam*/ 0x00010000, /*beh*/ bhvWfSlidingPlatform),
    OBJECT(/*model*/ MODEL_WF_SLIDING_PLATFORM,         /*pos*/  3328, 1075, -2815, /*angle*/ 0,  90, 0, /*behParam*/ 0x00030000, /*beh*/ bhvWfSlidingPlatform),
    OBJECT(/*model*/ MODEL_WF_TUMBLING_BRIDGE,          /*pos*/  1792, 2496,  1600, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvWfTumblingBridge),
    OBJECT(/*model*/ MODEL_NONE,                        /*pos*/ -2495, 1331,  -256, /*angle*/ 0,   0, 0, /*behParam*/ 0x003D0000, /*beh*/ bhvPoleGrabbing),
    RETURN(),
};

static const LevelScript script_func_local_3[] = {
    OBJECT(/*model*/ MODEL_THWOMP,            /*pos*/  3462, 1939, -1545, /*angle*/ 0,  180, 0, /*behParam*/ 0x00000000, /*beh*/ bhvThwomp),
    OBJECT(/*model*/ MODEL_THWOMP,            /*pos*/  3462, 1075, -3314, /*angle*/ 0,   90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvThwomp2),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/  -856,  922,  3819, /*angle*/ 0,    0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvBetaFishSplashSpawner),
    OBJECT(/*model*/ MODEL_PIRANHA_PLANT,     /*pos*/  1822, 2560,  -101, /*angle*/ 0,   90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvPiranhaPlant),
    OBJECT(/*model*/ MODEL_WHOMP,             /*pos*/ -2045, 2560,  -286, /*angle*/ 0,    0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSmallWhomp),
    OBJECT(/*model*/ MODEL_BULLET_BILL,       /*pos*/  1280, 3712,   968, /*angle*/ 0,  180, 0, /*behParam*/ 0x00000000, /*beh*/ bhvBulletBill),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_08, /*pos*/     0, 3584,     0, /*angle*/ 0,    0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvTower),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_09, /*pos*/  1280, 3584,   896, /*angle*/ 0,    0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvBulletBillCannon),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/     0, 3483,     0, /*angle*/ 0,    0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvTowerPlatformGroup),
    OBJECT(/*model*/ MODEL_HOOT,              /*pos*/  2560,  700,  4608, /*angle*/ 0,    0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHoot),
    RETURN(),
};

static const LevelScript script_func_local_4[] = {
    OBJECT(/*model*/ MODEL_STAR,  /*pos*/   300,  5550,     0, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStar),
    OBJECT(/*model*/ MODEL_STAR,  /*pos*/     0,  3750, -2800, /*angle*/ 0, 0, 0, /*behParam*/ 0x01000000, /*beh*/ bhvStar),
    RETURN(),
};

const LevelScript level_wf_entry[] = {
    INIT_LEVEL(),
    LOAD_RAW(         /*seg*/ 0x07, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd),
    LOAD_MIO0(        /*seg*/ 0x0A, _cloud_floor_skybox_mio0SegmentRomStart, _cloud_floor_skybox_mio0SegmentRomEnd),
    LOAD_MIO0_TEXTURE(/*seg*/ 0x09, _grass_mio0SegmentRomStart, _grass_mio0SegmentRomEnd),
    LOAD_RAW(         /*seg*/ 0x05, _group1_mio0SegmentRomStart, _group1_mio0SegmentRomEnd),
    LOAD_RAW(         /*seg*/ 0x0C, _group1_geoSegmentRomStart,  _group1_geoSegmentRomEnd),
    LOAD_RAW(         /*seg*/ 0x06, _group14_mio0SegmentRomStart, _group14_mio0SegmentRomEnd),
    LOAD_RAW(         /*seg*/ 0x0D, _group14_geoSegmentRomStart,  _group14_geoSegmentRomEnd),
    LOAD_RAW(         /*seg*/ 0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
    LOAD_RAW(         /*seg*/ 0x0F, _common0_geoSegmentRomStart,  _common0_geoSegmentRomEnd),
    ALLOC_LEVEL_POOL(),
    MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
    JUMP_LINK(script_func_global_1),
    JUMP_LINK(script_func_global_2),
    JUMP_LINK(script_func_global_15),
    LOAD_MODEL_FROM_GEO(MODEL_WF_BUBBLY_TREE,                   bubbly_tree_geo),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03,                wf_geo_5),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04,                wf_geo_6),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05,                wf_geo_7),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06,                wf_geo_8),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07,                wf_geo_9),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08,                wf_geo_10),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09,                wf_geo_0008E8),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A,                wf_geo_12),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C,                wf_geo_13),
    LOAD_MODEL_FROM_GEO(MODEL_WF_GIANT_POLE,                    wf_geo_000AE0),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E,                wf_geo_15),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F,                wf_geo_16),
    LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_PLATFORM,             wf_geo_0009B8),
    LOAD_MODEL_FROM_GEO(MODEL_WF_SMALL_BOMP,                    wf_geo_000A00),
    LOAD_MODEL_FROM_GEO(MODEL_WF_LARGE_BOMP,                    wf_geo_000A40),
    LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_WOODEN_PLATFORM,      wf_geo_000A58),
    LOAD_MODEL_FROM_GEO(MODEL_WF_SLIDING_PLATFORM,              wf_geo_000A98),
    LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE_PART,          wf_geo_000AB0),
    LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE,               wf_geo_000AC8),
    LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_TRAPEZOID_PLATORM,       wf_geo_000AF8),
    LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM,          wf_geo_000B10),
    LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM_UNUSED,   wf_geo_000AF8),
    LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM_ELEVATOR, wf_geo_000B60),

    AREA(/*index*/ 1, mountain_geo),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/  2600, 1256,  5120, /*angle*/ 0, 90, 0, /*behParam*/ 0x000A0000, /*beh*/ bhvWarps74),
        WARP_NODE(/*id*/ 0x0A, /*destLevel*/ LEVEL_WF, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x0B, /*destLevel*/ LEVEL_WF, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x0C, /*destLevel*/ LEVEL_WF, /*destArea*/ 0x01, /*destNode*/ 0x0B, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF0, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x01, /*destNode*/ 0x33, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF1, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x01, /*destNode*/ 0x65, /*flags*/ WARP_NO_CHECKPOINT),
        JUMP_LINK(script_func_local_1),
        JUMP_LINK(script_func_local_2),
        JUMP_LINK(script_func_local_3),
        JUMP_LINK(script_func_local_4),
        TERRAIN(/*terrainData*/ mountain_collision),
        MACRO_OBJECTS(/*objList*/ mountain_macro),
        SHOW_DIALOG(/*index*/ 0x00, DIALOG_030),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0000, /*seq*/ SEQ_LEVEL_GRASS),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_STONE),
    END_AREA(),

    FREE_LEVEL_POOL(),
    MARIO_POS(/*area*/ 1, /*yaw*/ 90, /*pos*/ 2600, 256, 5120),
    CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
    CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    EXIT(),
};
