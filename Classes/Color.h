#pragma once
#include "cocos2d.h"

USING_NS_CC;
class Color : public LabelTTF
{
public:
	virtual bool init();
	CREATE_FUNC(Color);
	Color3B convertToColor(int color);
	std::string convertToStringColor(int color);
	LabelTTF* getColorLabel();
private:
	int color;
	int colorString;
	LabelTTF* colorLabel;
};