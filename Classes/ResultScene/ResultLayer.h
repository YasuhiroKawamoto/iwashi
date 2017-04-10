/***************************************************************************
*|
*|	�T�v�@�@ResultLayer
*|�@�쐬�ҁ@GS2 16 ���c�N��
*|�@�쐬���@2017/4/08
*|___________________________________________________________________________
****************************************************************************/

#pragma once 
/* ---- ���C�u�����̃C���N���[�h ---------- */
#include "cocos2d.h"
#include "Score.h"
#include "BackGround.h"
#include "EventListenerGesture.h"

class ResultLayer :public cocos2d::Layer
{

public:
	virtual bool init();

	CREATE_FUNC(ResultLayer);


private:
	//�^�b�`���ꂽ��
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
	//�^�b�`�͂Ȃ��ꂽ��
	void onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * pEvent);


	////���t���[���Ăяo�����֐�
	void update(float delta)override;
	int ActionCnt;//�A�N�V�����J�E���g
	int RankingCnt;//�����L���O�J�E���g
	Score* score;
};

