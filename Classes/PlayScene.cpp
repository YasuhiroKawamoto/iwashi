#include "PlayScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "ResultScene\\ResultScene.h"




#include "ResultScene\ResultScene.h"

#include "audio\include\AudioEngine.h"


USING_NS_CC;

using namespace cocos2d::experimental;
using namespace cocostudio::timeline;

const float TIME_LIMIT_SECOND = 900;//残り時間（６０秒）
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
	,m_TimeLabel(NULL)
	,m_flag(true)
	,m_CountFlag(true)
	, m_TotalScore(321)
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


// ===========================================
// @>概　要:（暫定的）当たり判定
//
// @>引　数:なし
//
// @>戻り値:bool(true:当たった)
// ===========================================
bool Play::Collision()
{
	
	if (iwashi != nullptr)
	{
		// 鰯スプライトのバウンディングボックスを取得
		r_iwashi = iwashi->getBoundingBox();


		// 1P音波のバウンディングボックスを取得
		
		isHit1 = false;
		if (m_wave[PLAYER_1] != nullptr)
		{
			r_wave1 = m_wave[PLAYER_1]->getBoundingBox();
		}

		// 1P音波のバウンディングボックスを取得
	
		isHit2 = false;
		if (m_wave[PLAYER_2] != nullptr)
		{
			r_wave2 = m_wave[PLAYER_2]->getBoundingBox();
		}

		// 矩形同士で当たり判定を取得
		isHit1 = r_iwashi.intersectsRect(r_wave1);
		isHit2 = r_iwashi.intersectsRect(r_wave2);

		// どちらとものスプライトと当たったとき
		if (isHit1 && isHit2)
		{
			isHit1 = false;
			isHit2 = false;
			return true;
		}
	}
	return false;
}

void Play::GetIwashi()
{
	// SE
	AudioEngine::play2d("Sounds\\Splash.ogg");

	// 作成したパーティクルのプロパティリストを読み込み
	ParticleSystemQuad* particle = ParticleSystemQuad::create("Images\\kirakira.plist");
	//パーティクルのメモリーリーク回避（★重要）
	particle->setAutoRemoveOnFinish(true);
	// パーティクルを開始
	particle->resetSystem();
	// パーティクルを表示する場所の設定
	particle->setPosition(480, 500);
	// パーティクルを配置
	this->addChild(particle);


	// パーティクルにアクション
	DelayTime* delay2 = DelayTime::create(1.5f);
	RemoveSelf* remove2 = RemoveSelf::create();
	Sequence* sequence_particle = Sequence::create(delay2, remove2, nullptr);
	particle->runAction(sequence_particle);
	particle = nullptr;

	// 魚にアクション
	iwashi->stopActionByTag(100);
	iwashi->setAnchorPoint(Vec2(0.5f, 0.5f));
	MoveTo* move = MoveTo::create(0.25f, Vec2(480, 50));		// バグってる
	ScaleTo* scale = ScaleTo::create(0.2f, 2.5f);
	Spawn* spawn = Spawn::create(scale, move, nullptr);
	DelayTime* delay = DelayTime::create(1.5f);
	RemoveSelf* remove = RemoveSelf::create();
	CallFunc* call = CallFunc::create(CC_CALLBACK_0(Play::IwashiDelete,this));
	Sequence* sequence_iwahi = Sequence::create(spawn, delay, remove, call, nullptr);
	iwashi->runAction(sequence_iwahi);
	
	// スプライトの解放
	if (m_wave[PLAYER_1] != nullptr)
	{
		m_wave[PLAYER_1]->runAction(RemoveSelf::create());
		m_wave[PLAYER_1] = nullptr;
	}
	if (m_wave[PLAYER_2] != nullptr)
	{
		m_wave[PLAYER_2]->runAction(RemoveSelf::create());
		m_wave[PLAYER_2] = nullptr;
	}

	// 発射状態のリセット
	canShoot_1p = true;
	canShoot_2p = true;
}
// ===========================================
// @>概　要:スコアの計算
//
// @>引　数:各種スコア（３段階の鰯、ごみのスコア、ボーナススコア）
//
// @>戻り値:合計のスコア
// ===========================================

int Play::SumScore(int score)
{

	return m_TotalScore += score;
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
	auto timeLabel = Label::createWithSystemFont(StringUtils::toString(second), "Default Font", 16);
	timeLabel->setColor(Color3B::BLACK);
	timeLabel->setPosition(Vec2(700,570));
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
	auto textTimeLabel = Label::createWithSystemFont(" TIME", "Default Font", 16);
	textTimeLabel->setColor(Color3B::BLACK);
	textTimeLabel->setPosition(Vec2(500, 570));
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

	for (int i = 0; i < 10; i++)
	{
		if(iwashies[i] != nullptr)
		iwashies[i] = Iwashi::GenerateIwashi();

		// イワシのスプライトをシーンに追加
	//	this->addChild(iwashies[i]->GetSprite());
		break;
	}

	MoveTo* MoveByAction = MoveTo::create(10.0, Vec2(-1000, 340));
	DelayTime* DelayTimeAction = DelayTime::create(0);
	Sequence* SpawnAction = Sequence::create(DelayTimeAction, MoveByAction, nullptr);
	SpawnAction->setTag(100);
	iwashi = Sprite::create("Images\\PlaySeen.png");
	iwashi->setTextureRect(Rect(0,0,150,50));
	iwashi->setPosition(1200, 340);
	this->addChild(iwashi);
	iwashi->runAction(SpawnAction);
	m_flag = false;
	for (int i = 0; i < 10; i++)
	{
		if (iwashies[i] != nullptr)
		{
			iwashies[i] = Iwashi::GenerateIwashi();

			// イワシのスプライトをシーンに追加

			this->addChild(iwashies[i]->GetSprite());
		}
		break;
	}


}
void Play::DeletIwashi()
{
	//鰯の座標が0以下だったら
	if (iwashi->getPositionX() <= 0)
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
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    
	// 変数初期化==============================
	m_animation_cnt = 0;

	canShoot_1p = true;
	canShoot_2p = true;

	// 音波
	for (int i = 0; i < 2; i++)
	{
		m_wave[i] = nullptr;
	}

	// イワシ
	for (int i = 0; i < 10; i++)
	{
		iwashies[i] = nullptr;
	}

	iwashi = nullptr;

	// 背景===================================
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

	
	// SEのプリロード
	AudioEngine::preload("Sounds\\Sonic.ogg");
	AudioEngine::preload("Sounds\\Splash.ogg");

	// BGM再生
	bgm_play = AudioEngine::play2d("Sounds\\SeenBGM.ogg", true);

	FormIwasHi();//鰯の生成

		//////////////////////////////////////////
	
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

	if (m_flag==true)
	{

		FormIwasHi();

		DeletIwashi();//鰯が画面外に出たら破棄
	}
	// アニメーション更新
	AnimationUpdate();

	// 画面外に出たら発射状態を回復
	Reload();

	// !!!======!!! 暫定的 !!!======!!! //
	// 当たり判定()
	if (Collision())
	{
		// 鰯ゲット
		GetIwashi();
	}

	//残り時間の更新
	UpadateTime();

	//スコアの描画
	ScoreIndicate(m_TotalScore);

	//残りタイムが0になったらリザルト画面に行く
	///////////////////////////////////////////

	if (m_timer <= 0)
	{
		// BGM停止
		AudioEngine::stop(bgm_play);
		AudioEngine::uncache("Sounds\\SeenBGM.ogg");


		//auto director = Director::getInstance();

		//// create a scene. it's an autorelease object
		//auto scene = ResultScene::createScene();

		//// run
		//director->runWithScene(scene);
		// 次のシーンを作成する
		Scene* nextScene = ResultScene::create();
		// 次のシーンに移行
		_director->replaceScene(nextScene);
	}

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

void Play::ScoreIndicate(int Score)
{
	int j;

	//桁数を初期化する
	Digit = 1;
	//対象のスコアを保存する
	Score2 = Score;

	//スコアが何桁あるのか求める
	//整数がなくなるまで10で除法する

	//スコアが0じゃないとき
	if ((Score - Score2 != Score))
	{
		while (Score - Score2 != Score)
		{
			Score2 /= 10;
			//何回ループしたかカウントする
			Digit *= 10;

		}
		//小数になるまでかけたが、桁数を知りたいので10で割る
		Digit /= 10;
	}




	//対象のスコアを保存する
	Score2 = Score;

	j = 0;
	while (Digit != 0)
	{
		//残りの値が0になる時、「Digit桁の値を求める」でエラーになる
		//残りの値が0になる時、桁数分の0を表示して
		if (Score2 <= 0)
		{
			//Digit桁の値を求める
			Score = 0;
		}
		else
		{
			//Digit桁の値を求める
			Score /= Digit;
		}
		//SCOREのスプライトの作成
		m_ScoreImage= Sprite::create("Images\\Score.png");
		m_ScoreImage->setPosition(Vec2(100, 570));
		this->addChild(m_ScoreImage);
		//数字のスプライトを作成する
		s_Number = Sprite::create("Images\\Number.png");
		//レクトを設定する
		s_Number->setTextureRect(Rect(Score * 64, 0, 64, 64));

		if (m_CountFlag==true)
		{
			//座標
			s_Number->setPosition(Vec2(250 + 64 * j, 570));
			this->addChild(s_Number);
		}
		//スコアから求めた値を引く
		Score2 -= Score * Digit;
		//次はDigit-1桁を見る
		Digit /= 10;
		j++;
	}
	m_CountFlag = false;
}

//鰯を捕獲したら削除する関数
void Play::IwashiDelete()
{
	iwashi = nullptr;
}

