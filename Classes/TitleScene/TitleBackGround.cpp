#include "TitleBackGround.h"

USING_NS_CC;
bool TitleBackGround::init()
{
	if (!Node::init())
	{
		return false;
	}
	return true;

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
}
