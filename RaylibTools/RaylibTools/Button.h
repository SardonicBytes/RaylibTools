#pragma once
#include <raylib.h>
#include <string>
#include <functional>


class Button
{
public:

	Rectangle rect = Rectangle{100,100,300,100};
	std::string message = "Button";
	std::function<void()> pressAction;

	//Button Settings
	float fontSize = 50;
	Color colour = BLUE;
	Color hoverColor = GRAY;
	Color clickedColor = WHITE;
	Color textColour = RED;


	void Update();
	void Render() const;
	void Press();

private:

	bool isHovered = false;
	float clickedTimer = 0;
};
