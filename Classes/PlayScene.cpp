#include "PlayScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

const int SPRIITE_SIZE = 256;
const int SCREEN_WIDTH = 960;

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
// @>���@��:�^�b�`���W
//
// @>�߂�l:�Ȃ�
// ===========================================
void  Play::CreateWave(Vec2 pos)
{
	// �摜�t�@�C���̓ǂݍ���
	m_wave = Sprite::create("Images\\wave_anm.png");

	// �ŏ��̃p�^�[���摜��؂蔲��
	m_wave->setTextureRect(Rect(0, 0, SPRIITE_SIZE, SPRIITE_SIZE));

	// ���W���^�b�`���W�ɕύX
	m_wave->setPosition(Vec2(pos.x, pos.y));

	// �T�C�Y�����������ɒ���
	m_wave->setScale(0.4f);

	// �v���C�V�[���ɒǉ�
	this->addChild(m_wave);
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
    
	// update���Ăяo���ݒ�
	this->scheduleUpdate();

	// �C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();

	// �C�x���g���X�i�[�Ɋe�R�[���o�b�N�֐����Z�b�g����
	listener->onTouchBegan = CC_CALLBACK_2(Play::onTouchBegan, this);


	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

    return true;
}

// ���t���[���Ăяo�����update�֐�
void Play::update(float delta)
{
	static int cnt = 0;

	cnt++;
	cnt %= 90;
	if (m_wave != nullptr)
	{
		m_wave->setTextureRect(Rect(0, (cnt/30)*SPRIITE_SIZE, SPRIITE_SIZE, SPRIITE_SIZE));
	}
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
		Play::CreateWave(Vec2(0, touch_pos.y));
		m_wave->setFlippedX(true);

		// ��ʊO�܂ŉ��g�ړ�
		m_wave->runAction(MoveBy::create(4.0f, Vec3(SCREEN_WIDTH+ SCREEN_WIDTH, 0, 0)));
		return true;
	}

	else // ��ʔ������E���^�b�v���ꂽ�Ƃ��̏���
	{
		Play::CreateWave(Vec2(SCREEN_WIDTH, touch_pos.y));

		// ��ʊO�܂ŉ��g�ړ�
		m_wave->runAction(MoveBy::create(4.0f, Vec3(-(SCREEN_WIDTH+SCREEN_WIDTH), 0, 0)));
		return true;
	}

	return false;

}