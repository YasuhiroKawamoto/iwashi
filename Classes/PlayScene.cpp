#include "PlayScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "audio\include\AudioEngine.h"


USING_NS_CC;

using namespace cocos2d::experimental;
using namespace cocostudio::timeline;

const int SPRIITE_SIZE = 256;
const int SCREEN_WIDTH = 960;

const int ANIMETION�QPUTTURNS = 3;
const int ANIMETION�QFRAME = 30;


enum PLAYER
{
	PLAYER_1,
	PLAYER_2
};

Scene* Play::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Play::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// ===========================================
// @>�T�@�v:�^�b�`���W�ɉ��g�𐶐�
//
// @>���@��:�^�b�`���W(Vec2), �ǂ����̃v���C���[����������(int)
//
// @>�߂�l:�Ȃ�
// ===========================================
void  Play::CreateWave(Vec2 pos, int player)
{

		// �摜�t�@�C���̓ǂݍ���
		m_wave[player] = Sprite::create("Images\\wave_anm.png");

		// �ŏ��̃p�^�[���摜��؂蔲��
		m_wave[player]->setTextureRect(Rect(0, 0, SPRIITE_SIZE, SPRIITE_SIZE));

		// ���W���^�b�`���W�ɕύX
		m_wave[player]->setPosition(Vec2(pos.x, pos.y));

		// �T�C�Y�����������ɒ���
		m_wave[player]->setScale(0.4f);

	
	// �e�m�[�h�ɒǉ�
	this->addChild(m_wave[player]);
}


// ===========================================
// @>�T�@�v:���g����ʊO�ɏo����Ĕ��ˉ\�ɂ���
//
// @>���@��:�Ȃ�
//
// @>�߂�l:�Ȃ�
// ===========================================
void Play::Reload()
{
	// ��ʊO�ɏo���甭�ˏ�Ԃ���
	if (m_wave[PLAYER_1] != nullptr)
	{
		if (m_wave[PLAYER_1]->getPosition().x > SCREEN_WIDTH)
		{
			canShoot_1p = true;
		}
	}

	if (m_wave[PLAYER_2] != nullptr)
	{
		if (m_wave[PLAYER_2]->getPosition().x < 0)
		{
			canShoot_2p = true;
		}
	}
}

// ===========================================
// @>�T�@�v:�A�j���[�V�����̍X�V
//
// @>���@��:�Ȃ�
//
// @>�߂�l:�Ȃ�
// ===========================================
void Play::AnimationUpdate()
{
	// �A�j���\�V�����J�E���g�̑���
	m_animation_cnt++;

	// �ő�90�t���[���ݒ�
	m_animation_cnt %= ANIMETION�QFRAME * ANIMETION�QPUTTURNS;

	// 2�̉��g�̃X�v���C�g�����ꂼ��؂�ւ���
	for (int i = 0; i < 2; i++)
	{
		if (m_wave[i] != nullptr)
		{
			m_wave[i]->setTextureRect(Rect(0, (m_animation_cnt / ANIMETION�QFRAME)*SPRIITE_SIZE, SPRIITE_SIZE, SPRIITE_SIZE));
		}
	}
}


// on "init" you need to initialize your instance
bool Play::init()
{
    /**  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    **/
    

    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	// �ϐ�������
	m_animation_cnt = 0;

	canShoot_1p = true;
	canShoot_2p = true;

	// update���Ăяo���ݒ�
	this->scheduleUpdate();

	// �C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();

	// �C�x���g���X�i�[�Ɋe�R�[���o�b�N�֐����Z�b�g����
	listener->onTouchBegan = CC_CALLBACK_2(Play::onTouchBegan, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	// �w�i
	m_bg = Sprite::create("Images\\BG.png");
	m_bg->setAnchorPoint(Vec2(0, 0));
	this->addChild(m_bg);

	// BGM�̃v�����[�h
	AudioEngine::preload("Sounds\\SeenBGM.ogg");

	// SE�̃v�����[�h
	AudioEngine::preload("Sounds\\Sonic.ogg");

	// �e�m�[�h���쐬
	m_parent_wave = Sprite::create();

	// �e�m�[�h���V�[���ɒǉ�
	this->addChild(m_parent_wave);

	// BGM�Đ�
	se_wave = AudioEngine::play2d("Sounds\\SeenBGM.ogg", true);

    return true;
}

// ���t���[���Ăяo�����update�֐�
void Play::update(float delta)
{
	// �A�j���[�V�����X�V
	AnimationUpdate();

	// ��ʊO�ɏo���甭�ˏ�Ԃ���
	Reload();

}

bool Play::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event)
{
	// �^�b�`���W���擾
	Vec2 touch_pos = touch->getLocation();

	// y���W�ɐ�����t����
	if (touch_pos.y > 400)
	{
		touch_pos.y = 400;
	}

	// ��ʔ�����荶���^�b�v���ꂽ�Ƃ��̏���
	if (touch_pos.x < (SCREEN_WIDTH / 2))
	{
		// ���ˉ\��Ԃ̎�
		if (canShoot_1p)
		{
			Play::CreateWave(Vec2(0, touch_pos.y), PLAYER_1);
			m_wave[0]->setFlippedX(true);

			// �A�j���[�V�������Z�b�g
			m_animation_cnt = 0;

			// ���˂�s��
			canShoot_1p = false;

			// ��ʊO�܂ŉ��g�ړ�
			m_wave[PLAYER_1]->runAction(MoveBy::create(4.0f, Vec3(SCREEN_WIDTH + SCREEN_WIDTH, 0, 0)));

			// SE�Đ�
			se_wave = AudioEngine::play2d("Sounds\\Sonic.ogg");

			return true;
		}
	}

	else // ��ʔ������E���^�b�v���ꂽ�Ƃ��̏���
	{
		// ���ˉ\��Ԃ̎�
		if (canShoot_2p)
		{
			Play::CreateWave(Vec2(SCREEN_WIDTH, touch_pos.y), PLAYER_2);

			// �A�j���[�V�������Z�b�g
			m_animation_cnt = 0;

			// ���˂�s��
			canShoot_2p = false;

			// ��ʊO�܂ŉ��g�ړ�
			m_wave[PLAYER_2]->runAction(MoveBy::create(4.0f, Vec3(-(SCREEN_WIDTH + SCREEN_WIDTH), 0, 0)));

			// SE�Đ�
			se_wave = AudioEngine::play2d("Sounds\\Sonic.ogg");

			return true;
		}
	}
	return false;
}