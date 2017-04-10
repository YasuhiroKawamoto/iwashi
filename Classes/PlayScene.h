#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class Play : public cocos2d::Scene
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
	void CreateWave(cocos2d::Vec2 pos, int player);


	// ���g����ʊO�ɏo����Ĕ��ˉ\�ɂ���
	void Reload();

	//�c�莞�Ԃ̕`��֐�
	void RenderTimeLabel();
	//TIME�̕`��֐�
	void RendertextTimeLabel();
	//�c�莞�Ԃ̍X�V�֐�
	void UpadateTime();
	//��̐����֐�
	void FormIwasHi();
	//�񂪉�ʊO�ɏo����폜����֐�
	void DeletIwashi();
	//���ߊl������폜����֐�
	void IwashiDelete();
	// �v���C���[1
	cocos2d::Sprite* m_player1;

	// �A�j���[�V�����X�V
	void AnimationUpdate();

	// �����蔻��
	bool Collision();

	// ����Q�b�g
	void GetIwashi();

	// �w�i
	cocos2d::Sprite* m_bg;

	// ���g	
	cocos2d::Sprite* m_wave[2];		// ���g�̃X�v���C�g

	// ���ꂼ��̃v���C�������g�𔭎ˏo���邩
	bool canShoot_1p;
	bool canShoot_2p;

	int se_wave;
	int bgm_play;
	int m_animation_cnt;

	// ��
	bool m_flag;//��𐶐�������t���O




	CC_SYNTHESIZE(float, m_timer, Second);//�c��b����float�ɕϊ�����
	CC_SYNTHESIZE_RETAIN(cocos2d::Label*, m_TimeLabel, TimeLabel);//���x����V�����Z�b�g����֐�������

    // implement the "static create()" method manually
    CREATE_FUNC(Play);
	cocos2d::Sprite* iwashi;
	cocos2d::Rect r_iwashi;
	cocos2d::Rect r_wave1;
	cocos2d::Rect r_wave2;
	bool isHit1;
	bool isHit2;
};

#endif // __HELLOWORLD_SCENE_H__
