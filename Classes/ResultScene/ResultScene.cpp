/***************************************************************************
*|
*|	�T�v�@�@ResultScene�N���X�̒�`
*|�@�쐬�ҁ@GS2 16 ���c�N��
*|�@�쐬���@2017/4/08
*|___________________________________________________________________________
****************************************************************************/

/* ---- ���C�u�����̃C���N���[�h ---------- */
#include "ResultScene.h"
#include "ResultLayer.h"
#include "EventListenerGesture.h"
#include "ResultScene\Score.h"
#include "audio\include\AudioEngine.h"
#include "TitleScene\TitleScene.h"
USING_NS_CC;
using namespace cocos2d::experimental;

/* ---- �����o�[�֐��̒�` ---------------- */
/***************************************************************************
*|	�T�v�@�@�V�[�����쐬����B
*|	�����@�@����
*|�@�߂�l�@�V�[���̃A�h���X
****************************************************************************/
Scene* ResultScene::createScene()
{

	// �V�[�����쐬����
	auto scene = Scene::create();

	// ���C���[���쐬����
	auto layer = ResultScene::create();

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

bool ResultScene::init()
{
	// �e�N���X������������
	if (!Scene::init())
	{
		return false;
	}

	// �L�����N�^�[�Ăяo��
	auto result_layer = ResultLayer::create();
	// �L�����N�^�[�֘A�̃��C��
	this->addChild(result_layer);

	// �^�b�`�C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(ResultScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//���y�t�@�C����\�߃��[�h���Ă���
	AudioEngine::preload("Sounds\\TapSE.ogg");
	//���ʉ�
	ResultBGM = AudioEngine::play2d("Sounds\\ResultBGM.ogg");

	return true;
}

/***************************************************************************
*|	�T�v�@�@�L�[�������ꂽ�Ƃ��Ăяo�����֐�
*|	�����@�@����
*|�@�߂�l�@����
****************************************************************************/
// �^�b�`�J�n���R�[���o�b�N
bool ResultScene::onTouchBegan(Touch* touch, Event* pEvent)
{
	
	////�t�F�[�h�g�����W�V����
	//nextScene = TransitionOriginal::create(1.0f, nextScene);
	if (Score::SceneFlag == true)
	{
		Score::SceneFlag = false;
		//BGM�I��
		AudioEngine::stop(ResultBGM);
		// ���̃V�[�����쐬����
		Scene* nextScene = TitleScene::create();
		// ���̃V�[���Ɉڍs
		_director->replaceScene(nextScene);
	}
	//���ʉ�
	int id = AudioEngine::play2d("Sounds\\TapSE.ogg");


	return true;

}
