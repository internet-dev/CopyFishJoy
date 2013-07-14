//
//  Fish.cpp
//  mJoy
//
//  Created by Jerry Yang on 7/9/13.
//
//

#include "Fish.h"

/**
    鱼的配置
 */
fish_conf_t fish_conf[FISH_GROUP_COUNT];

/**
    鱼的贝赛尔路径
    TODO
 */
/** 鱼路径配置 */
const bezier_t g_path_config[PATH_CONF_TOTAL] = {
    /** 0 左到右(偏上) */
    {ccp(-200, 100), ccp(240, 320), ccp(560, 240), 150, 190},
    /** 1 左到右(偏下) */
    {ccp(-200, -100), ccp(240, 320), ccp(560, 120), 125, 200},
    /** 2 左下到右下 */
    {ccp(-100, -50), ccp(240, 320), ccp(560, -100), 110, 240},
    /** 3 左上到右上 */
    {ccp(-100, 330), ccp(-20, -100), ccp(550, 380), 270, 130},
    /** 4 左下到右上 */
    {ccp(50, -100), ccp(30, 350), ccp(500, 350), 78, 180},
    /** 5 右到左(偏上)*/
    {ccp(600, 100), ccp(300, 100), ccp(-100, 300), -20, 40},
    /** 6 右到左 */
    {ccp(550, 300), ccp(300, -50), ccp(-150, 160), -60, 25},
    /** 7 右到左偏下 */
    {ccp(600, 240), ccp(-20, 350), ccp(-150, -100), 10, -30},
    /** 8 右下到左上 */
    {ccp(500, -100), ccp(450, 350), ccp(-100, 350), 70, 20},
    /** 9 上到下偏左 */
    {ccp(400, 400), ccp(150, 420), ccp(100, -100), -20, -80},
    /** 10 上到下偏右 */
    {ccp(300, 400), ccp(600, 100), ccp(50, -100), -130, -35},
    /** 11 上到下偏右 */
    {ccp(50, 400), ccp(600, 150), ccp(250, -100), -160, -60},
    /** 12 上到下偏左 */
    {ccp(300, 550), ccp(-100, 100), ccp(100, -100), -50, -105},
    /** 13 下到上 */
    {ccp(25, -100), ccp(350, 200), ccp(100, 400), 150, 60},
    /** 14 下到上 */
    {ccp(200, -100), ccp(-200, 240), ccp(350, 400), 10, 160},
    /** 15 下到上 */
    {ccp(400, -100), ccp(500, 200), ccp(200, 400), 120, 40},
    /** 16 下到上 */
    {ccp(450, -100), ccp(-100, 200), ccp(260, 400), 0, 110},
};

using namespace cocos2d;

Fish::Fish(void)
{
    CCLOG("create fish -> Fish::Fish(void)");
}

Fish::~Fish(void)
{
    CCLog("release fish Fish::~Fish(void)");
}

/** 静态方法,主场景中初始化 */
void Fish::initFishConf(void)
{
    /** 炮灰 */
    fish_conf[FISH_GROUP_SMALL].value     = 1;  /** 只值一个金币 */
    fish_conf[FISH_GROUP_SMALL].speed     = 3.5f;
    fish_conf[FISH_GROUP_SMALL].show_rate = 82.6f;
    fish_conf[FISH_GROUP_SMALL].hit_rate  = 27.1f;

    fish_conf[FISH_GROUP_NORMAL].value     = 5;
    fish_conf[FISH_GROUP_NORMAL].speed     = 5.1f;
    fish_conf[FISH_GROUP_NORMAL].show_rate = 61.7f;
    fish_conf[FISH_GROUP_NORMAL].hit_rate  = 13.3f;

    fish_conf[FISH_GROUP_MERMAID].value     = 50;
    fish_conf[FISH_GROUP_MERMAID].speed     = 9.1f;
    fish_conf[FISH_GROUP_MERMAID].show_rate = 31.7f;
    fish_conf[FISH_GROUP_MERMAID].hit_rate  = 11.1f;

    fish_conf[FISH_GROUP_WHALE].value     = 100;
    fish_conf[FISH_GROUP_WHALE].speed     = 17.1f;
    fish_conf[FISH_GROUP_WHALE].show_rate = 11.7f;
    fish_conf[FISH_GROUP_WHALE].hit_rate  = 7.7f;
}

void Fish::spawnOneFish(Fish *fish)
{
    assert(NULL != fish);

    fish->fish_sprite->setVisible(true);
}
