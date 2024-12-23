#pragma once
#include <SFML/Graphics.hpp>
#include "../Button/Button.h"
#include "../Game/Game.h"

class MainMenu
{
private:

	bool main_menu;

	sf::RenderWindow* window;
	sf::VideoMode video_mode;
	sf::Event evnt;


	void initVariables();
	void initWindow();

public:

	MainMenu();
	~MainMenu();

	void main_menu_window(Button&, Button&);

	void gameLoop();


	void update();

	// Render

	void render();
};

