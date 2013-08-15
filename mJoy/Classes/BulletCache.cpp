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

        bullet->setVisible(false);
        //CCPoint pos = ccp(rand() % (int)this->windowSize.width, rand() % (int)this->windowSize.height);
        //bullet->setPosition(pos);

        this->BulletBatch->addObject(bullet);
        this->addChild(bullet);
    }
}


void BulletCache::shootBullet(BulletCache *bullet_cache, cocos2d::CCPoint touch_pos, int level)
{
    assert(NULL != bullet_cache);
    assert(level > 0 && level <= CANNON_LEVEL_TOTAL);

    float angle = atan2f(touch_pos.y - CANNON_Y, touch_pos.x - CANNON_X) / M_PI * 180.0f;
    if (! (angle > 15.0f && angle < 165.0f))
    {
        return;
    }

    CCPoint start_pos =ccp(CANNON_X, CANNON_Y);
    CCArray *bullet_array = (CCArray *)bullet_cache->BulletBatch;
    int count = bullet_array->count();
    //CCLOG("bullet_array->count() = %d", count);
    for (int index = 0; index < count; index++)
    {
        CCSprite *bullet = (CCSprite *)bullet_array->objectAtIndex(index);
        if (bullet->isVisible())
        {
            continue;
        }

        bullet->stopAllActions();
        bullet->setRotation(90.0f - angle);
        bullet->setPosition(start_pos);
        bullet->setVisible(true);

        CCString *frameName = CCString::createWithFormat("bullet0%d.png", level);
        CCSpriteFrame *frame= CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName->getCString());
        if (frame)
        {
            bullet->setDisplayFrame(frame);
        }

        CCMoveTo *moveto = CCMoveTo::create(1.0f, touch_pos);
        // 匀速
        // CCSpeed* pSpeed= CCSpeed::create(pActionInterval, 1.5f); //1.5倍速运行
        CCFiniteTimeAction *callFunc = CCCallFuncN::create(bullet, callfuncN_selector(BulletCache::hideBullet));
        CCSequence  *actionSequence = CCSequence::create(moveto, callFunc, NULL);
        bullet->runAction(actionSequence);

        break;
    }
}

void BulletCache::hideBullet(CCNode *sender)
{
    assert(NULL != sender);

    CCSprite *bullet = (CCSprite *)sender;
    bullet->setVisible(false);
}

