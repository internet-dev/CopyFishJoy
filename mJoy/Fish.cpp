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
static fish_conf_t fish_conf[FISH_GROUP_COUNT];

using namespace cocos2d;
Fish::Fish(void)
{
    CCLOG("create fish -> Fish::Fish(void)");
}


Fish::~Fish(void)
{
	CCLog("release fish Fish::~Fish(void)");
}

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
