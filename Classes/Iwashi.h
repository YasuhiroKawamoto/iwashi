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
	cocos2d::MoveBy* m_action;					// ���s���ׂ��A�N�V����
	std::string m_dummy;
	bool m_isFisshed;							// �ނ������ǂ���
	bool m_isUsing;								// ���ݎg�p�����ǂ���


	int m_pattern;								// �C���V�̃p�^�[��
	int m_score;								// �C���V�̓_��

	Iwashi(int putturn, cocos2d::Vec2 pos);		// ����J�R���X�g���N�^
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

	// �f�t�H���g�R���X�g���N�^ 
	Iwashi();

	// �C���V�̓��I����
	static Iwashi* GenerateIwashi();

	// �g�p���t���O�Z�b�g
	void SetUsingFlag(bool isUsing)
	{
		m_isUsing = isUsing;
	}

	// �g�p���t���O�Q�b�g
	bool GetUsingFlag()
	{
		return m_isUsing;
	}

	// ����t���O�Z�b�g
	void SetFisshed(bool isFisshed)
	{
		m_isFisshed = isFisshed;
	}

	// ����t���O�Q�b�g
	bool GetFisshed()
	{
		return m_isFisshed;
	}

	// �A�N�V�����擾
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