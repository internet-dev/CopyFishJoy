//
//  FishCache.cpp
//  mJoy
//
//  Created by Jerry Yang on 7/9/13.
//
//

#include "FishCache.h"

/** 配置不容许运行时修改 */
const int g_small_id_conf[]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 13, 14}; // 15 不存在
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
    int group_id = 0;
    int fish_id  = 0;

    const int *conf = NULL;

    CCArray *batch_table[FISH_GROUP_COUNT] = {
        /*
        this->SmallBatch,
        this->NormalBatch,
        this->MermaidBatch,
        this->WhaleBatch,
        */
    };

    for (; i < FISH_GROUP_COUNT; i++)
    {
        group_id = i;
        int cache_number = 0;
        int single_cache = 0;

        switch (i)
        {
            case FISH_GROUP_SMALL:
                count = sizeof(g_small_id_conf) / sizeof(g_small_id_conf[0]);
                conf  = g_small_id_conf;
                cache_number = count * FISH_SMALL_CACHE;
                single_cache = FISH_SMALL_CACHE;
                this->SmallBatch = CCArray::createWithCapacity(cache_number);
                this->SmallBatch->retain();
                batch_table[i] = this->SmallBatch;
                break;

            case FISH_GROUP_NORMAL:
                count = sizeof(g_normal_id_conf) / sizeof(g_normal_id_conf[0]);
                conf  = g_normal_id_conf;
                cache_number = count * FISH_NORMAL_CACHE;
                single_cache = FISH_NORMAL_CACHE;
                this->NormalBatch = CCArray::createWithCapacity(cache_number);
                this->NormalBatch->retain();
                batch_table[i] = this->NormalBatch;
                break;

            case FISH_GROUP_MERMAID:
                count = sizeof(g_mermaid_id_conf) / sizeof(g_mermaid_id_conf[0]);
                conf  = g_mermaid_id_conf;
                cache_number = count * FISH_MERMAID_CACHE;
                single_cache = FISH_MERMAID_CACHE;
                this->MermaidBatch = CCArray::createWithCapacity(cache_number);
                this->MermaidBatch->retain();
                batch_table[i] = this->MermaidBatch;
                break;

            case FISH_GROUP_WHALE:
                count = sizeof(g_whale_id_conf) / sizeof(g_whale_id_conf[0]);
                conf  = g_whale_id_conf;
                cache_number = count * FISH_WHALE_CACHE;
                single_cache = FISH_WHALE_CACHE;
                this->WhaleBatch = CCArray::createWithCapacity(cache_number);
                this->WhaleBatch->retain();
                batch_table[i] = this->WhaleBatch;
                break;

            default:
                CCLOG("!!! Wrong...");
                return;
                //break;
        }

        CCLOG("###count(group %d) = %d", i, count);
        for (k = 0; k < count; k++)
        {
            fish_id = conf[k];

            CCString *originalFrameName = CCString::createWithFormat("fish%02d_01.png", fish_id);
            CCLOG("@@@original file name: %s", originalFrameName->getCString());

            CCLOG("$$$ group: %d, single_cache: %d", group_id, single_cache);
            for (int m = 0; m < single_cache; m++)
            {
                Fish *fish = new Fish();
                fish->group_id = group_id;
                fish->fish_id  = fish_id;

                fish->fish_sprite = fish->createWithSpriteFrameName(originalFrameName->getCString());
                if (NULL == batch_table[i])
                {
                    CCLOG("@@@ batch_table[%d] is NULL @@@", i);
                }
                /** debug ues true */
                fish->fish_sprite->setVisible(true);

                /** 测试显示 */
                CCPoint pos = ccp(rand() % (int)this->windowSize.width, rand() % (int)this->windowSize.height);
                //CCLOG("pos: {x: %f, y: %f}", pos.x, pos.y);
                fish->fish_sprite->setPosition(pos);

                batch_table[i]->addObject(fish);
                this->addChild(fish->fish_sprite);
            }
        }
    }
}

void FishCache::update(float delta)
{
    CCLOG("FishCache::update(float delta)");
}

void FishCache::spawnFish(FishCache *fish_cache)
{
    assert(NULL != fish_cache);
    CCLOG("FishCache::spawnFish(void)");

    CCArray *fish_array = (CCArray *)fish_cache->NormalBatch;
    CCLOG("count(fish_cache->NormalBatch) = %d", fish_array->count());

    //Fish *fish = (Fish *)fish_cache->NormalBatch->objectAtIndex(0);
    //CCLOG("fish->group_id: %d, fish_id: %d", fish->group_id, fish->fish_id);
}
