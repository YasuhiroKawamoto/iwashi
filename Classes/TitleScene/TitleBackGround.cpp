#include "TitleBackGround.h"

USING_NS_CC;
bool TitleBackGround::init()
{
	if (!Node::init())
	{
		return false;
	}


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

	//�^�b�`
	s_touch = Sprite::create("Images\\TouchImage.png");
	s_touch->setPosition(Vec2(480.0f, 100.0f));
	this->addChild(s_touch);
	Opacity = 0;
	this->scheduleUpdate();

	return true;
}

void TitleBackGround::update(float data)
{

		Opacity += 2;
		s_touch->setOpacity(Opacity);
	
}