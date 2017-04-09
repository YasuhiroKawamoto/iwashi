#pragma once
#include "cocos2d.h"

class TitleBackGround : public cocos2d::Node
{
public:
	virtual bool init();
	CREATE_FUNC(TitleBackGround);

private:
	void update(float date)override;
	cocos2d::Sprite* s_touch;//タッチスプライト
	float Opacity;//透明度

};