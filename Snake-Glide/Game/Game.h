#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>

#include "../Snake/Snake.h"

using namespace std;

class Game {

private:

	int score;

	// Snake

	sf::RenderWindow* window;
	sf::VideoMode video_mode;
	sf::Event evnt;

	// For Snake

	vector <sf::RectangleShape> snake;
	vector <sf::Vector2f> snake_pos;

	// Target

	sf::RectangleShape target;
	sf::Vector2f target_pos;

	//// Private Functions

	void initSnake();
	void initVariables();

public:

	Game(sf::RenderWindow*, sf::Event, sf::VideoMode);
	
	int getScore();

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

	void run();
};