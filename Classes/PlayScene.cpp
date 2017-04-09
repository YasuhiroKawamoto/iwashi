#include "PlayScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

////////////////////////////////////////////////////////
// 不明な点：元画像を部分毎に別々で表示させる方法。　 
// 約3秒経つたび魚を表示してアクションを実行させる方法。
// 魚を画面外から表示させる方法。
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

	//　イワシは3秒に一回くらい
	/* イワシ */
	// イワシ生成
	Sprite*iwashi = Sprite::create("PlaySeen.png");
	Sprite->setPosition(Vec2(100.0f, 0.0f));
	this->addChild(iwashi);


	/* アクション */
	// イワシ行動

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


