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
	Iwashi* iwashi = new Iwashi(1, Vec2(0, 0));
	return iwashi;
}

// ===========================================
// @>�T�@�v:�C���V�̃R���X�g���N�^
//
// @>���@��:�Ȃ�
// ===========================================
Iwashi::Iwashi(int putturn, cocos2d::Vec2 pos)
{
	m_pattern = putturn;

}

Iwashi::Iwashi()
{

}