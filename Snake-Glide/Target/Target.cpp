#include <time.h>
#include <random>

#include "Target.h"

using namespace std;

sf::Vector2f Target::targetGeneration(sf::VideoMode video_mode) {

	// Generating target on random location
	sf::Vector2f target_pos;

	random_device rd;                       // Seed for randomness
	mt19937 gen(rd());                      // Mersenne Twister generator
	uniform_int_distribution<> dis1(10, (video_mode.width / 10) - 10); // Range [0, 900]

	target_x = static_cast<float>(dis1(gen) * 10);

	uniform_int_distribution<> dis2(10, (video_mode.height / 10) - 10);

	target_y = static_cast<float>(dis2(gen) * 10);
	
	target_pos.x = target_x;

	target_pos.y = target_y;

	return target_pos;

}

bool Target::isTargetHit(vector<sf::RectangleShape>& snake, vector<sf::Vector2f>& snake_pos, Snake snake_movement){

	float head_x = snake_pos.at(snake_pos.size() - 1).x;

	float head_y = snake_pos.at(snake_pos.size() - 1).y;

	bool isHit = false;

	// From left

	if (head_x == target_x && head_y == target_y) {

		isHit = true;
	}

	// From Up

	if (head_x - 5 == target_x + 5 && head_y + 5 == target_y - 5) {

		isHit = true;
	}

	// From Down

	if (head_x - 5 == target_x + 5 && head_y - 5 == target_y + 5) {

		isHit = true;
	}

	// From Right

	if (head_x == target_x + 10 && head_y == target_y) {

		isHit = true;
	}

	// Is Hit?

	if (isHit == true) {

		snake_movement.increaseLength(snake, snake_pos);
	}

	
	return isHit;
}
