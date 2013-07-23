//
//  GameConfig.h
//  mJoy
//
//  Created by Jerry Yang on 7/23/13.
//
//

#ifndef __GameConfig_H__
#define __GameConfig_H__

/** __GAME_SCENE_H__ */
#define OP_LAYER_TAG    111
#define UI_LAYER_TAG    100
#define GAME_LAYER_TAG  10

typedef enum
{
    GameSceneNodeTagFish = 1,
    GameSceneNodeTagCannon,
    GameSceneNodeTagNet,
    GameSceneNodeTagCoin,
} GameSceneNodeTags;

typedef enum
{
    SourceNodeTagFish01 = 111,
    SourceNodeTagFish02,
    SourceNodeTagFish03,
    SourceNodeTagFish04,
    SourceNodeTagCannon,
} SourceNodeTags;

/** __Fish__ */
#define SPRITE_OFFSET       0
#define PATH_CONF_TOTAL     17
#define FISH_FRAMES_NUMBER  10

/** __FishCache__ */
#define STR_BUF_LEN         1024
/** 场景中可显示的鱼的最大数目 */
#define FISH_TOTAL          30
#define SPAWN_RETRY_NUM     3
/** 定义cache 数目 */
/** 炮灰 */
#define FISH_SMALL_CACHE    10
/** 普通鱼类 */
#define FISH_NORMAL_CACHE   4
/** 美人鱼 */
#define FISH_MERMAID_CACHE  3
/** 鲸鱼 */
#define FISH_WHALE_CACHE    2

/** __CannonCache__ */
/**
 炮的等级 1 - 7
 对应的图片记数从 1 开始
 数组记数从 0 开始,切记
 */
#define CANNON_LEVEL_TOTAL  7
#define CANNON_X            530.0f
#define CANNON_Y            48.0f

#endif
