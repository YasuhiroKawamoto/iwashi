#pragma once


#include "cocos2d.h"

class TitleScene :public cocos2d::Scene
{
public:
	//�V�[�����쐬����
	static cocos2d::Scene* createScene();
	CREATE_FUNC(TitleScene);
	//����������
	virtual bool init();
	//�^�b�`���ɌĂяo�����֐�
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
private:
	int BGM;
};