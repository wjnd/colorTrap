#include "IntroScene.h"
#include "SimpleAudioEngine.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* IntroScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = IntroScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool IntroScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    //Add our code here

	m_loadingSteps = 0;
	this->scheduleUpdate();
    return true;
}

void IntroScene::update(float dt)
{
	switch (m_loadingSteps)
	{
		//Load sprite sheet
	case 0:
		//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprite_sheet_name.plist", "spite_sheet_name.png");
		break;
		
		//Load Logo
	case 1:
		//auto logo = Sprite::createWithSpriteFrameName("logo.png");
		//this->addChild(logo);
		break;
		
		//go to main menu scene
	case 2:
		this->schedule(schedule_selector(IntroScene::gotoMainMenu), 2.0f);
		break;
	}
	m_loadingSteps++;
}

void IntroScene::gotoMainMenu(float dt)
{
	auto mainMenuScene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(mainMenuScene);
}

