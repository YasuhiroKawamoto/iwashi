#include "PlayScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "ResultScene\\ResultScene.h"




#include "ResultScene\ResultScene.h"

#include "audio\include\AudioEngine.h"


USING_NS_CC;

using namespace cocos2d::experimental;
using namespace cocostudio::timeline;

const float TIME_LIMIT_SECOND = 900;//�c�莞�ԁi�U�O�b�j
const float DECREASE_TIME = 0.5;//�����Ă�������
const int RETURN_TIME = 30;//fps�𕪒P�ʂɖ߂�
const float SCALSE_SIZE = 5.0;//������傫������T�C�Y
//���x���̍����ƕ�
const int TIME_LABEL_WIDTH = 350;
const int TIME_LABEL_HEIGHT = 70;
const int TEXT_TIME_LABEL_WIDTH = 550;
const int TEXT_TIME_LABEL_HEIGHT = 70;

const int SPRIITE_SIZE = 256;
const int SCREEN_WIDTH = 960;


const int ANIMETION�QPUTTURNS = 3;
const int ANIMETION�QFRAME = 30;


enum PLAYER
{
	PLAYER_1,
	PLAYER_2
};

//�R���X�g���N�^
Play::Play()
	:m_timer(TIME_LIMIT_SECOND)
	,m_TimeLabel(NULL)
	,m_flag(true)
	,m_CountFlag(true)
	, m_TotalScore(321)
{
}
//�f�X�g���N�^�[
Play::~Play()
{
	CC_SAFE_RELEASE_NULL(m_TimeLabel);//m_TimeLabel��j��
}
//----------------------------------------------------------------------
//! @brief createScene
//!
//! @param[in] �Ȃ�
//!
//! @return  scene
//----------------------------------------------------------------------

Scene* Play::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Play::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
// ===========================================
// @>�T�@�v:�^�b�`���W�ɉ��g�𐶐�
//
// @>���@��:�^�b�`���W(Vec2), �ǂ����̃v���C���[����������(int)
//
// @>�߂�l:�Ȃ�
// ===========================================
void  Play::CreateWave(Vec2 pos, int player)
{

	// �摜�t�@�C���̓ǂݍ���
	m_wave[player] = Sprite::create("Images\\wave_anm.png");

	// �ŏ��̃p�^�[���摜��؂蔲��
	m_wave[player]->setTextureRect(Rect(0, 0, SPRIITE_SIZE, SPRIITE_SIZE));

	// ���W���^�b�`���W�ɕύX
	m_wave[player]->setPosition(Vec2(pos.x, pos.y));

	// �T�C�Y�����������ɒ���
	m_wave[player]->setScale(0.4f);


	// �V�[���ɒǉ�
	this->addChild(m_wave[player]);
}


// ===========================================
// @>�T�@�v:���g����ʊO�ɏo����Ĕ��ˉ\�ɂ���
//
// @>���@��:�Ȃ�
//
// @>�߂�l:�Ȃ�
// ===========================================
void Play::Reload()
{
	// ��ʊO�ɏo���甭�ˏ�Ԃ���
	if (m_wave[PLAYER_1] != nullptr)
	{
		if (m_wave[PLAYER_1]->getPosition().x > SCREEN_WIDTH)
		{
			canShoot_1p = true;
		}
	}

	if (m_wave[PLAYER_2] != nullptr)
	{
		if (m_wave[PLAYER_2]->getPosition().x < 0)
		{
			canShoot_2p = true;
		}
	}
}

// ===========================================
// @>�T�@�v:�A�j���[�V�����̍X�V
//
// @>���@��:�Ȃ�
//
// @>�߂�l:�Ȃ�
// ===========================================
void Play::AnimationUpdate()
{
	// �A�j���\�V�����J�E���g�̑���
	m_animation_cnt++;

	// �ő�90�t���[���ݒ�
	m_animation_cnt %= 90;

	// 2�̉��g�̃X�v���C�g�����ꂼ��؂�ւ���
	for (int i = 0; i < 2; i++)
	{
		if (m_wave[i] != nullptr)
		{
			m_wave[i]->setTextureRect(Rect(0, (m_animation_cnt / 30)*SPRIITE_SIZE, SPRIITE_SIZE, SPRIITE_SIZE));
		}
	}
}


// ===========================================
// @>�T�@�v:�i�b��I�j�����蔻��
//
// @>���@��:�Ȃ�
//
// @>�߂�l:bool(true:��������)
// ===========================================
bool Play::Collision()
{
	
	if (iwashi != nullptr)
	{
		// ��X�v���C�g�̃o�E���f�B���O�{�b�N�X���擾
		r_iwashi = iwashi->getBoundingBox();


		// 1P���g�̃o�E���f�B���O�{�b�N�X���擾
		
		isHit1 = false;
		if (m_wave[PLAYER_1] != nullptr)
		{
			r_wave1 = m_wave[PLAYER_1]->getBoundingBox();
		}

		// 1P���g�̃o�E���f�B���O�{�b�N�X���擾
	
		isHit2 = false;
		if (m_wave[PLAYER_2] != nullptr)
		{
			r_wave2 = m_wave[PLAYER_2]->getBoundingBox();
		}

		// ��`���m�œ����蔻����擾
		isHit1 = r_iwashi.intersectsRect(r_wave1);
		isHit2 = r_iwashi.intersectsRect(r_wave2);

		// �ǂ���Ƃ��̃X�v���C�g�Ɠ��������Ƃ�
		if (isHit1 && isHit2)
		{
			isHit1 = false;
			isHit2 = false;
			return true;
		}
	}
	return false;
}

void Play::GetIwashi()
{
	// SE
	AudioEngine::play2d("Sounds\\Splash.ogg");

	// �쐬�����p�[�e�B�N���̃v���p�e�B���X�g��ǂݍ���
	ParticleSystemQuad* particle = ParticleSystemQuad::create("Images\\kirakira.plist");
	//�p�[�e�B�N���̃������[���[�N����i���d�v�j
	particle->setAutoRemoveOnFinish(true);
	// �p�[�e�B�N�����J�n
	particle->resetSystem();
	// �p�[�e�B�N����\������ꏊ�̐ݒ�
	particle->setPosition(480, 500);
	// �p�[�e�B�N����z�u
	this->addChild(particle);


	// �p�[�e�B�N���ɃA�N�V����
	DelayTime* delay2 = DelayTime::create(1.5f);
	RemoveSelf* remove2 = RemoveSelf::create();
	Sequence* sequence_particle = Sequence::create(delay2, remove2, nullptr);
	particle->runAction(sequence_particle);
	particle = nullptr;

	// ���ɃA�N�V����
	iwashi->stopActionByTag(100);
	iwashi->setAnchorPoint(Vec2(0.5f, 0.5f));
	MoveTo* move = MoveTo::create(0.25f, Vec2(480, 50));		// �o�O���Ă�
	ScaleTo* scale = ScaleTo::create(0.2f, 2.5f);
	Spawn* spawn = Spawn::create(scale, move, nullptr);
	DelayTime* delay = DelayTime::create(1.5f);
	RemoveSelf* remove = RemoveSelf::create();
	CallFunc* call = CallFunc::create(CC_CALLBACK_0(Play::IwashiDelete,this));
	Sequence* sequence_iwahi = Sequence::create(spawn, delay, remove, call, nullptr);
	iwashi->runAction(sequence_iwahi);
	
	// �X�v���C�g�̉��
	if (m_wave[PLAYER_1] != nullptr)
	{
		m_wave[PLAYER_1]->runAction(RemoveSelf::create());
		m_wave[PLAYER_1] = nullptr;
	}
	if (m_wave[PLAYER_2] != nullptr)
	{
		m_wave[PLAYER_2]->runAction(RemoveSelf::create());
		m_wave[PLAYER_2] = nullptr;
	}

	// ���ˏ�Ԃ̃��Z�b�g
	canShoot_1p = true;
	canShoot_2p = true;
}
// ===========================================
// @>�T�@�v:�X�R�A�̌v�Z
//
// @>���@��:�e��X�R�A�i�R�i�K�̈�A���݂̃X�R�A�A�{�[�i�X�X�R�A�j
//
// @>�߂�l:���v�̃X�R�A
// ===========================================

int Play::SumScore(int score)
{

	return m_TotalScore += score;
}

//----------------------------------------------------------------------
//! @brief RenderTimeLabel
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Play::RenderTimeLabel()
{
	//���S���W
	auto size = Director::getInstance()->getWinSize();
	//�^�C�}�[ ���x���̒ǉ�
	int second = static_cast < int >(m_timer); // int �^ �� �L���X�g ����
	auto timeLabel = Label::createWithSystemFont(StringUtils::toString(second), "Default Font", 16);
	timeLabel->setColor(Color3B::BLACK);
	timeLabel->setPosition(Vec2(700,570));
	timeLabel->setScale(SCALSE_SIZE);
	this->setTimeLabel(timeLabel);
	this->addChild(m_TimeLabel);
}

//----------------------------------------------------------------------
//! @brief RendertextTimeLabel
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------

void Play::RendertextTimeLabel()
{
	//���S���W
	auto size = Director::getInstance()->getWinSize();

	// �^�C�}�[�w�b�_�[�̒ǉ�
	auto textTimeLabel = Label::createWithSystemFont(" TIME", "Default Font", 16);
	textTimeLabel->setColor(Color3B::BLACK);
	textTimeLabel->setPosition(Vec2(500, 570));
	textTimeLabel->setScale(SCALSE_SIZE);
	this->addChild(textTimeLabel);
}
//----------------------------------------------------------------------
//! @brief UpadateTime
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------

void Play::UpadateTime()
{
	
	// �c�� �b �� �� ���炷
	m_timer -= DECREASE_TIME;
	// �c�� �b �� �� �\�� �� �X�V ����
	int second = static_cast < int >(m_timer / RETURN_TIME); // int �^ �� �L���X�g ����
	m_TimeLabel->setString(StringUtils::toString(second));

}

void Play::FormIwasHi()
{

	for (int i = 0; i < 10; i++)
	{
		if(iwashies[i] != nullptr)
		iwashies[i] = Iwashi::GenerateIwashi();

		// �C���V�̃X�v���C�g���V�[���ɒǉ�
	//	this->addChild(iwashies[i]->GetSprite());
		break;
	}

	MoveTo* MoveByAction = MoveTo::create(10.0, Vec2(-1000, 340));
	DelayTime* DelayTimeAction = DelayTime::create(0);
	Sequence* SpawnAction = Sequence::create(DelayTimeAction, MoveByAction, nullptr);
	SpawnAction->setTag(100);
	iwashi = Sprite::create("Images\\PlaySeen.png");
	iwashi->setTextureRect(Rect(0,0,150,50));
	iwashi->setPosition(1200, 340);
	this->addChild(iwashi);
	iwashi->runAction(SpawnAction);
	m_flag = false;
	for (int i = 0; i < 10; i++)
	{
		if (iwashies[i] != nullptr)
		{
			iwashies[i] = Iwashi::GenerateIwashi();

			// �C���V�̃X�v���C�g���V�[���ɒǉ�

			this->addChild(iwashies[i]->GetSprite());
		}
		break;
	}


}
void Play::DeletIwashi()
{
	//��̍��W��0�ȉ���������
	if (iwashi->getPositionX() <= 0)
	{
		iwashi->removeFromParent();//����폜
		iwashi = nullptr;
		m_flag = true;
	}
}
//----------------------------------------------------------------------
//! @brief init
//!
//! @param[in] �Ȃ�
//!
//! @return true or false
//----------------------------------------------------------------------

// on "init" you need to initialize your instance
bool Play::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    
	// �ϐ�������==============================
	m_animation_cnt = 0;

	canShoot_1p = true;
	canShoot_2p = true;

	// ���g
	for (int i = 0; i < 2; i++)
	{
		m_wave[i] = nullptr;
	}

	// �C���V
	for (int i = 0; i < 10; i++)
	{
		iwashies[i] = nullptr;
	}

	iwashi = nullptr;

	// �w�i===================================
	m_bg = Sprite::create("Images\\BG.png");
	m_bg->setAnchorPoint(Vec2(0, 0));
	this->addChild(m_bg);

	// TIME�`��
	RenderTimeLabel();
	RendertextTimeLabel();

	// update���Ăяo���ݒ�
	this->scheduleUpdate();

	// �C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();

	// �C�x���g���X�i�[�Ɋe�R�[���o�b�N�֐����Z�b�g����
	listener->onTouchBegan = CC_CALLBACK_2(Play::onTouchBegan, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	
	// SE�̃v�����[�h
	AudioEngine::preload("Sounds\\Sonic.ogg");
	AudioEngine::preload("Sounds\\Splash.ogg");

	// BGM�Đ�
	bgm_play = AudioEngine::play2d("Sounds\\SeenBGM.ogg", true);

	FormIwasHi();//��̐���

		//////////////////////////////////////////
	
    return true;
}
//----------------------------------------------------------------------
//! @brief update(���t���[���Ăяo�����update�֐�)
//!
//! @param[in] �Ȃ�
//!
//! @return 
//----------------------------------------------------------------------
void Play::update(float delta)
{

	if (m_flag==true)
	{

		FormIwasHi();

		DeletIwashi();//�񂪉�ʊO�ɏo����j��
	}
	// �A�j���[�V�����X�V
	AnimationUpdate();

	// ��ʊO�ɏo���甭�ˏ�Ԃ���
	Reload();

	// !!!======!!! �b��I !!!======!!! //
	// �����蔻��()
	if (Collision())
	{
		// ��Q�b�g
		GetIwashi();
	}

	//�c�莞�Ԃ̍X�V
	UpadateTime();

	//�X�R�A�̕`��
	ScoreIndicate(m_TotalScore);

	//�c��^�C����0�ɂȂ����烊�U���g��ʂɍs��
	///////////////////////////////////////////

	if (m_timer <= 0)
	{
		// BGM��~
		AudioEngine::stop(bgm_play);
		AudioEngine::uncache("Sounds\\SeenBGM.ogg");


		//auto director = Director::getInstance();

		//// create a scene. it's an autorelease object
		//auto scene = ResultScene::createScene();

		//// run
		//director->runWithScene(scene);
		// ���̃V�[�����쐬����
		Scene* nextScene = ResultScene::create();
		// ���̃V�[���Ɉڍs
		_director->replaceScene(nextScene);
	}

}
//----------------------------------------------------------------------
//! @brief onTouchBegan
//!
//! @param[in] cocos2d::Touch* touch, cocos2d::Event* unused_event
//!
//! @return true or false
//----------------------------------------------------------------------
bool Play::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event)
{
	// �^�b�`���W���擾
	Vec2 touch_pos = touch->getLocation();

	// y���W�ɐ�����t����
	if (touch_pos.y > 400)
	{
		touch_pos.y = 400;
	}

	// ��ʔ�����荶���^�b�v���ꂽ�Ƃ��̏���
	if (touch_pos.x < (SCREEN_WIDTH / 2))
	{
		// ���ˉ\��Ԃ̎�
		if (canShoot_1p)
		{
			Play::CreateWave(Vec2(0, touch_pos.y), PLAYER_1);
			m_wave[0]->setFlippedX(true);

			// �A�j���[�V�������Z�b�g
			m_animation_cnt = 0;

			// ���˂�s��
			canShoot_1p = false;

			// ��ʊO�܂ŉ��g�ړ�
			m_wave[PLAYER_1]->runAction(MoveBy::create(4.0f, Vec3(SCREEN_WIDTH + SCREEN_WIDTH, 0, 0)));

			// SE�Đ�
			se_wave = AudioEngine::play2d("Sounds\\Sonic.ogg");

			return true;
		}
	}

	else // ��ʔ������E���^�b�v���ꂽ�Ƃ��̏���
	{
		// ���ˉ\��Ԃ̎�
		if (canShoot_2p)
		{
			Play::CreateWave(Vec2(SCREEN_WIDTH, touch_pos.y), PLAYER_2);

			// �A�j���[�V�������Z�b�g
			m_animation_cnt = 0;

			// ���˂�s��
			canShoot_2p = false;

			// ��ʊO�܂ŉ��g�ړ�
			m_wave[PLAYER_2]->runAction(MoveBy::create(4.0f, Vec3(-(SCREEN_WIDTH + SCREEN_WIDTH), 0, 0)));

			// SE�Đ�
			se_wave = AudioEngine::play2d("Sounds\\Sonic.ogg");

			return true;
		}
	}
	return false;
}

void Play::ScoreIndicate(int Score)
{
	int j;

	//����������������
	Digit = 1;
	//�Ώۂ̃X�R�A��ۑ�����
	Score2 = Score;

	//�X�R�A����������̂����߂�
	//�������Ȃ��Ȃ�܂�10�ŏ��@����

	//�X�R�A��0����Ȃ��Ƃ�
	if ((Score - Score2 != Score))
	{
		while (Score - Score2 != Score)
		{
			Score2 /= 10;
			//���񃋁[�v�������J�E���g����
			Digit *= 10;

		}
		//�����ɂȂ�܂ł��������A������m�肽���̂�10�Ŋ���
		Digit /= 10;
	}




	//�Ώۂ̃X�R�A��ۑ�����
	Score2 = Score;

	j = 0;
	while (Digit != 0)
	{
		//�c��̒l��0�ɂȂ鎞�A�uDigit���̒l�����߂�v�ŃG���[�ɂȂ�
		//�c��̒l��0�ɂȂ鎞�A��������0��\������
		if (Score2 <= 0)
		{
			//Digit���̒l�����߂�
			Score = 0;
		}
		else
		{
			//Digit���̒l�����߂�
			Score /= Digit;
		}
		//SCORE�̃X�v���C�g�̍쐬
		m_ScoreImage= Sprite::create("Images\\Score.png");
		m_ScoreImage->setPosition(Vec2(100, 570));
		this->addChild(m_ScoreImage);
		//�����̃X�v���C�g���쐬����
		s_Number = Sprite::create("Images\\Number.png");
		//���N�g��ݒ肷��
		s_Number->setTextureRect(Rect(Score * 64, 0, 64, 64));

		if (m_CountFlag==true)
		{
			//���W
			s_Number->setPosition(Vec2(250 + 64 * j, 570));
			this->addChild(s_Number);
		}
		//�X�R�A���狁�߂��l������
		Score2 -= Score * Digit;
		//����Digit-1��������
		Digit /= 10;
		j++;
	}
	m_CountFlag = false;
}

//���ߊl������폜����֐�
void Play::IwashiDelete()
{
	iwashi = nullptr;
}

