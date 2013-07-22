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
        CCPoint pos = ccp(530.0f , 48.0f);
        cannon->setPosition(pos);

        this->CannonBatch->addObject(cannon);
        this->addChild(cannon);
    }
}

void CannonCache::touchFollow(CannonCache *cannon_cache, CCPoint touch_pos)
{
    assert(NULL != cannon_cache);
    CCLOG("touch_pos: {x: %f, y: %f}", touch_pos.x, touch_pos.y);
}
