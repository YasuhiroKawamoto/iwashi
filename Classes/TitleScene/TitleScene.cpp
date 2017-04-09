/***************************************************************************
*|
*|	概要　　TitleSceneクラスの定義
*|　作成者　GF3 17 中田湧介
*|　作成日　2017/4/08
*|___________________________________________________________________________
****************************************************************************/

/* ---- ライブラリのインクルード ---------- */
#include "TitleScene.h"
#include "TitleLayer.h"
#include "EventListenerGesture.h"
#include "audio\include\AudioEngine.h"
USING_NS_CC;
using namespace cocos2d::experimental;

/* ---- メンバー関数の定義 ---------------- */
/***************************************************************************
*|	概要　　シーンを作成する。
*|	引数　　無し
*|　戻り値　シーンのアドレス
****************************************************************************/
cocos2d::Scene * TitleScene::createScene()
{
	// シーンを作成する

	auto scene = Scene::create();
	// レイヤーを作成する

	auto layer = TitleScene::create();
	// レイヤーをシーンに追加する

	scene->addChild(layer);
	// シーンを返す

	return scene;
}

/***************************************************************************
*|	概要　　プレイシーンのレイヤーを呼びだす
*|	引数　　無し
*|　戻り値　無し
****************************************************************************/
bool TitleScene::init()
{
	// 親クラスを初期化する
	if (!Scene::init())
	{
		return false;
	}

	// キャラクター呼び出し
	auto title_layer = TitleLayer::create();
	// キャラクター関連のレイヤ
	this->addChild(title_layer);

	//BGM
	int Bgm = AudioEngine::play2d("TapSE.ogg");

	//BGMループ再生
	AudioEngine::setLoop(Bgm, true);

}

bool TitleScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent)
{
	//効果音
	int id = AudioEngine::play2d("TapSE.ogg");
	return false;
}
