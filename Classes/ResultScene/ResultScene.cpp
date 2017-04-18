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
#include "Score.h"
USING_NS_CC;
using namespace cocos2d::experimental;


/* ---- �����o�[�֐��̒�` ---------------- */
/***************************************************************************
*|	�T�v�@�@�V�[�����쐬����B
*|	�����@�@����
*|�@�߂�l�@�V�[���̃A�h���X
****************************************************************************/
Scene* ResultScene::create(int score)
{
	//�������m��
	ResultScene *pRet = new(std::nothrow)ResultScene();

	if (pRet && pRet->init(score))
    { 
        pRet->autorelease(); 
        return pRet; 
    } 
    else 
    { 
        delete pRet; 
        pRet = nullptr; 
        return nullptr; 
    } 
}

/***************************************************************************
*|	�T�v�@�@�v���C�V�[���̃��C���[���Ăт���
*|	�����@�@����
*|�@�߂�l�@����
****************************************************************************/

bool ResultScene::init(int score)
{
	// �e�N���X������������
	if (!Scene::init())
	{
		return false;
	}
	Score::m_Score = score;

	// �L�����N�^�[�Ăяo��
	auto result_layer = ResultLayer::create();
	// �L�����N�^�[�֘A�̃��C��
	this->addChild(result_layer);

	// �^�b�`�C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(ResultScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	//���y�t�@�C����\�߃��[�h���Ă���
	AudioEngine::preload("Sounds/TapSE.ogg");
	//���ʉ�
	ResultBGM = AudioEngine::play2d("Sounds/ResultBGM.mp3", true);
	bubble = AudioEngine::play2d("Sounds/bubble.mp3");
	AudioEngine::setLoop(bubble, true);
	
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
		AudioEngine::stop(bubble);
		AudioEngine::uncache("Sounds/ResultBGM.mp3");

		// ���̃V�[�����쐬����
		Scene* nextScene = TitleScene::create();
		// ���̃V�[���Ɉڍs
		_director->replaceScene(nextScene);
	}
	//���ʉ�
	int id = AudioEngine::play2d("Sounds/TapSE.ogg");


	return true;

}
