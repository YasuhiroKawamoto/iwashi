#include "TitleBackGround.h"

USING_NS_CC;
bool TitleBackGround::init()
{
	if (!Node::init())
	{
		return false;
	}
	return true;

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
}
