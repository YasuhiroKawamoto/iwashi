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

	// タップ判定関数
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);

	// 音波生成関数
	void CreateWave(cocos2d::Vec2 pos, int player);


	// 音波が画面外に出たら再発射可能にする
	void Reload();

	//残り時間の描画関数
	void RenderTimeLabel();
	//TIMEの描画関数
	void RendertextTimeLabel();
	//残り時間の更新関数
	void UpadateTime();
	//鰯の生成関数
	void FormIwasHi();
	//鰯が画面外に出たら削除する関数
	void DeletIwashi();
	//鰯を捕獲したら削除する関数
	void IwashiDelete();
	// プレイヤー1
	cocos2d::Sprite* m_player1;

	// アニメーション更新
	void AnimationUpdate();

	// 当たり判定
	bool Collision();

	// 鰯をゲット
	void GetIwashi();

	// 背景
	cocos2d::Sprite* m_bg;

	// 音波	
	cocos2d::Sprite* m_wave[2];		// 音波のスプライト

	// それぞれのプレイヤが音波を発射出来るか
	bool canShoot_1p;
	bool canShoot_2p;

	int se_wave;
	int bgm_play;
	int m_animation_cnt;

	// 鰯
	bool m_flag;//鰯を生成させるフラグ




	CC_SYNTHESIZE(float, m_timer, Second);//残り秒数をfloatに変換する
	CC_SYNTHESIZE_RETAIN(cocos2d::Label*, m_TimeLabel, TimeLabel);//ラベルを新しくセットする関数をつくる

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
