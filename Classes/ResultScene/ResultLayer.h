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

class ResultLayer :public cocos2d::Layer
{

public:
	virtual bool init();

	CREATE_FUNC(ResultLayer);


private:


	////���t���[���Ăяo�����֐�
	void update(float delta)override;
	int ActionCnt;//�A�N�V�����J�E���g
	int RankingCnt;//�����L���O�J�E���g
	Score* score;
};

