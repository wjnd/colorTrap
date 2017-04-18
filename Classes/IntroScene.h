#pragma once

#include "cocos2d.h"

class IntroScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	void update(float dt) override;
	CREATE_FUNC(IntroScene);
	void gotoMainMenu(float dt);
private:
	int m_loadingSteps;
};


