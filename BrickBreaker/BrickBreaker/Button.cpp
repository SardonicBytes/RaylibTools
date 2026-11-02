#include "Button.h"
#include <cstdio>

void Button::Update()
{
	isHovered = CheckCollisionPointRec(GetMousePosition(),rect);
	clickedTimer -= GetFrameTime();
	if (IsMouseButtonPressed(0))
	{
		if (isHovered)
		{
			Press();
		}
	}
}

void Button::Render() const
{
	auto renderColor = (isHovered)? hoverColor : colour;
	if (clickedTimer > 0)
	{
		renderColor = clickedColor;
	}
	auto measuredText = MeasureText(message.c_str(), fontSize);
	DrawRectangleRounded(rect,10,12,renderColor);
	DrawText(message.c_str(), rect.x + rect.width/2 - measuredText/2, rect.y + rect.height/2 - fontSize / 2,  fontSize, textColour);
}

void Button::Press()
{
	printf("Button Pressed\n");
	clickedTimer = 0.2f;
	if (pressAction) pressAction();
}
