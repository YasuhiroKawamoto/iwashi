/***************************************************************************
*|
*|	概要　　背景クラスの宣言
*|　作成者　GF3 17 中田湧介
*|　作成日　2017/04/07
*|___________________________________________________________________________
****************************************************************************/
#pragma once
/* ---- ライブラリのインクルード ---------- */
#include "cocos2d.h"


class BackGround :public cocos2d::Node
{
public:
	virtual bool init();

	CREATE_FUNC(BackGround);




	//数
	cocos2d::Sprite* s_BackGround;




private:

};
