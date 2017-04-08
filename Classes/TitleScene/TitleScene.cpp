/***************************************************************************
*|
*|	�T�v�@�@TitleScene�N���X�̒�`
*|�@�쐬�ҁ@GF3 17 ���c�N��
*|�@�쐬���@2017/4/08
*|___________________________________________________________________________
****************************************************************************/

/* ---- ���C�u�����̃C���N���[�h ---------- */
#include "TitleScene.h"
#include "TitleLayer.h"
#include "EventListenerGesture.h"
#include "audio\include\AudioEngine.h"
USING_NS_CC;
using namespace cocos2d::experimental;

/* ---- �����o�[�֐��̒�` ---------------- */
/***************************************************************************
*|	�T�v�@�@�V�[�����쐬����B
*|	�����@�@����
*|�@�߂�l�@�V�[���̃A�h���X
****************************************************************************/
cocos2d::Scene * TitleScene::createScene()
{
	// �V�[�����쐬����

	auto scene = Scene::create();
	// ���C���[���쐬����

	auto layer = TitleScene::create();
	// ���C���[���V�[���ɒǉ�����

	scene->addChild(layer);
	// �V�[����Ԃ�

	return scene;
}

/***************************************************************************
*|	�T�v�@�@�v���C�V�[���̃��C���[���Ăт���
*|	�����@�@����
*|�@�߂�l�@����
****************************************************************************/
bool TitleScene::init()
{
	// �e�N���X������������
	if (!Scene::init())
	{
		return false;
	}

	// �L�����N�^�[�Ăяo��
	auto title_layer = TitleLayer::create();
	// �L�����N�^�[�֘A�̃��C��
	this->addChild(title_layer);

	//BGM
	int Bgm = AudioEngine::play2d("TapSE.ogg");

	//BGM���[�v�Đ�
	AudioEngine::setLoop(Bgm, true);

}

bool TitleScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent)
{
	//���ʉ�
	int id = AudioEngine::play2d("TapSE.ogg");
	return false;
}
