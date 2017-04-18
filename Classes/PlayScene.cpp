#include "PlayScene.h"
#include "SimpleAudioEngine.h"
#include "Color.h"

USING_NS_CC;

Scene* PlayScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = PlayScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PlayScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	/////////////////////////////
	//Add our code here
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//background
	auto background = Sprite::create("background.jpg");
	background->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(background);
	//score label
	auto scoreLabel = Label::createWithSystemFont("Score", "Arial", 30);
	scoreLabel->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 2 / 3);
	this->addChild(scoreLabel);
    
	//Gen random color label
	auto color = Color::create();
	auto questionLabel = color->getColorLabel();
	questionLabel->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(questionLabel);
    return true;
}


