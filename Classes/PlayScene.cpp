#include "PlayScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

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
    
	// updateを呼び出す設定
	this->scheduleUpdate();

	//
	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(Play::onKeyPressed, this);

    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

	//　イワシは3秒に一回くらい
	/* イワシ */
	// イワシ生成
//	Sprite*iwashi = Sprite::create("");

//	this->addChild(iwashi);

	/* アクション？ */
	// イワシ行動

	// 親ノードの作成
	m_pParentNode = Node::create();
	m_pParentNode->setPosition(960, 50);

	// １P初期化
	m_player1 = Sprite::create("tekito.png");

	m_pParentNode->addChild(m_player1);	// カーソルを親ノードに追加
	
	MoveBy* up = MoveBy::create(2, Vec3(0, 300, 0));
	MoveBy* down = MoveBy::create(2, Vec3(0, -300, 0));

	Sequence* upDown = Sequence::create(up, down, nullptr);
	RepeatForever* rUpDown = RepeatForever::create(upDown);

	m_pParentNode->runAction(rUpDown);

	// 音波初期化
	m_wave = Sprite::create("Images\\Sonic_1.png");
	m_wave->setScale(0.4f);
	m_wave->setVisible(false);

	m_pParentNode->addChild(m_wave);	// 音波を親ノードに追加


	this->addChild(m_pParentNode);

    return true;
}

// 毎フレーム呼び出されるupdate関数
void Play::update(float delta)
{


}

void Play::onKeyPressed(cocos2d::EventKeyboard::KeyCode key_code, cocos2d::Event* key_event)
{

	cocos2d::log("test");
	switch (key_code)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_ENTER:
		cocos2d::log("test");
		m_wave->setVisible(true);
		runAction(MoveBy::create(1, Vec3(0, 10, 0)));
		break;
	default:
		break;
	}

}


