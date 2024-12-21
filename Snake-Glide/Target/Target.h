#pragma once
#include "../Snake/Snake.h"

using namespace std;

class Target {

	// Target Record

	float target_x, target_y;

public:

	// Generate Target

	sf::Vector2f targetGeneration(sf::VideoMode video_mode);

	// Is Hit

	bool isTargetHit(vector<sf::RectangleShape>& snake, vector<sf::Vector2f>& snake_pos, Snake snake_movement);
};