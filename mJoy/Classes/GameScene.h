#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "GameConfig.h"

class GameScene : public cocos2d::CCLayer
{
public:
    /** 成员属性 { */
    cocos2d::CCSize windowSize;
    /** } */

    /** 成员方法 { */
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene *scene();

    /** 半静态方法,快速取当前游戏场景 */
    static GameScene *sharedGameScene(void);

    /** 关闭按钮 */
    void menuCloseCallback(CCObject* pSender);

    /** 触控事件代理 */
    virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

    CREATE_FUNC(GameScene);
    // CC_SYNTHESIZE
    /** } */

private:
    /** 批量加载资源 */
    void loadFrames(void);
    void loadSource(void);
    /** 初始化静态 UI */
    void initUI(void);
    /** 创建游戏节点 */
    void initGame(void);
    /** 游戏更新 */
    void update(float delta);

    void touchEvent(cocos2d::CCPoint touch_pos);
};

#endif // __GAME_SCENE_H__
