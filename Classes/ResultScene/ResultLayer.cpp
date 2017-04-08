/***************************************************************************
*|
*|	概要　　リザルトレイヤー
*|　作成者　GF3 17 中田湧介
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
	score->ScoreIndicate(ScoreNumber);
	

	////毎フレームアップデート関数を呼びだす
	this->scheduleUpdate();


	return true;
}


/***************************************************************************
*|	概要　　
*|	引数　　無し
*|　戻り値　無し
****************************************************************************/
void ResultLayer::update(float date)
{
	//一秒ごとにスコアのアクションを呼ぶ
	ActionCnt++;
	if ((ActionCnt == 60)&&(RankingCnt >= 0))
	{
		score->ScoreAction(RankingCnt);
		ActionCnt = 0;
		RankingCnt--;
	}
}