#include "GameScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace std;

CCScene* GameScene::scene()
{
    CCScene * scene = NULL;
    do
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        GameScene *layer = GameScene::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

bool GameScene::init()
{
    bool bRet = false;
    do
    {
        /* super init first */
        CC_BREAK_IF(! CCLayer::init());

        // 1. Add a menu item with "X" image, which is clicked to quit the program.
        // Create a "close" menu item with close icon, it's an auto release object.
        CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                              "CloseNormal.png",
                                                              "CloseSelected.png",
                                                              this,
                                                              menu_selector(GameScene::menuCloseCallback));
        CC_BREAK_IF(! pCloseItem);

        this->windowSize = CCDirector::sharedDirector()->getWinSize();
        // Place the menu item bottom-right conner.
        pCloseItem->setPosition(ccp(this->windowSize.width - 20, 20));

        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        // Add the menu to HelloWorld layer as a child layer.
        this->addChild(pMenu, 1);


		//this->schedule(schedule_selector(GameScene::updateFish), 1.0f);
        bRet = true;
    } while (0);

    return bRet;
}

void GameScene::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
