//
//  BulletCache.cpp
//  mJoy
//
//  Created by Jerry Yang on 7/23/13.
//
//

#include "BulletCache.h"

using namespace cocos2d;

BulletCache::BulletCache(void)
{
    CCLOG("BulletCache __construct");

    this->windowSize = CCDirector::sharedDirector()->getWinSize();
    this->initBatch();
}

BulletCache::~BulletCache()
{
    CCLOG("BulletCache __destruct");
}

void BulletCache::initBatch()
{
    this->BulletBatch = CCArray::createWithCapacity(BULLET_CACHE_NUMBER);
    this->BulletBatch->retain();

    for (int i = 0; i < BULLET_CACHE_NUMBER; i++)
    {
        CCString *originalFrameName = CCString::createWithFormat("bullet01.png");
        CCSprite *bullet = CCSprite::createWithSpriteFrameName(originalFrameName->getCString());

        bullet->setVisible(true);
        CCPoint pos = ccp(rand() % (int)this->windowSize.width, rand() % (int)this->windowSize.height);
        bullet->setPosition(pos);

        this->BulletBatch->addObject(bullet);
        this->addChild(bullet);
    }
}