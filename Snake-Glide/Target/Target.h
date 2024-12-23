#pragma once
#include "../Snake/Snake.h"

using namespace std;

class Target {

private:
	// Target Record

	float target_x, target_y;

public:

	// Generate Target

	sf::Vector2f targetGeneration(sf::VideoMode);

	// Is Hit

	bool isTargetHit(vector<sf::RectangleShape>&, vector<sf::Vector2f>&, Snake);
};