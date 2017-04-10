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
#include "PlayScene.h"
#include "ResultScene\ResultScene.h"
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
	//�^�C�g���̃X�v���C�g�̍쐬
	m_TotleBG = Sprite::create("Images/TITLE.png");
	//�A���J�[�|�C���g�̐ݒ�
	m_TotleBG->setAnchorPoint(Vec2(0, 0));
	//�^�C�g���̕`��
	this->addChild(m_TotleBG);
	// �L�����N�^�[�Ăяo��
	auto title_layer = TitleLayer::create();
	// �L�����N�^�[�֘A�̃��C��
	this->addChild(title_layer);


	//BGM
	BGM = AudioEngine::play2d("Sounds/TitleBGM.mp3");
	//BGM���[�v�Đ�
	AudioEngine::setLoop(BGM, true);


	// �^�b�`�C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	return true;
}

bool TitleScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent)
{
	//BGM���I��������
	AudioEngine::stop(BGM);
	//���ʉ�
	int id = AudioEngine::play2d("Sounds/TapSE.ogg");
	// ���̃V�[�����쐬����
	Scene* nextScene = Play::create();
	// ���̃V�[���Ɉڍs
	_director->replaceScene(nextScene);

	return false;
}
