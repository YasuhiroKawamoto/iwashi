#include "TitleLayer.h"
#include "TitleBackGround.h"
USING_NS_CC;

bool TitleLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//���C���[�Ƀm�[�h���W��
	TitleBackGround* title_back_ground = TitleBackGround::create();
	this->addChild(title_back_ground);

	return true;

}