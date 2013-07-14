//
//  Fish.h
//
//  Created by Jerry Yang on 7/9/13.
//
//

#ifndef __Fish__
#define __Fish__

#include "cocos2d.h"

#define SPRITE_OFFSET       0
#define PATH_CONF_TOTAL     17
#define FISH_FRAMES_NUMBER  10

/**
 查看资源后,发现总共有 18 种不同类型的鱼类
 可以分为 4 个级别的鱼,同级别的属性值一样
 */
typedef enum{
    FISH_GROUP_SMALL = 0,   /** 炮灰 */
    FISH_GROUP_NORMAL,
    FISH_GROUP_MERMAID,     /** 美人鱼 */
    FISH_GROUP_WHALE,       /** 鲸鱼 */

    FISH_GROUP_COUNT,       /** 组数目 */
} FISH_GROUP_CONF;

typedef struct _fish_conf_t
{
    int value;  /** 价值 */

    float speed;        /** 游动的速度,实际是时间,越长刚游动的越慢 */
    float show_rate;    /** 出现在场景中的概率 */
    float hit_rate;     /** 命中率 */
} fish_conf_t;

/** 贝赛尔配置 */
typedef struct _bezier_t
{
    cocos2d::CCPoint start_pos;
    cocos2d::CCPoint control_pos;
    cocos2d::CCPoint end_pos;
    float start_angle;
    float end_angle;
} bezier_t;

extern fish_conf_t fish_conf[FISH_GROUP_COUNT];

/** 类定义 */
class GameScene;
class Fish : public cocos2d::CCSprite
{
public:
    Fish(void);
    ~Fish(void);

    /** 静态初始鱼配置 */
    static void initFishConf(void);

    static void spawnOneFish(Fish *fish);

    //CC_SYNTHESIZE(GameScene *, m_pgameScene, gameScene);
    /** 成员属性 */
    int group_id;   /** 所在分组,具有同样的属性 */
    int fish_id;    /** 在资源中的编号 */
    cocos2d::CCSprite *fish_sprite;
};

#endif /* defined(__Fish__) */
