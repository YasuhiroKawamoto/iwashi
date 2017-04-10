/***************************************************************************
*|
*|	�T�v�@�@���U���g���C���[
*|�@�쐬�ҁ@GS2 16 ���c�N��
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
	score->ScoreIndicate(5);
	
	// �^�b�`�C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(ResultLayer::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(ResultLayer::onTouchEnded, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	////���t���[���A�b�v�f�[�g�֐����Ăт���
	this->scheduleUpdate();


	return true;
}

/***************************************************************************
*|	�T�v�@	�^�b�`���ꂽ��
*|	�����@�@����
*|�@�߂�l�@����
****************************************************************************/
bool ResultLayer::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent)
{
	//�X�R�A�̃A�N�V�����̑��x
	Score::ScoreActionSpd = 0.5f;
	ActionCnt++;
	return true;
}
/***************************************************************************
*|	�T�v�@	�^�b�`�͂Ȃ��ꂽ��
*|	�����@�@����
*|�@�߂�l�@����
****************************************************************************/
void ResultLayer::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * pEvent)
{
	//�X�R�A�̃A�N�V�����̑��x
	Score::ScoreActionSpd = 1.0f;
}

/***************************************************************************
*|	�T�v�@	�X�R�A�̃A�N�V�����֐����Ăт����@
*|	�����@�@����
*|�@�߂�l�@����
****************************************************************************/
void ResultLayer::update(float date)
{
	//��b���ƂɃX�R�A�̃A�N�V�������Ă�
	ActionCnt++;
	if ((ActionCnt >= 60)&&(RankingCnt >= 0))
	{
		score->ScoreAction(RankingCnt);
		ActionCnt = 0;
		RankingCnt--;
	}
}