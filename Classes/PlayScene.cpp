#include "PlayScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "audio\include\AudioEngine.h"


USING_NS_CC;

using namespace cocos2d::experimental;
using namespace cocostudio::timeline;

const float TIME_LIMIT_SECOND = 1800;//�c�莞�ԁi�U�O�b�j
const float DECREASE_TIME = 0.5;//�����Ă�������
const int RETURN_TIME = 30;//fps�𕪒P�ʂɖ߂�
const float SCALSE_SIZE = 5.0;//������傫������T�C�Y
//���x���̍����ƕ�
const int TIME_LABEL_WIDTH = 350;
const int TIME_LABEL_HEIGHT = 70;
const int TEXT_TIME_LABEL_WIDTH = 550;
const int TEXT_TIME_LABEL_HEIGHT = 70;

const int SPRIITE_SIZE = 256;
const int SCREEN_WIDTH = 960;


const int ANIMETION�QPUTTURNS = 3;
const int ANIMETION�QFRAME = 30;


enum PLAYER
{
	PLAYER_1,
	PLAYER_2
};

//�R���X�g���N�^
Play::Play()
	:m_timer(TIME_LIMIT_SECOND)
	, m_TimeLabel(NULL)
	,m_flag(true)
{
}
//�f�X�g���N�^�[
Play::~Play()
{
	CC_SAFE_RELEASE_NULL(m_TimeLabel);//m_TimeLabel��j��
}
//----------------------------------------------------------------------
//! @brief createScene
//!
//! @param[in] �Ȃ�
//!
//! @return  scene
//----------------------------------------------------------------------

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


	// �V�[���ɒǉ�
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
	m_animation_cnt %= 90;

	// 2�̉��g�̃X�v���C�g�����ꂼ��؂�ւ���
	for (int i = 0; i < 2; i++)
	{
		if (m_wave[i] != nullptr)
		{
			m_wave[i]->setTextureRect(Rect(0, (m_animation_cnt / 30)*SPRIITE_SIZE, SPRIITE_SIZE, SPRIITE_SIZE));
		}
	}
}


//----------------------------------------------------------------------
//! @brief RenderTimeLabel
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Play::RenderTimeLabel()
{
	//���S���W
	auto size = Director::getInstance()->getWinSize();
	//�^�C�}�[ ���x���̒ǉ�
	int second = static_cast < int >(m_timer); // int �^ �� �L���X�g ����
	auto timeLabel = Label::createWithSystemFont(StringUtils::toString(second), "Arial Felt", 16);
	timeLabel->setColor(Color3B::BLACK);
	timeLabel->setPosition(Vec2(size.width - TIME_LABEL_WIDTH, size.height - TIME_LABEL_HEIGHT));
	timeLabel->setScale(SCALSE_SIZE);
	this->setTimeLabel(timeLabel);
	this->addChild(m_TimeLabel);
}

//----------------------------------------------------------------------
//! @brief RendertextTimeLabel
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------

void Play::RendertextTimeLabel()
{
	//���S���W
	auto size = Director::getInstance()->getWinSize();

	// �^�C�}�[�w�b�_�[�̒ǉ�
	auto textTimeLabel = Label::createWithSystemFont(" TIME", "Arial Felt", 16);
	textTimeLabel->setColor(Color3B::BLACK);
	textTimeLabel->setPosition(Vec2(size.width - TEXT_TIME_LABEL_WIDTH, size.height - TEXT_TIME_LABEL_HEIGHT));
	textTimeLabel->setScale(SCALSE_SIZE);
	this->addChild(textTimeLabel);
}
//----------------------------------------------------------------------
//! @brief UpadateTime
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------

void Play::UpadateTime()
{
	// �c�� �b �� �� ���炷
	m_timer -= DECREASE_TIME;
	// �c�� �b �� �� �\�� �� �X�V ����
	int second = static_cast < int >(m_timer / RETURN_TIME); // int �^ �� �L���X�g ����
	m_TimeLabel->setString(StringUtils::toString(second));
}
void Play::FormIwasHi()
{
	MoveTo*MoveByAction = MoveTo::create(3.0, Vec2(-1000, 340));
	DelayTime*DelayTimeAction = DelayTime::create(3);
	Sequence* SpawnAction = Sequence::create(DelayTimeAction, MoveByAction, nullptr);
	CCRect rect = CCRectMake(0, 0, 150, 50);
	iwashi = Sprite::create("Images\\PlaySeen.png");
	iwashi->setTextureRect(rect);
	iwashi->setPosition(1200, 340);
	this->addChild(iwashi);
	iwashi->runAction(SpawnAction);
	m_flag = false;
}
void Play::DeletIwashi()
{
	//��̍��W���m�F����
	float pos_x = iwashi->getPositionX();
	float pos_y = iwashi->getPositionY();
	//��̍��W��0�ȉ���������
	if (pos_x < 0)
	{
		iwashi->removeFromParent();//����폜
		iwashi = nullptr;
		m_flag = true;
	}
}
//----------------------------------------------------------------------
//! @brief init
//!
//! @param[in] �Ȃ�
//!
//! @return true or false
//----------------------------------------------------------------------

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

	for (int i = 0; i < 2; i++)
	{
		m_wave[i] = nullptr;
	}


	// �w�i
	m_bg = Sprite::create("Images\\BG.png");
	m_bg->setAnchorPoint(Vec2(0, 0));
	this->addChild(m_bg);

	// TIME�`��
	RenderTimeLabel();
	RendertextTimeLabel();

	// update���Ăяo���ݒ�
	this->scheduleUpdate();

	// �C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();

	// �C�x���g���X�i�[�Ɋe�R�[���o�b�N�֐����Z�b�g����
	listener->onTouchBegan = CC_CALLBACK_2(Play::onTouchBegan, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	// BGM�̃v�����[�h
	AudioEngine::preload("Sounds\\SeenBGM.ogg");

	// SE�̃v�����[�h
	AudioEngine::preload("Sounds\\Sonic.ogg");

	// BGM�Đ�
	se_wave = AudioEngine::play2d("Sounds\\SeenBGM.ogg", true);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//�@�C���V��3�b�Ɉ�񂭂炢
	/* �C���V */
	// �C���V����
	
	
	//Rect rect(float(0.0f), float(0.0f), float(150.0f), float(50.0f));

	//iwashi = Sprite::create("PlaySeen.png");
	//this->addChild(iwashi);
	/* �A�N�V�����H */
	// �C���V�s��
	//Sprite*iwashi = Sprite::create("PlaySeen.png");
	//iwashi->setPosition(Vec2(100.0f, 0.0f));
	//this->addChild(iwashi);


	/* �A�N�V���� */
	// �C���V�s��

	//iwashi->setPosition(Vec2(iwashi->getContentSize));

	//iwashi = Sprite::create("PlaySeen.png");
	//iwashi->setPosition(Vec2(iwashi->getContentSize().width / 2, visibleSize.height / 2));
	/*addChild(iwashi);
	MoveTo* action1 = MoveTo::create(1, Vec2(visibleSize.width - iwashi->getContentSize().width / 2, visibleSize.height / 2));
	EaseBackInOut* action2 = EaseBackInOut::create(action1);
	Sequence*action3 = Sequence::create(action1, action2, action1, nullptr);
	RepeatForever* action4 = RepeatForever::create(action3);
*/
	//iwashi->runAction(action4);
		///////////////////////////////////////////
	//�c��^�C����0�ɂȂ����烊�U���g��ʂɍs��
	///////////////////////////////////////////
	//if (m_timer < 0)
	//{

	//}

    return true;
}
//----------------------------------------------------------------------
//! @brief update(���t���[���Ăяo�����update�֐�)
//!
//! @param[in] �Ȃ�
//!
//! @return 
//----------------------------------------------------------------------
void Play::update(float delta)
{

	if (m_flag)
	{
		FormIwasHi();//��̐���
		DeletIwashi();//�񂪉�ʊO�ɏo����j��
	}
	// �A�j���[�V�����X�V
	AnimationUpdate();

	// ��ʊO�ɏo���甭�ˏ�Ԃ���
	Reload();

	//�c�莞�Ԃ̍X�V
	UpadateTime();


}
//----------------------------------------------------------------------
//! @brief onTouchBegan
//!
//! @param[in] cocos2d::Touch* touch, cocos2d::Event* unused_event
//!
//! @return true or false
//----------------------------------------------------------------------
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