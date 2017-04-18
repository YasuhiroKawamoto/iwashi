/***************************************************************************
*|
*|	概要　　ResultSceneクラスの宣言
*|　作成者　GS2 16 中田湧介
*|　作成日　2017/2/28
*|___________________________________________________________________________
****************************************************************************/
/* ---- 多重インクルード防止 ---------- */
#pragma once


//#ifndef __PLAYSCENE_H__
//#define __PLAYSCENE_H__

/* ---- ライブラリのインクルード ---------- */
#include "cocos2d.h"


class ResultScene : public cocos2d::Scene
{
public:
	// シーンを作成する
	static cocos2d::Scene* create(int score);
	/*void update(float date)override;*/

	// 初期化する。
	virtual bool init(int score);
private:
	//タッチされたら
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);

	//BGM
	int ResultBGM;
	int bubble;
};
//#endif // __