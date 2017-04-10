//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @File  iwashi.h
//!
//! @Brief  �C���V�N���X�̃w�b�_�[�t�@�C��
//!
//! @Date   2017/04/10
//!
//! @Author �͖{���G
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once

#include "cocos2d.h"

class Iwashi
{
private:
	cocos2d::Sprite* m_sprIwashi;				// �X�v���C�g
	bool isFisshed;								// �ނ������ǂ���

	Iwashi(int putturn, cocos2d::Vec2 pos);		// ����J�R���X�g���N�^
public:
	cocos2d::Sprite* GetSprite()
	{
		return m_sprIwashi;
	}
	static Iwashi GenerateIwashi();
	
};