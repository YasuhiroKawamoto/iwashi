/***************************************************************************
*|
*|	概要　　リザルトレイヤー
*|　作成者　GS2 16 中田湧介
*|　作成日　2017/4/07
*|___________________________________________________________________________
****************************************************************************/
/* ---- ライブラリのインクルード ---------- */
#include "ResultLayer.h"

USING_NS_CC;

bool ResultLayer::init()
{
	if (!Layer::init()) {

		return false;

	}

	//レイヤーにノードを集約
	BackGround* background = BackGround::create();
	this->addChild(background);

	score = Score::create();
	this->addChild(score);

	//カウントを初期化する
	ActionCnt = 0;
	RankingCnt = 5;
	
	
	//ランキング取得
	score->sortAllChildren();
	//ランキング変更
	score->RankingSort();
	//ランキング保存
	score->ScoreResister();
	//ランキングスコアの設定
	for (int i = 0; i < MAX_SCORE; i++)
	{
		score->ScoreIndicate(i);
	}
	//今回のスコアの設定
	score->ScoreIndicate(5);
	
	// タッチイベントリスナーを作成
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(ResultLayer::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(ResultLayer::onTouchEnded, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	////毎フレームアップデート関数を呼びだす
	this->scheduleUpdate();


	return true;
}

/***************************************************************************
*|	概要　	タッチされたら
*|	引数　　無し
*|　戻り値　無し
****************************************************************************/
bool ResultLayer::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent)
{
	//スコアのアクションの速度
	Score::ScoreActionSpd = 0.5f;
	ActionCnt++;
	return true;
}
/***************************************************************************
*|	概要　	タッチはなされたら
*|	引数　　無し
*|　戻り値　無し
****************************************************************************/
void ResultLayer::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * pEvent)
{
	//スコアのアクションの速度
	Score::ScoreActionSpd = 1.0f;
}

/***************************************************************************
*|	概要　	スコアのアクション関数を呼びだす　
*|	引数　　無し
*|　戻り値　無し
****************************************************************************/
void ResultLayer::update(float date)
{
	//一秒ごとにスコアのアクションを呼ぶ
	ActionCnt++;
	if ((ActionCnt >= 60)&&(RankingCnt >= 0))
	{
		score->ScoreAction(RankingCnt);
		ActionCnt = 0;
		RankingCnt--;
	}
}