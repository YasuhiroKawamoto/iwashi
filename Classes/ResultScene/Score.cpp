/***************************************************************************
*|
*|	�T�v�@�X�R�A�N���X�̒�`
*|�@�쐬�ҁ@GS2 16 ���c�N��
*|�@�쐬���@2017/4/07
*|___________________________________________________________________________
****************************************************************************/
/* ---- ���C�u�����̃C���N���[�h ---------- */
#include "Score.h"
#include "audio\include\AudioEngine.h"

USING_NS_CC;
using namespace cocos2d::experimental;


bool  Score::SceneFlag = false;
float Score::ScoreActionSpd = 1.0f;		//�X�R�A�̃A�N�V�����̑��x


bool Score::init()
{
	if (!Node::init()) {

		return false;
	}

	m_Score = rand()%999;

	////������
	//Score::SceneFlag = false;
	//ScoreActionSpd = 1.0f;
	//���y�t�@�C����\�߃��[�h���Ă���
	AudioEngine::preload("Sounds\\SlideSE.ogg");

	
	userDefault = cocos2d::UserDefault::getInstance();


	//��Ճm�[�h���쐬����
	for (int i = 0; i < MAX_SCORE + 1; i++)
	{
		m_NodeNumber[i] = Node::create();
	}
	
	return true;
}


/***************************************************************************
*|	�T�v�@�@�����L���O���擾����
*|	�����@�@����
*|�@�߂�l�@����
****************************************************************************/
void Score::ScoreAcquisition()
{
	RankingScore[First] = userDefault->getIntegerForKey("name1");
	RankingScore[Scound] = userDefault->getIntegerForKey("name2");
	RankingScore[Third] = userDefault->getIntegerForKey("name3");
	RankingScore[Fourth] = userDefault->getIntegerForKey("name4");
	RankingScore[Fifth] = userDefault->getIntegerForKey("name5");
}


/***************************************************************************
*|	�T�v�@�@�X�R�A�̃����L���O�𒲂ׂ�
*|	�����@�@����
*|�@�߂�l�@����
****************************************************************************/
void Score::RankingSort()
{
	//����̃X�R�A�������L���O�̂ǂ��Ɉʒu���邩���߂�
	int i = Fifth;
	while ((RankingScore[i] < m_Score)&&(i > 0))
	{
		i--;
	}

	//����̃X�R�A�������L���O�ɓ����Ă���Ȃ��
	if (i != score)
	{
		//�����L���O�����ւ���
		for (int j = 2; i <= j; j--)
		{
			RankingScore[j + 1] = RankingScore[j];
		}

		//����̃X�R�A�������L���O�ɓ����
		RankingScore[i] = m_Score;
	}

	
}

/***************************************************************************
*|	�T�v�@�@�X�R�A��ۑ�����
*|	�����@�@����
*|�@�߂�l�@����
****************************************************************************/
void Score::ScoreResister()
{
	userDefault->setIntegerForKey("name1", RankingScore[First]);
	userDefault->setIntegerForKey("name2", RankingScore[Scound]);
	userDefault->setIntegerForKey("name3", RankingScore[Third]);
	userDefault->setIntegerForKey("name4", RankingScore[Fourth]);
	userDefault->setIntegerForKey("name5", RankingScore[Fifth]);
	userDefault->flush();
}


/***************************************************************************
*|	�T�v�@�@�X�R�A�̃X�v���C�g�ݒ�
*|	�����@�@����
*|�@�߂�l�@����
****************************************************************************/
void Score::ScoreIndicate(int Ranking)
{

	int j;
		//����������������
		Digit = 1;
		//�Ώۂ̃X�R�A��ۑ�����
		ScoreNumber = RankingScore[Ranking];
		ScoreNumber2 = RankingScore[Ranking];

		//����̃X�R�A�̏ꍇ
		if (Ranking == 5)
		{
			ScoreNumber = m_Score;
			ScoreNumber2 = m_Score;
		}

		//�X�R�A����������̂����߂�
		//�������Ȃ��Ȃ�܂�10�ŏ��@����
		
		//�X�R�A��0����Ȃ��Ƃ�
		if ((ScoreNumber2 - ScoreNumber != ScoreNumber2))
		{
			while (ScoreNumber2 - ScoreNumber != ScoreNumber2)
			{
				ScoreNumber /= 10;
				//���񃋁[�v�������J�E���g����
				Digit *= 10;
			
			}
			//�����ɂȂ�܂ł��������A������m�肽���̂�10�Ŋ���
			Digit /= 10;
		}


		

		//�Ώۂ̃X�R�A��ۑ�����
		ScoreNumber = RankingScore[Ranking];
		ScoreNumber2 = RankingScore[Ranking];
		//����̃X�R�A�̏ꍇ
		if (Ranking == 5)
		{
			ScoreNumber = m_Score;
			ScoreNumber2 = m_Score;
		}
		j = 0;
		while (Digit != 0)
		{
			//�c��̒l��0�ɂȂ鎞�A�uDigit���̒l�����߂�v�ŃG���[�ɂȂ�
			//�c��̒l��0�ɂȂ鎞�A��������0��\������
			if (ScoreNumber2 <= 0)
			{
				//Digit���̒l�����߂�
				ScoreNumber = 0;
			}
			else
			{
				//Digit���̒l�����߂�
				ScoreNumber /= Digit;
			}

			//�����L���O�ɂ���ĉ摜��ς���
			switch (Ranking)
			{
			case First:
				//�����̃X�v���C�g���쐬����
				s_Number = Sprite::create("Images\\Number1.png");
				break;
			case Scound:
				//�����̃X�v���C�g���쐬����
				s_Number = Sprite::create("Images\\Number2.png");
				break;
			case Third:
				//�����̃X�v���C�g���쐬����
				s_Number = Sprite::create("Images\\Number3.png");
				break;
			default:
				//�����̃X�v���C�g���쐬����
				s_Number = Sprite::create("Images\\Number.png");
				break;
			}

		
			//���N�g��ݒ肷��
			s_Number->setTextureRect(Rect(ScoreNumber * 64, 0, 64, 64));
			if ( Ranking == 5)
			{
				////���W
				s_Number->setPosition(Vec2(200 +  64 * j - SCREEN_SIZE_WIDTH, 500));
			}
			else
			{
				////���W
				s_Number->setPosition(Vec2(630 + 64 * j + SCREEN_SIZE_WIDTH, 500 - (Ranking * 82)));
			}

			//��Ճm�[�h�ɂԂ牺����
			m_NodeNumber[Ranking]->addChild(s_Number);
			this->addChild(m_NodeNumber[Ranking]);

			//�X�R�A���狁�߂��l������
			ScoreNumber2 -= ScoreNumber * Digit;
			ScoreNumber = ScoreNumber2;
			//����Digit-1��������
			Digit /= 10;
			j++;
	}
}

/***************************************************************************
*|	�T�v�@�@�X�R�A�̃A�N�V����
*|	�����@�@����
*|�@�߂�l�@����
****************************************************************************/
void Score::ScoreAction(int Ranking)
{
	//����̃X�R�A�łȂ���
	if ((Ranking > First)&&(Ranking < score))
	{
		MoveBy* action = MoveBy::create(ScoreActionSpd, Vec2(-1 * SCREEN_SIZE_WIDTH, 0.0f));
		m_NodeNumber[Ranking]->runAction(action);
	}
	//�Ō�̃����L���O��
	else if (Ranking == First)
	{
		MoveBy* action = MoveBy::create(ScoreActionSpd, Vec2(-1 * SCREEN_SIZE_WIDTH, 0.0f));
		CallFunc* action2 = CallFunc::create(CC_CALLBACK_0(Score::SceneFlagChenge,this));
		Sequence* action3 = Sequence::create(action, action2, nullptr);
		m_NodeNumber[Ranking]->runAction(action3);

	}
	else
	{
		MoveBy* action = MoveBy::create(ScoreActionSpd, Vec2(SCREEN_SIZE_WIDTH, 0.0f));
		m_NodeNumber[Ranking]->runAction(action);
	}

	int id = AudioEngine::play2d("Sounds\\SlideSE.ogg");

}

/***************************************************************************
*|	�T�v�@�@�V�[���؂�ւ����Ă��������ύX����
*|	�����@�@����
*|�@�߂�l�@����
****************************************************************************/
void Score::SceneFlagChenge()
{
	SceneFlag = true;
}


