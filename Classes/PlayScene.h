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

	// タップ判定関数
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);

	// 音波生成関数
	void CreateWave(cocos2d::Vec2 pos);

	//残り時間の描画関数
	void RenderTimeLabel();
	//TIMEの描画関数
	void RendertextTimeLabel();
	//残り時間の更新関数
	void UpadateTime();
	// プレイヤー1
	cocos2d::Sprite* m_player1;

	// プレイヤー2
	cocos2d::Sprite* m_player2;

	// 音波
	cocos2d::Sprite* m_wave;


	CC_SYNTHESIZE(float, m_timer, Second);//残り秒数をfloatに変換する
	CC_SYNTHESIZE_RETAIN(cocos2d::Label*, m_TimeLabel, TimeLabel);//ラベルを新しくセットする関数をつくる

    // implement the "static create()" method manually
    CREATE_FUNC(Play);


	cocos2d::Sprite* iwashi;

};

#endif // __HELLOWORLD_SCENE_H__
