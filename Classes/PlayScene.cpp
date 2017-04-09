#include "PlayScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "audio\include\AudioEngine.h"


USING_NS_CC;

using namespace cocos2d::experimental;
using namespace cocostudio::timeline;

const float TIME_LIMIT_SECOND = 1800;//残り時間（６０秒）
const float DECREASE_TIME = 0.5;//減っていく時間
const int RETURN_TIME = 30;//fpsを分単位に戻す
const float SCALSE_SIZE = 5.0;//文字を大きくするサイズ
//ラベルの高さと幅
const int TIME_LABEL_WIDTH = 350;
const int TIME_LABEL_HEIGHT = 70;
const int TEXT_TIME_LABEL_WIDTH = 550;
const int TEXT_TIME_LABEL_HEIGHT = 70;

const int SPRIITE_SIZE = 256;
const int SCREEN_WIDTH = 960;


const int ANIMETION＿PUTTURNS = 3;
const int ANIMETION＿FRAME = 30;


enum PLAYER
{
	PLAYER_1,
	PLAYER_2
};

//コンストラクタ
Play::Play()
	:m_timer(TIME_LIMIT_SECOND)
	, m_TimeLabel(NULL)
	,m_flag(true)
{
}
//デストラクター
Play::~Play()
{
	CC_SAFE_RELEASE_NULL(m_TimeLabel);//m_TimeLabelを破棄
}
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
// ===========================================
// @>概　要:タッチ座標に音波を生成
//
// @>引　数:タッチ座標(Vec2), どっちのプレイヤーがうったか(int)
//
// @>戻り値:なし
// ===========================================
void  Play::CreateWave(Vec2 pos, int player)
{

	// 画像ファイルの読み込み
	m_wave[player] = Sprite::create("Images\\wave_anm.png");

	// 最初のパターン画像を切り抜き
	m_wave[player]->setTextureRect(Rect(0, 0, SPRIITE_SIZE, SPRIITE_SIZE));

	// 座標をタッチ座標に変更
	m_wave[player]->setPosition(Vec2(pos.x, pos.y));

	// サイズをいい感じに調整
	m_wave[player]->setScale(0.4f);


	// シーンに追加
	this->addChild(m_wave[player]);
}


// ===========================================
// @>概　要:音波が画面外に出たら再発射可能にする
//
// @>引　数:なし
//
// @>戻り値:なし
// ===========================================
void Play::Reload()
{
	// 画面外に出たら発射状態を回復
	if (m_wave[PLAYER_1] != nullptr)
	{
		if (m_wave[PLAYER_1]->getPosition().x > SCREEN_WIDTH)
		{
			canShoot_1p = true;
		}
	}

	if (m_wave[PLAYER_2] != nullptr)
	{
		if (m_wave[PLAYER_2]->getPosition().x < 0)
		{
			canShoot_2p = true;
		}
	}
}

// ===========================================
// @>概　要:アニメーションの更新
//
// @>引　数:なし
//
// @>戻り値:なし
// ===========================================
void Play::AnimationUpdate()
{
	// アニメ―ションカウントの増加
	m_animation_cnt++;

	// 最大90フレーム設定
	m_animation_cnt %= 90;

	// 2つの音波のスプライトをそれぞれ切り替える
	for (int i = 0; i < 2; i++)
	{
		if (m_wave[i] != nullptr)
		{
			m_wave[i]->setTextureRect(Rect(0, (m_animation_cnt / 30)*SPRIITE_SIZE, SPRIITE_SIZE, SPRIITE_SIZE));
		}
	}
}


//----------------------------------------------------------------------
//! @brief RenderTimeLabel
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Play::RenderTimeLabel()
{
	//中心座標
	auto size = Director::getInstance()->getWinSize();
	//タイマー ラベルの追加
	int second = static_cast < int >(m_timer); // int 型 に キャスト する
	auto timeLabel = Label::createWithSystemFont(StringUtils::toString(second), "Arial Felt", 16);
	timeLabel->setColor(Color3B::BLACK);
	timeLabel->setPosition(Vec2(size.width - TIME_LABEL_WIDTH, size.height - TIME_LABEL_HEIGHT));
	timeLabel->setScale(SCALSE_SIZE);
	this->setTimeLabel(timeLabel);
	this->addChild(m_TimeLabel);
}

//----------------------------------------------------------------------
//! @brief RendertextTimeLabel
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------

void Play::RendertextTimeLabel()
{
	//中心座標
	auto size = Director::getInstance()->getWinSize();

	// タイマーヘッダーの追加
	auto textTimeLabel = Label::createWithSystemFont(" TIME", "Arial Felt", 16);
	textTimeLabel->setColor(Color3B::BLACK);
	textTimeLabel->setPosition(Vec2(size.width - TEXT_TIME_LABEL_WIDTH, size.height - TEXT_TIME_LABEL_HEIGHT));
	textTimeLabel->setScale(SCALSE_SIZE);
	this->addChild(textTimeLabel);
}
//----------------------------------------------------------------------
//! @brief UpadateTime
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------

void Play::UpadateTime()
{
	// 残り 秒 数 を 減らす
	m_timer -= DECREASE_TIME;
	// 残り 秒 数 の 表示 を 更新 する
	int second = static_cast < int >(m_timer / RETURN_TIME); // int 型 に キャスト する
	m_TimeLabel->setString(StringUtils::toString(second));
}
void Play::FormIwasHi()
{
	MoveTo*MoveByAction = MoveTo::create(3.0, Vec2(-1000, 340));
	DelayTime*DelayTimeAction = DelayTime::create(3);
	Sequence* SpawnAction = Sequence::create(DelayTimeAction, MoveByAction, nullptr);
	CCRect rect = CCRectMake(0, 0, 150, 50);
	iwashi = Sprite::create("Images\\PlaySeen.png");
	iwashi->setTextureRect(rect);
	iwashi->setPosition(1200, 340);
	this->addChild(iwashi);
	iwashi->runAction(SpawnAction);
	m_flag = false;
}
void Play::DeletIwashi()
{
	//鰯の座標を確認する
	float pos_x = iwashi->getPositionX();
	float pos_y = iwashi->getPositionY();
	//鰯の座標が0以下だったら
	if (pos_x < 0)
	{
		iwashi->removeFromParent();//鰯を削除
		iwashi = nullptr;
		m_flag = true;
	}
}
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

    
	// 変数初期化
	m_animation_cnt = 0;

	canShoot_1p = true;
	canShoot_2p = true;

	for (int i = 0; i < 2; i++)
	{
		m_wave[i] = nullptr;
	}


	// 背景
	m_bg = Sprite::create("Images\\BG.png");
	m_bg->setAnchorPoint(Vec2(0, 0));
	this->addChild(m_bg);

	// TIME描画
	RenderTimeLabel();
	RendertextTimeLabel();

	// updateを呼び出す設定
	this->scheduleUpdate();

	// イベントリスナーを作成
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();

	// イベントリスナーに各コールバック関数をセットする
	listener->onTouchBegan = CC_CALLBACK_2(Play::onTouchBegan, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	// BGMのプリロード
	AudioEngine::preload("Sounds\\SeenBGM.ogg");

	// SEのプリロード
	AudioEngine::preload("Sounds\\Sonic.ogg");

	// BGM再生
	se_wave = AudioEngine::play2d("Sounds\\SeenBGM.ogg", true);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//　イワシは3秒に一回くらい
	/* イワシ */
	// イワシ生成
	
	
	//Rect rect(float(0.0f), float(0.0f), float(150.0f), float(50.0f));

	//iwashi = Sprite::create("PlaySeen.png");
	//this->addChild(iwashi);
	/* アクション？ */
	// イワシ行動
	//Sprite*iwashi = Sprite::create("PlaySeen.png");
	//iwashi->setPosition(Vec2(100.0f, 0.0f));
	//this->addChild(iwashi);


	/* アクション */
	// イワシ行動

	//iwashi->setPosition(Vec2(iwashi->getContentSize));

	//iwashi = Sprite::create("PlaySeen.png");
	//iwashi->setPosition(Vec2(iwashi->getContentSize().width / 2, visibleSize.height / 2));
	/*addChild(iwashi);
	MoveTo* action1 = MoveTo::create(1, Vec2(visibleSize.width - iwashi->getContentSize().width / 2, visibleSize.height / 2));
	EaseBackInOut* action2 = EaseBackInOut::create(action1);
	Sequence*action3 = Sequence::create(action1, action2, action1, nullptr);
	RepeatForever* action4 = RepeatForever::create(action3);
*/
	//iwashi->runAction(action4);
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

	if (m_flag)
	{
		FormIwasHi();//鰯の生成
		DeletIwashi();//鰯が画面外に出たら破棄
	}
	// アニメーション更新
	AnimationUpdate();

	// 画面外に出たら発射状態を回復
	Reload();

	//残り時間の更新
	UpadateTime();


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
	if (touch_pos.x < (SCREEN_WIDTH / 2))
	{
		// 発射可能状態の時
		if (canShoot_1p)
		{
			Play::CreateWave(Vec2(0, touch_pos.y), PLAYER_1);
			m_wave[0]->setFlippedX(true);

			// アニメーションリセット
			m_animation_cnt = 0;

			// 発射を不可に
			canShoot_1p = false;

			// 画面外まで音波移動
			m_wave[PLAYER_1]->runAction(MoveBy::create(4.0f, Vec3(SCREEN_WIDTH + SCREEN_WIDTH, 0, 0)));

			// SE再生
			se_wave = AudioEngine::play2d("Sounds\\Sonic.ogg");

			return true;
		}
	}

	else // 画面半部より右がタップされたときの処理
	{
		// 発射可能状態の時
		if (canShoot_2p)
		{
			Play::CreateWave(Vec2(SCREEN_WIDTH, touch_pos.y), PLAYER_2);

			// アニメーションリセット
			m_animation_cnt = 0;

			// 発射を不可に
			canShoot_2p = false;

			// 画面外まで音波移動
			m_wave[PLAYER_2]->runAction(MoveBy::create(4.0f, Vec3(-(SCREEN_WIDTH + SCREEN_WIDTH), 0, 0)));

			// SE再生
			se_wave = AudioEngine::play2d("Sounds\\Sonic.ogg");

			return true;
		}
	}
	return false;
}