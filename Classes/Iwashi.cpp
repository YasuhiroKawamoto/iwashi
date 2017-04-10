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

// ===========================================
// @>�T�@�v:��𐶐�����֐�
//
// @>���@��:�Ȃ�
//
// @>�߂�l:����:true ���s:fasle
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
// @>�T�@�v:�C���V�̃R���X�g���N�^
//
// @>���@��:�Ȃ�
// ===========================================
Iwashi::Iwashi(int putturn, cocos2d::Vec2 pos)
{
	// ����������f�[�^�ɑ��
	m_pattern = putturn;
	m_sprIwashi = Sprite::create("Images\\PlayScene");


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
{

}