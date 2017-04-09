#include "PlayScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

////////////////////////////////////////////////////////
// �s���ȓ_�F���摜�𕔕����ɕʁX�ŕ\����������@�B�@ 
// ��3�b�o���ы���\�����ăA�N�V���������s��������@�B
// ������ʊO����\����������@�B
// 
/////////////////////////////////////////////////////////


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

// on "init" you need to initialize your instance
bool Play::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

	//�@�C���V��3�b�Ɉ�񂭂炢
	/* �C���V */
	// �C���V����
	Sprite*iwashi = Sprite::create("PlaySeen.png");
	Sprite->setPosition(Vec2(100.0f, 0.0f));
	this->addChild(iwashi);


	/* �A�N�V���� */
	// �C���V�s��

	iwashi->setPosition(Vec2(iwashi->getContentSize))


	auto sprite = Sprite::create("PlaySeen.png");
	sprite->setPosition(Vec2(sprite->getContentSize().width / 2, visibleSize.height / 2));
	addChild(sprite);	
	MoveTo* action1 = MoveTo::create(1, Vec2(visibleSize.width - iwashi->getContentSize().width / 2, visibleSize.height / 2));
	EaseBackInOut* action2 = EaseBackInOut::create(action);
	Sequence*action3 = Sequence::create(action1, action2, action1, nullptr);
	RepeayForever* action4 = RepeatForever::create(action3);

	iwasi->runaction(action);


    return true;
}


