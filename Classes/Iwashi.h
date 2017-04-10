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
	bool m_isFisshed;								// 釣ったかどうか
	bool m_isUsing;								// 現在使用中かどうか
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

	// デフォルトコンストラクタ 
	Iwashi();
	static Iwashi* GenerateIwashi();

	// 使用中フラグセット
	void SetUsingFlag(bool isUsing)
	{
		m_isUsing = isUsing;
	}

	// 使用中フラグゲット
	bool GetUsingFlag()
	{
		return m_isUsing;
	}
	void Update();
private:
	void setAction();
	
};