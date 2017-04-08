#include "PlayScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

////////////////////////////////////////////////////////
//														
// 
// 
/////////////////////////////////////////////////////////


using namespace cocostudio::timeline;

Scene* Play::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Play::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Play::init()
{
    /**  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    **/
    

    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

	//　イワシは3秒に一回くらい
	/* イワシ */
	// イワシ生成
	Sprite*iwashi = Sprite::create("PlaySeen.png");
	Sprite->setPosition(Vec2(100.0f, 0.0f));
	this->addChild(iwashi);


	/* アクション */
	// イワシ行動

	iwashi->setPosition(Vec2(iwashi->getContentSize))


	auto sprite = Sprite::create("PlaySeen.png");
	sprite->setPosition(Vec2(sprite->getContentSize().width / 2, visibleSize.height / 2));
	addChild(sprite);	
	MoveTo* action1 = MoveTo::create(1, Vec2(visibleSize.width - iwashi->getContentSize().width / 2, visibleSize.height / 2));
	EaseBackInOut* action2 = EaseBackInOut::create(action);
	Sequence*action3 = Sequence::create(action1, action2, action1, nullptr);
	RepeayForever* action4 = RepeatForever::create(action3);

	iwasi->runaction(action);


    return true;
}


