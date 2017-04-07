#pragma once

#include "cocos2d.h"

// 各オブジェクトのベースとなる抽象クラス
class GameObject
{		
protected:
	cocos2d::Vec2 m_pos;			// 座標
	cocos2d::Vec2 m_spd;			// 速度
	cocos2d::Sprite* m_sprite;		// スプライト
	int direction;					// オブジェクトの向き
public:
	virtual void Update() = 0;		// 純粋仮想関数

};