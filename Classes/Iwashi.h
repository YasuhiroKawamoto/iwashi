//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @File  iwashi.h
//!
//! @Brief  イワシクラスのヘッダーファイル
//!
//! @Date   2017/04/10
//!
//! @Author 河本恭宏
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

#include "cocos2d.h"

class Iwashi
{
private:
	cocos2d::Sprite* m_sprIwashi;				// スプライト
	bool isFisshed;								// 釣ったかどうか
	cocos2d::Rect m_bounding_box;
	int m_pattern;								// イワシのパターン
	int m_score;								// イワシの点数

	Iwashi(int putturn, cocos2d::Vec2 pos);		// 非公開コンストラクタ
public:
	cocos2d::Sprite* GetSprite()
	{
		if (m_sprIwashi != nullptr)
		{
			return m_sprIwashi;
		}
	}
	Iwashi();
	static Iwashi* GenerateIwashi();
	void Update();
private:
	void setAction();
	
};