/***************************************************************************
*|
*|	�T�v�@�@�X�R�A�N���X�̐錾
*|�@�쐬�ҁ@GS2 16 ���c�N��
*|�@�쐬���@2017/4/08
*|___________________________________________________________________________
****************************************************************************/
#pragma once
/* ---- ���C�u�����̃C���N���[�h ---------- */
#include "cocos2d.h"

enum ScoreNumber
{
	First,
	Scound,
	Third,
	Fourth,
	Fifth,
	ScoreNumber
};
//�����L���O��
const int MAX_SCORE = 5;

class Score :public cocos2d::Node
{
public:
	virtual bool init();

	CREATE_FUNC(Score);


	//�X�R�A���擾����
	void ScoreAcquisition();

	//�X�R�A�̃����L���O�𒲂ׂ�
	void RankingSort();

	//�X�R�A�̕ۑ�
	void ScoreResister();

	//�X�R�A�̃��N�g��ݒ�E�`��
	void ScoreIndicate(int Ranking);

	//�X�R�A�̃A�N�V����
	void ScoreAction(int Ranking);

	//��
	cocos2d::Sprite* s_Number;

	//�X�R�A�̌���
	int Digit;
	//����̃X�R�A
	int m_Score;


	//�����L���O�X�R�A
	int RankingScore[MAX_SCORE];

	bool static SceneFlag;	//�V�[���؂�ւ����Ă�������

private:
	cocos2d::UserDefault* userDefault;
	const float SCREEN_SIZE_WIDTH = 980.0f; //��ʂ̒���
	const float SCREEN_SIZE_LENGTH = 640.0f; //��ʂ̒���
	int ScoreNumber; //���������߂�ۂɑ�����Ďg�p���Ďg���ϐ�
	int ScoreNumber2;
	Node* m_NodeNumber[MAX_SCORE + 1];
};

