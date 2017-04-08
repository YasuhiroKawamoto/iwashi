#include "PlayScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

//const float TIME_LIMIT_SECOND = 1800;//残り時間（６０秒）
//const float DECREASE_TIME = 0.5;//減っていく時間
//const int RETURN_TIME = 30;//fpsを分単位に戻す
//const float SCALSE_SIZE = 5.0;
//const int TIME_LABEL_WIDTH = 350;
//const int TIME_LABEL_HEIGHT = 70;
//const int TEXT_TIME_LABEL_WIDTH = 550;
//const int TEXT_TIME_LABEL_HEIGHT = 70;

////コンストラクタ
//Play::Play()
//	:m_timer(TIME_LIMIT_SECOND)
//	, m_TimeLabel(NULL)
//{
//}
////デストラクター
//Play::~Play()
//{
//	CC_SAFE_RELEASE_NULL(m_TimeLabel);//m_TimeLabelを破棄
//}
//----------------------------------------------------------------------
//! @brief createScene
//!
//! @param[in] なし
//!
//! @return  scene
//----------------------------------------------------------------------
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
//----------------------------------------------------------------------
//! @brief CreateWave
//!
//! @param[in] Vec2 pos
//!
//! @return なし
//----------------------------------------------------------------------
void  Play::CreateWave(Vec2 pos)
{
	m_wave = Sprite::create("Images\\Sonic_1.png");
	m_wave->setPosition(Vec2(pos.x, pos.y));
	m_wave->setScale(0.6f);
	this->addChild(m_wave);
}
//----------------------------------------------------------------------
//! @brief RenderTimeLabel
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
//void Play::RenderTimeLabel()
//{
//	//中心座標
//	auto size = Director::getInstance()->getWinSize();
//	//タイマー ラベルの追加
//	int second = static_cast < int >(m_timer); // int 型 に キャスト する
//	auto timeLabel = Label::createWithSystemFont(StringUtils::toString(second), "Arial Felt", 16);
//	timeLabel->setPosition(Vec2(size.width - TIME_LABEL_WIDTH, size.height - TIME_LABEL_HEIGHT));
//	timeLabel->setScale(SCALSE_SIZE);
//	this->setTimeLabel(timeLabel);
//	this->addChild(m_TimeLabel);
//}
//----------------------------------------------------------------------
//! @brief RendertextTimeLabel
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------

//void Play::RendertextTimeLabel()
//{
//	//中心座標
//	auto size = Director::getInstance()->getWinSize();
//
//	// タイマーヘッダーの追加
//	auto textTimeLabel = Label::createWithSystemFont(" TIME", "Arial Felt", 16);
//	textTimeLabel->setPosition(Vec2(size.width - TEXT_TIME_LABEL_WIDTH, size.height - TEXT_TIME_LABEL_HEIGHT));
//	textTimeLabel->setScale(SCALSE_SIZE);
//	this->addChild(textTimeLabel);
//}
//----------------------------------------------------------------------
//! @brief UpadateTime
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------

//void Play::UpadateTime()
//{
//	// 残り 秒 数 を 減らす
//	m_timer -= DECREASE_TIME;
//	// 残り 秒 数 の 表示 を 更新 する
//	int second = static_cast < int >(m_timer / RETURN_TIME); // int 型 に キャスト する
//	m_TimeLabel->setString(StringUtils::toString(second));
//}
//----------------------------------------------------------------------
//! @brief init
//!
//! @param[in] なし
//!
//! @return true or false
//----------------------------------------------------------------------
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

	//addChild(rootNode);

	//RenderTimeLabel();
	//RendertextTimeLabel();

	// updateを呼び出す設定
	this->scheduleUpdate();

	// イベントリスナーを作成
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();

	// イベントリスナーに各コールバック関数をセットする
	listener->onTouchBegan = CC_CALLBACK_2(Play::onTouchBegan, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//　イワシは3秒に一回くらい
	/* イワシ */
	// イワシ生成
//	Sprite*iwashi = Sprite::create("");

//	this->addChild(iwashi);

	/* アクション？ */
	// イワシ行動

	///////////////////////////////////////////
	//残りタイムが0になったらリザルト画面に行く
	///////////////////////////////////////////
	//if (m_timer < 0)
	//{

	//}

    return true;
}
//----------------------------------------------------------------------
//! @brief update(毎フレーム呼び出されるupdate関数)
//!
//! @param[in] なし
//!
//! @return 
//----------------------------------------------------------------------
void Play::update(float delta)
{
	//UpadateTime();//残り時間の更新
}
//----------------------------------------------------------------------
//! @brief onTouchBegan
//!
//! @param[in] cocos2d::Touch* touch, cocos2d::Event* unused_event
//!
//! @return true or false
//----------------------------------------------------------------------
bool Play::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event)
{
	// タッチ座標を取得
	Vec2 touch_pos = touch->getLocation();

	// y座標に制限を付ける
	if (touch_pos.y > 400)
	{
		touch_pos.y = 400;
	}

	// 画面半部より左がタップされたときの処理
	if (touch_pos.x < (960 / 2))
	{
		Play::CreateWave(Vec2(0, touch_pos.y));
		m_wave->setFlippedX(true);

		// 音波移動
		m_wave->runAction(MoveBy::create(2.0f, Vec3(1000, 0, 0)));
		return true;
	}

	// 画面半部より右がタップされたときの処理
	else
	{
		Play::CreateWave(Vec2(960, touch_pos.y));

		// 音波移動
		m_wave->runAction(MoveBy::create(2.0f, Vec3(-1000, 0, 0)));
		return true;
	}

	return false;

}