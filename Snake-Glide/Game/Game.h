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

	int score;

	// Snake

	//sf::RenderWindow* window;
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

	//// Private Functions

	void initSnake();
	void initVariables();

public:

	Game(sf::VideoMode);
	// 
	// Game

	void keyboardInput(sf::RenderWindow* window);

	// Game Window

	void pollEvent(sf::RenderWindow* window);

	// Update

	void updateTarget(sf::RenderWindow* window);
	void updateSnake(sf::RenderWindow* window);
	void update(sf::RenderWindow* window);

	// Render

	void renderTarget(sf::RenderWindow* window);
	void renderSnake(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);

	void run(sf::RenderWindow*, sf::Event);
};