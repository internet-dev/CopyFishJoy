//
//  CannonCache.cpp
//  mJoy
//
//  Created by Jerry Yang on 7/22/13.
//
//

#include "CannonCache.h"

using namespace cocos2d;

CannonCache::CannonCache(void)
{
    CCLOG("CannonCache __construct");

    this->windowSize = CCDirector::sharedDirector()->getWinSize();
    this->initBatch();
}

CannonCache::~CannonCache(void)
{
    CCLOG("CannonCache __destruct");
}

void CannonCache::initBatch(void)
{
    this->level = CANNON_LEVEL_TOTAL;

    this->CannonBatch = CCArray::createWithCapacity(CANNON_LEVEL_TOTAL);
    this->CannonBatch->retain();

    for (int i = 1; i <= CANNON_LEVEL_TOTAL; i++)
    {
        CCString *originalFrameName = CCString::createWithFormat("actor_cannon1_%d1.png", i);
        CCSprite *cannon = CCSprite::createWithSpriteFrameName(originalFrameName->getCString());

        cannon->setVisible(CANNON_LEVEL_TOTAL == i ? true : false);
        CCPoint pos = ccp(CANNON_X , CANNON_Y);
        cannon->setPosition(pos);

        this->CannonBatch->addObject(cannon);
        this->addChild(cannon);
    }
}

void CannonCache::touchFollow(CannonCache *cannon_cache, CCPoint touch_pos)
{
    assert(NULL != cannon_cache);

    if (cannon_cache->level < 1 || cannon_cache->level > CANNON_LEVEL_TOTAL)
    {
        cannon_cache->level = CANNON_LEVEL_TOTAL;
    }

    float angle = atan2f(touch_pos.y - CANNON_Y, touch_pos.x - CANNON_X) / M_PI * 180.0f;
    if (! (angle > 15.0f && angle < 165.0f))
    {
        return;
    }
    CCLOG("touch_pos: {x: %f, y: %f}, level: %d angle: %f", touch_pos.x, touch_pos.y, cannon_cache->level, angle);
    CCArray *cannon_array = (CCArray *)cannon_cache->CannonBatch;
    /** 数组下标从 0 开始 */
    CCSprite *cannon = (CCSprite *)cannon_array->objectAtIndex(cannon_cache->level - 1);
    cannon->setRotation(90.0f - angle);
}
