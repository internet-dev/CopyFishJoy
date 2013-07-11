//
//  FishCache.cpp
//  mJoy
//
//  Created by Jerry Yang on 7/9/13.
//
//

#include "FishCache.h"

const int g_small_id_conf[]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 13, 14, 15};
const int g_normal_id_conf[]  = {10, 18};
const int g_mermaid_id_conf[] = {11, 12};
const int g_whale_id_conf[]   = {16, 17};

// CC_DEGREES_TO_RADIANS

using namespace cocos2d;

FishCache::FishCache(void)
{
    CCLOG("FishCache __construct");

    this->windowSize = CCDirector::sharedDirector()->getWinSize();
    this->initBatch();
}

FishCache::~FishCache(void)
{
    CCLOG("FishCache __destruct");
}

void FishCache::initBatch(void)
{
    CCLOG("initBatch");

    int i = 0;
    int k = 0;
    int count = 0;
    int fish_id = 0;

    count = sizeof(g_small_id_conf) / sizeof(g_small_id_conf[0]);
    CCLOG("count(g_small_id_conf) = %d", count);
    for (k = 0; k < count; k++) {
        fish_id = g_small_id_conf[k];
    }
}

void FishCache::update(float delta)
{
    //
}
