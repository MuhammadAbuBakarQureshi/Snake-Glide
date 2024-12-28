#pragma once
#include <SFML/Graphics.hpp>
#include "../Button/Button.h"
#include "../Game/Game.h"

class MainMenu
{
private:

	// Window

	sf::RenderWindow* window;
	sf::VideoMode video_mode;
	sf::Event evnt;

	// Buttons
	// 
	// Initialization

	void initVariables();
	void initWindow();

	// After Kill

	void scoreWindow(Game);

	void highScoreWindow();

public:

	MainMenu();
	~MainMenu();

	void gameLoop();

	void updateScore();
	void updateTitle();
};

