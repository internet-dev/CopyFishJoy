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
 全局场景中显示的鱼的个数
 */
int g_fish_current_total = 0;

/**
    鱼的贝赛尔路径
    TODO
 */
/** 鱼路径配置 */
const bezier_t g_path_config[PATH_CONF_TOTAL] = {
    /** 0 左到右(偏上) */
    {ccp(-200, 100), ccp(560, 380), ccp(1152, 460), 150, 190},
    /** 1 左到右(偏下) */
    {ccp(-200, -100), ccp(340, 620), ccp(1152, 120), 125, 200},
    /** 2 左下到右下 */
    {ccp(-100, -50), ccp(540, 720), ccp(1088, -128), 110, 240},
    /** 3 左上到右上 */
    {ccp(-162, 500), ccp(10, 26), ccp(1088, 680), 220, 150},
    /** 4 左下到右上 */
    {ccp(50, -100), ccp(50, 370), ccp(1024, 652), 78, 175},
    /** 5 右到左(偏上)*/
    {ccp(1152, 560), ccp(512, 64), ccp(-100, 510), -45, 32},
    /** 6 右到左 */
    {ccp(1152, 384), ccp(300, -50), ccp(-150, 160), -45, 25},
    /** 7 右到左偏下 */
    {ccp(1152, 660), ccp(628, 50), ccp(-150, 128), -32, -5},
    /** 8 右下到左上 */
    {ccp(1152, -32), ccp(614, 384), ccp(-100, 614), 45, 20},
    /** 9 上到下偏左 */
    {ccp(640, 896), ccp(150, 420), ccp(128, -128), -37, -80},
    /** 10 上到下偏右 */
    {ccp(300, 896), ccp(600, 100), ccp(50, -128), -130, -35},
    /** 11 上到下偏右 */
    {ccp(896, 896), ccp(600, 150), ccp(890, -128), -60, -105},
    /** 12 上到下偏左 */
    {ccp(1008, 896), ccp(-100, 100), ccp(100, -128), -35, -65},
    /** 13 下到上 */
    {ccp(25, -128), ccp(350, 400), ccp(952, 896), 93, 142},
    /** 14 下到上 */
    {ccp(64, -128), ccp(-78, 386), ccp(1152, 737), 90, 172},
    /** 15 下到上 */
    {ccp(931, -128), ccp(870, 660), ccp(-128, 522), 90, 0},
    /** 16 下到上 */
    {ccp(64, -128), ccp(16, 675), ccp(1152, 660), 90, 180},
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
    fish_conf[FISH_GROUP_SMALL].speed     = 13.5f;
    fish_conf[FISH_GROUP_SMALL].show_rate = 40.0f;
    fish_conf[FISH_GROUP_SMALL].hit_rate  = 27.1f;

    fish_conf[FISH_GROUP_NORMAL].value     = 5;
    fish_conf[FISH_GROUP_NORMAL].speed     = 11.1f;
    fish_conf[FISH_GROUP_NORMAL].show_rate = 30.0f;
    fish_conf[FISH_GROUP_NORMAL].hit_rate  = 13.3f;

    fish_conf[FISH_GROUP_MERMAID].value     = 50;
    fish_conf[FISH_GROUP_MERMAID].speed     = 15.5f;
    fish_conf[FISH_GROUP_MERMAID].show_rate = 20.0f;
    fish_conf[FISH_GROUP_MERMAID].hit_rate  = 11.1f;

    fish_conf[FISH_GROUP_WHALE].value     = 100;
    fish_conf[FISH_GROUP_WHALE].speed     = 19.9f;
    fish_conf[FISH_GROUP_WHALE].show_rate = 10.0f;
    fish_conf[FISH_GROUP_WHALE].hit_rate  = 7.7f;
}

void Fish::spawnOneFish(Fish *fish)
{
    assert(NULL != fish);

    fish->fish_sprite->stopAllActions();
    fish->fish_sprite->setVisible(true);

    /** 游动 */
    CCArray *fish_frames = CCArray::create();
    for(int i = 1; i <= FISH_FRAMES_NUMBER; i++)
    {
        CCString *frame_name = CCString::createWithFormat("fish%02d_%02d.png", fish->fish_id, i);
        CCSpriteFrame *pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frame_name->getCString());
        if(pFrame)
        {
            fish_frames->addObject(pFrame);
        }
    }
    CCAnimation *animation = CCAnimation::createWithSpriteFrames(fish_frames, 0.2f);
    animation->setRestoreOriginalFrame(false);
    CCAnimate *animate = CCAnimate::create(animation);
    CCAction *swing = CCRepeatForever::create(animate);
    fish->fish_sprite->runAction(swing);

    /** 路径 */
    int index = rand() % PATH_CONF_TOTAL;
    // debug path
    //index = 16;
    CCPoint start_pos   = g_path_config[index].start_pos;
    CCPoint control_pos = g_path_config[index].control_pos;
    CCPoint end_pos     = g_path_config[index].end_pos;
    float start_angle = g_path_config[index].start_angle - SPRITE_OFFSET;
    float end_angle   = g_path_config[index].end_angle - SPRITE_OFFSET;
    float time = fish_conf[fish->group_id].speed + rand() % 10;

    int x_offset = rand() % 100 -50;
    int y_offset = rand() % 100 -50;

    CCPoint s_pos = ccp(start_pos.x + x_offset, start_pos.y + y_offset);
    CCPoint e_pos = ccp(end_pos.x + rand() % 50 - 25, end_pos.y + rand() % 50 - 25);
    CCPoint c_pos = ccp(control_pos.x + x_offset, control_pos.y + y_offset);

    fish->fish_sprite->setPosition(s_pos);
    fish->fish_sprite->setRotation(start_angle);

    ccBezierConfig bezier;
    bezier.controlPoint_1 = s_pos;
    bezier.controlPoint_2 = c_pos;
    bezier.endPosition    = e_pos;

    CCBezierTo *actionMove   = CCBezierTo::create(time, bezier);
    CCRotateTo *actionRotate = CCRotateTo::create(time, end_angle);
    CCActionInterval *action = CCSpawn::create(actionMove, actionRotate, NULL);
    /** 完成预订动作将自己设置为不可见 */
    CCFiniteTimeAction *callFunc = CCCallFuncN::create(fish, callfuncN_selector(Fish::hideSelf));
    CCSequence  *actionSequence = CCSequence::create(action, callFunc, NULL);
    fish->fish_sprite->runAction(actionSequence);
}

void Fish::hideSelf(CCNode *sender)
{
    CCSprite *fish_sprite = (Fish *)sender;
    fish_sprite->setVisible(false);
    g_fish_current_total--;
}




