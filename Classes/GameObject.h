#pragma once

#include "cocos2d.h"

// �e�I�u�W�F�N�g�̃x�[�X�ƂȂ钊�ۃN���X
class GameObject
{		
protected:
	cocos2d::Vec2 m_pos;			// ���W
	cocos2d::Vec2 m_spd;			// ���x
	cocos2d::Sprite* m_sprite;		// �X�v���C�g
	int direction;					// �I�u�W�F�N�g�̌���
public:
	virtual void Update() = 0;		// �������z�֐�

};