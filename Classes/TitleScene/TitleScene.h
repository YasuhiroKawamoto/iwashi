#pragma once


#include "cocos2d.h"

class TitleScene :public cocos2d::Scene
{
public:
	//シーンを作成する
	static cocos2d::Scene* createScene();
	CREATE_FUNC(TitleScene);
	//初期化する
	virtual bool init();
	//タッチ時に呼び出される関数
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
private:
	int BGM;
};