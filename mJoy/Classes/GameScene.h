#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::CCLayer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();

    cocos2d::CCSize windowSize;

    /** 关闭按钮 */
    void menuCloseCallback(CCObject* pSender);

    CREATE_FUNC(GameScene);

private:
    void update(float delta);
};

#endif // __GAME_SCENE_H__
