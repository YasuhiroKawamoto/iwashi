/***************************************************************************
*|
*|	概要　　ResultLayer
*|　作成者　GS2 16 中田湧介
*|　作成日　2017/4/08
*|___________________________________________________________________________
****************************************************************************/

#pragma once 
/* ---- ライブラリのインクルード ---------- */
#include "cocos2d.h"
#include "Score.h"
#include "BackGround.h"
#include "EventListenerGesture.h"

class ResultLayer :public cocos2d::Layer
{

public:
	virtual bool init();

	CREATE_FUNC(ResultLayer);


private:
	//タッチされたら
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
	//タッチはなされたら
	void onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * pEvent);


	////毎フレーム呼び出される関数
	void update(float delta)override;
	int ActionCnt;//アクションカウント
	int RankingCnt;//ランキングカウント
	Score* score;
};

