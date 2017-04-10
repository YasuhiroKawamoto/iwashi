//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @File  iwashi.cpp
//!
//! @Brief  �C���V�N���X�̃\�[�X�[�t�@�C��
//!
//! @Date   2017/04/10
//!
//! @Author �͖{���G
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
// @>�T�@�v:��𐶐�����֐�
//
// @>���@��:�Ȃ�
//
// @>�߂�l:����:true ���s:fasle
// ===========================================
Iwashi* Iwashi::GenerateIwashi()
{
	int lr = rand() % 2;		// ���ɏo�邩�E�ɏo�邩(0:��, 1:�E)
	int puttern = rand() % 3;
	Vec2 appear_pos;
	MoveBy* move;

	if (lr == LEFT)
	{
		appear_pos = Vec2(-40, rand() % 300 + 100);		// 100�ȏ�300�ȉ��̍���
		move = MoveBy::create(7.0f - puttern, Vec2(1300, 0));
	}
	else if (lr == RIGHT)
	{
		appear_pos = Vec2(1000, rand() % 300 + 100);	// 100�ȏ�300�ȉ��̍���
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
// @>�T�@�v:�C���V�̃R���X�g���N�^
//
// @>���@��:�Ȃ�
// ===========================================
Iwashi::Iwashi(int putturn, cocos2d::Vec2 pos)
{
	// ����������f�[�^�ɑ��
	m_pattern = putturn;
	m_sprIwashi = Sprite::create("Images/PlayScene.png");
	m_sprIwashi->setPosition(pos);

	switch (m_pattern)
	{
		// ��Ԃ���������
	case 0:
		if (m_sprIwashi != nullptr)
		{
			m_sprIwashi->setTextureRect(Rect(0, 0, 150, 42));
			m_score = 1;
		}
		break;
		// �����炢�̈�
	case 1:
		if (m_sprIwashi != nullptr)
		{
			m_sprIwashi->setTextureRect(Rect(0, 42, 150, 83));
			m_score = 3;
		}

		break;
		// ��ԑ傫����
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