#include "GameScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace std;

static GameScene* instanceOfGameScene;

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
        /** 设置随机种子 */
        srand(time(NULL));

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

        /** 开启触控 */
        this->setTouchEnabled(true);
        /** 批量加载资源 */
        this->loadFrames();
        /** 初始化基本 UI */
        this->initUI();
        this->initNode();

        /** schedule */
        //this->schedule(schedule_selector(GameScene::update), 1.0f);
        bRet = true;

        instanceOfGameScene = this;
    } while (0);

    return bRet;
}

GameScene *GameScene::sharedGameScene(void)
{
    assert(NULL != instanceOfGameScene);

    return instanceOfGameScene;
}

void GameScene::loadFrames(void)
{
    CCLOG("GameScene::loadFrames(void)");
    CCSpriteFrameCache *pFC = CCSpriteFrameCache::sharedSpriteFrameCache();
    assert(NULL != pFC);

    pFC->addSpriteFramesWithFile("fish.plist");
    pFC->addSpriteFramesWithFile("fish2.plist");
    pFC->addSpriteFramesWithFile("fish3.plist");
    pFC->addSpriteFramesWithFile("fish4.plist");
    pFC->addSpriteFramesWithFile("cannon.plist");
}

void GameScene::initUI(void)
{
    CCLOG("GameScene::initUI(void)");

    CCTextureCache *pSTC = CCTextureCache::sharedTextureCache();

    /** 背景 */
    CCTexture2D *texture = pSTC->addImage("bj01.jpg");
    CCSprite *pBG = CCSprite::createWithTexture(texture);
    pBG->setAnchorPoint(ccp(0.5f, 0.5f));
    pBG->setPosition(ccp(this->windowSize.width * 0.5f, this->windowSize.height * 0.5f));
    this->addChild(pBG);

    /** top bar */
    texture = pSTC->addImage("ui_box_01.png");
    CCSprite *pTopBar = CCSprite::createWithTexture(texture);
	pTopBar->setAnchorPoint(ccp(0.5f, 1.0f));
	pTopBar->setPosition(ccp((this->windowSize.width * 0.5f), (this->windowSize.height)));
    this->addChild(pTopBar, UI_LAYER_TAG);

    /** 底栏静态 UI 图 */
    texture = pSTC->addImage("ui_box_02.png");
    CCSprite *pBottomBar = CCSprite::createWithTexture(texture);
    pBottomBar->setAnchorPoint(ccp(0.0f, 0.0f));
	pBottomBar->setPosition(ccp(0.0f, 0.0f));
    this->addChild(pBottomBar, UI_LAYER_TAG);
}

void GameScene::initNode(void)
{
    CCLOG("GameScene::intNode(void)");
}

void GameScene::update(float delta)
{
    CCLOG("GameScene::update->delte = %f", delta);
}

void GameScene::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();

    /** ios 设备最好加上以下内容 */
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
