//
//  FishCache.h
//  mJoy
//
//  Created by Jerry Yang on 7/9/13.
//
//

#ifndef __FishCache__
#define __FishCache__

#include "cocos2d.h"
#include "GameConfig.h"

class FishCache : public cocos2d::CCNode
{
public:
    FishCache(void);
    ~FishCache(void);

    //CC_SYNTHESIZE(cocos2d::CCArray *, m_pFishes, fishes);
    static void spawnFish(FishCache *fish_cache);
    static void test(void);

    cocos2d::CCArray *SmallBatch;
    cocos2d::CCArray *NormalBatch;
    cocos2d::CCArray *MermaidBatch;
    cocos2d::CCArray *WhaleBatch;

    cocos2d::CCSize windowSize;

    /**
     // 精灵可动态通过 sp->setDisplayFrame(CCSpriteFrame *pNewFrame) 来实现被捕的动画
    cocos2d::CCSpriteBatchNode *Capture_SmallBatch;
    cocos2d::CCSpriteBatchNode *Capture_NormalBatch;
    cocos2d::CCSpriteBatchNode *Capture_MermaidBatch;
    cocos2d::CCSpriteBatchNode *Capture_WhaleBatch;
    */

private:
    void initBatch(void);
    void update(float delta);
};

#endif /* defined(__FishCache__) */
