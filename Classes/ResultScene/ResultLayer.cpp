/***************************************************************************
*|
*|	�T�v�@�@���U���g���C���[
*|�@�쐬�ҁ@GF3 17 ���c�N��
*|�@�쐬���@2017/4/07
*|___________________________________________________________________________
****************************************************************************/
/* ---- ���C�u�����̃C���N���[�h ---------- */
#include "ResultLayer.h"

USING_NS_CC;

bool ResultLayer::init()
{
	if (!Layer::init()) {

		return false;

	}

	//���C���[�Ƀm�[�h���W��
	BackGround* background = BackGround::create();
	this->addChild(background);

	score = Score::create();
	this->addChild(score);

	//�J�E���g������������
	ActionCnt = 0;
	RankingCnt = 5;
	
	
	//�����L���O�擾
	score->sortAllChildren();
	//�����L���O�ύX
	score->RankingSort();
	//�����L���O�ۑ�
	score->ScoreResister();
	//�����L���O�X�R�A�̐ݒ�
	for (int i = 0; i < MAX_SCORE; i++)
	{
		score->ScoreIndicate(i);
	}
	//����̃X�R�A�̐ݒ�
	score->ScoreIndicate(ScoreNumber);
	

	////���t���[���A�b�v�f�[�g�֐����Ăт���
	this->scheduleUpdate();


	return true;
}


/***************************************************************************
*|	�T�v�@�@
*|	�����@�@����
*|�@�߂�l�@����
****************************************************************************/
void ResultLayer::update(float date)
{
	//��b���ƂɃX�R�A�̃A�N�V�������Ă�
	ActionCnt++;
	if ((ActionCnt == 60)&&(RankingCnt >= 0))
	{
		score->ScoreAction(RankingCnt);
		ActionCnt = 0;
		RankingCnt--;
	}
}