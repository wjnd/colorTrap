#include "Color.h"
#include "Definition.h"

bool Color::init()
{
	color = RandomHelper::random_int(1, 7);
	colorString = RandomHelper::random_int(1, 7);
	colorLabel = LabelTTF::create(convertToStringColor(colorString), "Arial", 30);
	colorLabel->setColor(convertToColor(color));
	return true;
}
Color3B Color::convertToColor(int color)
{
	Color3B result;
	switch (color)
	{
	case eColor::RED:
		result = Color3B::RED;
		break;
	case eColor::BLUE:
		result = Color3B::BLUE;
		break;
	case eColor::ORANGE:
		result = Color3B::ORANGE;
		break;
	case eColor::YELLOW:
		result = Color3B::YELLOW;
		break;
	case eColor::GREEN:
		result = Color3B::GREEN;
		break;
	case eColor::WHITE:
		result = Color3B::WHITE;
		break;
	case eColor::BLACK:
		result = Color3B::BLACK;
		break;
	}
	return result;
}

std::string Color::convertToStringColor(int color)
{
	std::string result;
	switch (color)
	{
	case eColor::RED:
		result = "RED";
		break;
	case eColor::BLUE:
		result = "BLUE";
		break;
	case eColor::ORANGE:
		result = "ORANGE";
		break;
	case eColor::YELLOW:
		result = "YELLOW";
		break;
	case eColor::GREEN:
		result = "GREEN";
		break;
	case eColor::WHITE:
		result = "WHITE";
		break;
	case eColor::BLACK:
		result = "BLACK";
		break;
	}
	return result;
}

LabelTTF* Color::getColorLabel()
{
	return colorLabel;
}