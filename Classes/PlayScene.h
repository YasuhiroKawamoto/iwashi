#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class Play : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	void update(float delta) override;

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode key_code, cocos2d::Event* key_event);

	// プレイヤー1
	cocos2d::Sprite* m_player1;

	// 音波
	cocos2d::Sprite* m_wave;

	// プレイヤーと音波の親ノード
	cocos2d::Node* m_pParentNode;

    // implement the "static create()" method manually
    CREATE_FUNC(Play);


	cocos2d::Sprite* iwashi;

};

#endif // __HELLOWORLD_SCENE_H__
