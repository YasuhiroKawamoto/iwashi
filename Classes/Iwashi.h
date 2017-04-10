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

	Iwashi(int putturn, cocos2d::Vec2 pos);		// 非公開コンストラクタ
public:
	cocos2d::Sprite* GetSprite()
	{
		return m_sprIwashi;
	}
	static Iwashi GenerateIwashi();
	
};