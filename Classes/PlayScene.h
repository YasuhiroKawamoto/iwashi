#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class Play : public cocos2d::Layer
{
public:
	Play();
	~Play();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	void update(float delta) override;

	// void onKeyPressed(cocos2d::EventKeyboard::KeyCode key_code, cocos2d::Event* key_event);

	// �^�b�v����֐�
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);

	// ���g�����֐�
	void CreateWave(cocos2d::Vec2 pos);

	//�c�莞�Ԃ̕`��֐�
	void RenderTimeLabel();
	//TIME�̕`��֐�
	void RendertextTimeLabel();
	//�c�莞�Ԃ̍X�V�֐�
	void UpadateTime();
	// �v���C���[1
	cocos2d::Sprite* m_player1;

	// �v���C���[2
	cocos2d::Sprite* m_player2;

	// ���g
	cocos2d::Sprite* m_wave;


	CC_SYNTHESIZE(float, m_timer, Second);//�c��b����float�ɕϊ�����
	CC_SYNTHESIZE_RETAIN(cocos2d::Label*, m_TimeLabel, TimeLabel);//���x����V�����Z�b�g����֐�������

    // implement the "static create()" method manually
    CREATE_FUNC(Play);


	cocos2d::Sprite* iwashi;

};

#endif // __HELLOWORLD_SCENE_H__
