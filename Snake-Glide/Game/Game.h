#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>

#include "../Snake/Snake.h"

using namespace std;

class Game {

private:

	// For main menu

	bool main_menu;

	// Snake

	sf::RenderWindow* window;
	sf::VideoMode video_mode;
	sf::Event evnt;

	// For Snake

	vector <sf::RectangleShape> snake;
	vector <sf::Vector2f> snake_pos;

	// Taget

	sf::RectangleShape target;
	sf::Vector2f target_pos;
	
	// Target Private Function

	void generateTarget();

	// Private Functions

	void initSnake();
	void initVariables();
	void initWindow();

public:

	Game();
	~Game();
	
	// Accessor
	
	const bool isRunning() const;
	
	// Snake Data

	void isKilledInGame(bool);

	// Game

	void keyboardInput();

	// Game Window

	void pollEvent();

	// Update

	void updateTarget();
	void updateSnake();
	void update();

	// Render

	void renderTarget();
	void renderSnake();
	void render();
};