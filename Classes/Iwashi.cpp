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

// ===========================================
// @>概　要:鰯を生成する関数
//
// @>引　数:なし
//
// @>戻り値:成功:true 失敗:fasle
// ===========================================
Iwashi* Iwashi::GenerateIwashi()
{
	Iwashi* iwashi = new Iwashi(1, Vec2(1000, 400));
	return iwashi;
}

void Iwashi::Update()
{

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
	m_sprIwashi = Sprite::create("Images\\PlayScene");


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
{

}