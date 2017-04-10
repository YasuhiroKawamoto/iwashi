#include "TitleBackGround.h"

USING_NS_CC;
bool TitleBackGround::init()
{
	if (!Node::init())
	{
		return false;
	}


	// 作成したパーティクルのプロパティリストを読み込み
	ParticleSystemQuad* particle = ParticleSystemQuad::create("Images\\particle_texture.plist");
	//パーティクルのメモリーリーク回避（★重要）
	particle->setAutoRemoveOnFinish(true);
	// パーティクルを開始
	particle->resetSystem();
	// パーティクルを表示する場所の設定
	particle->setPosition(480, -100);
	// パーティクルを配置
	this->addChild(particle);

	//タッチ
	s_touch = Sprite::create("Images\\TouchImage.png");
	s_touch->setPosition(Vec2(480.0f, 100.0f));
	this->addChild(s_touch);
	Opacity = 0;
	this->scheduleUpdate();

	return true;
}

void TitleBackGround::update(float data)
{

		Opacity += 2;
		s_touch->setOpacity(Opacity);
	
}