/***************************************************************************
*|
*|	概要　背景クラスの宣言
*|　作成者　GS2 16 中田湧介
*|　作成日　2017/4/07
*|___________________________________________________________________________
****************************************************************************/
/* ---- ライブラリのインクルード ---------- */
#include "BackGround.h"
#include "Score.h"
USING_NS_CC;

bool BackGround::init()
{
	if (!Node::init()) {

		return false;
	}

	//背景
	s_BackGround = Sprite::create("Images/ResultTexture.png");
	s_BackGround->setPosition(Vec2(480.0f, 320.0f));
	s_BackGround->setScale(1.5f, 1.5f);
	this->addChild(s_BackGround);

	// 作成したパーティクルのプロパティリストを読み込み
	ParticleSystemQuad* particle = ParticleSystemQuad::create("Images/particle_texture.plist");
	//パーティクルのメモリーリーク回避（★重要）
	particle->setAutoRemoveOnFinish(true);
	// パーティクルを開始
	particle->resetSystem();
	// パーティクルを表示する場所の設定
	particle->setPosition(480, -100);
	// パーティクルを配置
	this->addChild(particle);
	////毎フレームアップデート関数を呼びだす
	this->scheduleUpdate();


	//タッチ
	s_touch = Sprite::create("Images/TouchImage.png");
	s_touch->setPosition(Vec2(480.0f,100.f));
	s_touch->setVisible(false);
//	s_touch->setScale
	this->addChild(s_touch);
	Opacity = 0;
	return true;
}

void BackGround::update(float data)
{
	if (Score::SceneFlag == true)
	{
		s_touch->setVisible(true);
		Opacity += 2;
		s_touch->setOpacity(Opacity);
	}
}
