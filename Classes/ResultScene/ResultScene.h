/***************************************************************************
*|
*|	�T�v�@�@ResultScene�N���X�̐錾
*|�@�쐬�ҁ@GS2 16 ���c�N��
*|�@�쐬���@2017/2/28
*|___________________________________________________________________________
****************************************************************************/
/* ---- ���d�C���N���[�h�h�~ ---------- */
#pragma once


//#ifndef __PLAYSCENE_H__
//#define __PLAYSCENE_H__

/* ---- ���C�u�����̃C���N���[�h ---------- */
#include "cocos2d.h"


class ResultScene : public cocos2d::Scene
{
public:
	// �V�[�����쐬����
	static cocos2d::Scene* createScene();
	/*void update(float date)override;*/
	CREATE_FUNC(ResultScene);
	// ����������B
	virtual bool init();
private:
	////�L�[�������ꂽ�Ƃ��Ăяo�����֐�
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);

	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);

	//BGM
	int ResultBGM;
	int bubble;
};
//#endif // __