#include "PlayScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

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

void  Play::CreateWave(Vec2 pos)
{
	m_wave = Sprite::create("Images\\Sonic_1.png");
	m_wave->setPosition(Vec2(pos.x, pos.y));
	m_wave->setScale(0.6f);
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

	//�@�C���V��3�b�Ɉ�񂭂炢
	/* �C���V */
	// �C���V����
//	Sprite*iwashi = Sprite::create("");

//	this->addChild(iwashi);

	/* �A�N�V�����H */
	// �C���V�s��

    return true;
}

// ���t���[���Ăяo�����update�֐�
void Play::update(float delta)
{

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
	if (touch_pos.x < (960 / 2))
	{
		Play::CreateWave(Vec2(0, touch_pos.y));
		m_wave->setFlippedX(true);

		// ���g�ړ�
		m_wave->runAction(MoveBy::create(2.0f, Vec3(1000, 0, 0)));
		return true;
	}

	// ��ʔ������E���^�b�v���ꂽ�Ƃ��̏���
	else
	{
		Play::CreateWave(Vec2(960, touch_pos.y));

		// ���g�ړ�
		m_wave->runAction(MoveBy::create(2.0f, Vec3(-1000, 0, 0)));
		return true;
	}

	return false;

}