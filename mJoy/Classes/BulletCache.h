//
//  BulletCache.h
//  mJoy
//
//  Created by Jerry Yang on 7/23/13.
//
//

#ifndef __BulletCache__
#define __BulletCache__

#include "cocos2d.h"
#include "GameConfig.h"

class BulletCache : public cocos2d::CCNode
{
public:
    BulletCache(void);
    ~BulletCache(void);
    
    cocos2d::CCArray *BulletBatch;
    cocos2d::CCSize windowSize;

private:
    void initBatch(void);
};

#endif /* defined(__BulletCache__) */