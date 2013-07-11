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
#include "Fish.h"

#define FISH_TOTAL  30  /** 场景中可显示的鱼的最大数目 */

/** 定义cache 数目 */
#define FISH_SMALL_CACHE    10  /** 炮灰 */
#define FISH_NORMAL_CACHE   5   /** 普通鱼类 */
#define FISH_MERMAID_CACHE  5   /** 美人鱼 */
#define FISH_WHALE_CACHE    5   /** 鲸鱼 */

/** 正常逻辑精灵缓存 */
/**
 GSNT_SmallSpriteBatch = 1,
 GSNT_NormalSpriteBatch,
 GSNT_MermaidSpriteBatch,
 GSNT_WhaleSpriteBatch,
 */

/** 被捕捉时精灵缓存 */
/**
 GSNT_Capture_SmallSpriteBatch,
 GSNT_Capture_NomalSpriteBatch,
 GSNT_Capture_MermaidSpriteBatch,
 GSNT_Capture_WhaleSpriteBatch,
 */

class FishCache : public cocos2d::CCNode
{
public:
    FishCache(void);
    ~FishCache(void);

    CC_SYNTHESIZE(cocos2d::CCArray *, m_pFishes, fishes);

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
