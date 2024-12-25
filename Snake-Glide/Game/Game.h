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

	sf::RenderWindow* window;
	sf::VideoMode video_mode;
	sf::Event evnt;

	//

	Snake* snake_movement;
	
	// Target

	sf::RectangleShape target;
	sf::Vector2f target_pos;

	//// Private Functions

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
	void update();

	// Render

	void renderTarget();
	void render();

	void run();
};