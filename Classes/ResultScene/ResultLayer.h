/***************************************************************************
*|
*|	概要　　キャラクターレイヤー
*|　作成者　GF3 17 中田湧介
*|　作成日　2017/3/30
*|___________________________________________________________________________
****************************************************************************/

#pragma once 
/* ---- ライブラリのインクルード ---------- */
#include "cocos2d.h"
#include "Score.h"
#include "BackGround.h"

class ResultLayer :public cocos2d::Layer
{

public:
	virtual bool init();

	CREATE_FUNC(ResultLayer);


private:


	////毎フレーム呼び出される関数
	void update(float delta)override;
	int ActionCnt;//アクションカウント
	int RankingCnt;//ランキングカウント
	Score* score;
};

