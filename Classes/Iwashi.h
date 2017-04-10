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
	cocos2d::MoveBy* m_action;					// 実行すべきアクション
	std::string m_dummy;
	bool m_isFisshed;							// 釣ったかどうか
	bool m_isUsing;								// 現在使用中かどうか


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
		return nullptr;
	}

	void DeleteSprite()
	{
		m_sprIwashi = nullptr;
	}

	// デフォルトコンストラクタ 
	Iwashi();

	// イワシの動的生成
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

	// 判定フラグセット
	void SetFisshed(bool isFisshed)
	{
		m_isFisshed = isFisshed;
	}

	// 判定フラグゲット
	bool GetFisshed()
	{
		return m_isFisshed;
	}

	// アクション取得
	cocos2d::MoveBy* GetAction()
	{
		return m_action;
	}

private:
	void SetAction(cocos2d::MoveBy* action)
	{
		m_action = action;
	}
	
};