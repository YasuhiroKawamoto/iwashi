/***************************************************************************
*|
*|	概要　　ResultSceneクラスの定義
*|　作成者　GS2 16 中田湧介
*|　作成日　2017/4/08
*|___________________________________________________________________________
****************************************************************************/

/* ---- ライブラリのインクルード ---------- */
#include "ResultScene.h"
#include "ResultLayer.h"
#include "EventListenerGesture.h"
#include "ResultScene\Score.h"
#include "audio\include\AudioEngine.h"
#include "TitleScene\TitleScene.h"
#include "Score.h"
USING_NS_CC;
using namespace cocos2d::experimental;


/* ---- メンバー関数の定義 ---------------- */
/***************************************************************************
*|	概要　　シーンを作成する。
*|	引数　　無し
*|　戻り値　シーンのアドレス
****************************************************************************/
Scene* ResultScene::create(int score)
{
	//メモリ確保
	ResultScene *pRet = new(std::nothrow)ResultScene();

	if (pRet && pRet->init(score))
    { 
        pRet->autorelease(); 
        return pRet; 
    } 
    else 
    { 
        delete pRet; 
        pRet = nullptr; 
        return nullptr; 
    } 
}

/***************************************************************************
*|	概要　　プレイシーンのレイヤーを呼びだす
*|	引数　　無し
*|　戻り値　無し
****************************************************************************/

bool ResultScene::init(int score)
{
	// 親クラスを初期化する
	if (!Scene::init())
	{
		return false;
	}
	Score::m_Score = score;

	// キャラクター呼び出し
	auto result_layer = ResultLayer::create();
	// キャラクター関連のレイヤ
	this->addChild(result_layer);

	// タッチイベントリスナーを作成
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(ResultScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	//音楽ファイルを予めロードしておく
	AudioEngine::preload("Sounds/TapSE.ogg");
	//効果音
	ResultBGM = AudioEngine::play2d("Sounds/ResultBGM.mp3", true);
	bubble = AudioEngine::play2d("Sounds/bubble.mp3");
	AudioEngine::setLoop(bubble, true);
	
	return true;
}

/***************************************************************************
*|	概要　　キーが押されたとき呼び出される関数
*|	引数　　無し
*|　戻り値　無し
****************************************************************************/
// タッチ開始時コールバック
bool ResultScene::onTouchBegan(Touch* touch, Event* pEvent)
{
	
	////フェードトランジション
	//nextScene = TransitionOriginal::create(1.0f, nextScene);
	if (Score::SceneFlag == true)
	{
		Score::SceneFlag = false;
		//BGM終了
		AudioEngine::stop(ResultBGM);
		AudioEngine::stop(bubble);
		AudioEngine::uncache("Sounds/ResultBGM.mp3");

		// 次のシーンを作成する
		Scene* nextScene = TitleScene::create();
		// 次のシーンに移行
		_director->replaceScene(nextScene);
	}
	//効果音
	int id = AudioEngine::play2d("Sounds/TapSE.ogg");


	return true;

}
