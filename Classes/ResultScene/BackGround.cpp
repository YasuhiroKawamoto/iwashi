/***************************************************************************
*|
*|	�T�v�@�w�i�N���X�̐錾
*|�@�쐬�ҁ@GS2 16 ���c�N��
*|�@�쐬���@2017/4/07
*|___________________________________________________________________________
****************************************************************************/
/* ---- ���C�u�����̃C���N���[�h ---------- */
#include "BackGround.h"
#include "Score.h"
USING_NS_CC;

bool BackGround::init()
{
	if (!Node::init()) {

		return false;
	}

	//�w�i
	s_BackGround = Sprite::create("Images\\ResultTexture.png");
	s_BackGround->setPosition(Vec2(480.0f, 320.0f));
	s_BackGround->setScale(1.5f, 1.5f);
	this->addChild(s_BackGround);

	// �쐬�����p�[�e�B�N���̃v���p�e�B���X�g��ǂݍ���
	ParticleSystemQuad* particle = ParticleSystemQuad::create("Images\\particle_texture.plist");
	//�p�[�e�B�N���̃������[���[�N����i���d�v�j
	particle->setAutoRemoveOnFinish(true);
	// �p�[�e�B�N�����J�n
	particle->resetSystem();
	// �p�[�e�B�N����\������ꏊ�̐ݒ�
	particle->setPosition(480, -100);
	// �p�[�e�B�N����z�u
	this->addChild(particle);
	////���t���[���A�b�v�f�[�g�֐����Ăт���
	this->scheduleUpdate();


	//�^�b�`
	s_touch = Sprite::create("Images\\TouchImage.png");
	s_touch->setPosition(Vec2(480.0f,100.f));
	s_touch->setVisible(false);
//	s_touch->setScale
	this->addChild(s_touch);
	Opacity = 0;
	return true;
}

void BackGround::update(float data)
{
	if (Score::SceneFlag == true)
	{
		s_touch->setVisible(true);
		Opacity += 2;
		s_touch->setOpacity(Opacity);
	}
}
