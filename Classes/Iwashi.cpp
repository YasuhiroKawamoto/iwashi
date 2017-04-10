//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @File  iwashi.cpp
//!
//! @Brief  イワシクラスのソースーファイル
//!
//! @Date   2017/04/10
//!
//! @Author 河本恭宏
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//
#include "cocos2d.h"

#include "Iwashi.h"

USING_NS_CC;

enum LR
{
	LEFT,
	RIGHT
};

// ===========================================
// @>概　要:鰯を生成する関数
//
// @>引　数:なし
//
// @>戻り値:成功:true 失敗:fasle
// ===========================================
Iwashi* Iwashi::GenerateIwashi()
{
	int lr = rand() % 2;		// 左に出るか右に出るか(0:左, 1:右)
	int puttern = rand() % 3;
	Vec2 appear_pos;
	MoveBy* move;

	if (lr == LEFT)
	{
		appear_pos = Vec2(-40, rand() % 300 + 100);		// 100以上300以下の高さ
		move = MoveBy::create(7.0f - puttern, Vec2(1300, 0));
	}
	else if (lr == RIGHT)
	{
		appear_pos = Vec2(1000, rand() % 300 + 100);	// 100以上300以下の高さ
		move = MoveBy::create(7.0f - puttern, Vec2(-1300, 0));
	}

	Iwashi* iwashi = new Iwashi(puttern, appear_pos);
	iwashi->SetAction(move);
	iwashi->SetUsingFlag(true);
	if (lr == LEFT)
	{
		iwashi->GetSprite()->setFlippedX(true);
	}



	return iwashi;
}


// ===========================================
// @>概　要:イワシのコンストラクタ
//
// @>引　数:なし
// ===========================================
Iwashi::Iwashi(int putturn, cocos2d::Vec2 pos)
{
	// 引数からをデータに代入
	m_pattern = putturn;
	m_sprIwashi = Sprite::create("Images/PlayScene.png");
	m_sprIwashi->setPosition(pos);

	switch (m_pattern)
	{
		// 一番い小さい鰯
	case 0:
		if (m_sprIwashi != nullptr)
		{
			m_sprIwashi->setTextureRect(Rect(0, 0, 150, 42));
			m_score = 1;
		}
		break;
		// 中くらいの鰯
	case 1:
		if (m_sprIwashi != nullptr)
		{
			m_sprIwashi->setTextureRect(Rect(0, 42, 150, 83));
			m_score = 3;
		}

		break;
		// 一番大きい鰯
	case 2:
		if (m_sprIwashi != nullptr)
		{
			m_sprIwashi->setTextureRect(Rect(0, 155, 150, 85));
			m_score = 5;
		}
		break;
	}
}

Iwashi::Iwashi()
	:m_isFisshed(false),
	m_sprIwashi(nullptr),
	m_isUsing(false)
	

{

}