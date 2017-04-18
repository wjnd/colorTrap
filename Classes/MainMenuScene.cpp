#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "PlayScene.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
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
	//Title game
	auto titleGame = LabelTTF::create("Color Trap", "Arial", 30);
	titleGame->setColor(Color3B::BLUE);
	titleGame->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(titleGame);

	//Play Button
	auto playBtn = MenuItemLabel::create(LabelTTF::create("Play", "Arial", 20), CC_CALLBACK_0(MainMenuScene::gotoPlayScene, this));
	playBtn->setColor(Color3B::GREEN);
	
	auto menu = Menu::create();
	menu->addChild(playBtn);
	menu->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 3);
	this->addChild(menu);

    return true;
}
void MainMenuScene::gotoPlayScene()
{
	auto playScene = PlayScene::createScene();
	Director::getInstance()->replaceScene(playScene);
}


