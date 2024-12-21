#pragma once
#include "../Game/Game.h"


enum Direction
{
    RIGHT,
    LEFT,
    UP,
    DOWN
};


using namespace std;

class Snake
{

private:

    float snake_speed = 10;
    
public:

    static int score;

    // Movement

    void move(vector<sf::RectangleShape>&, vector<sf::Vector2f>&, sf::VideoMode);

    void moveRight(vector<sf::RectangleShape>&, vector<sf::Vector2f>& , sf::VideoMode);
    void moveLeft(vector<sf::RectangleShape>&, vector<sf::Vector2f>&, sf::VideoMode);
    void moveUp(vector<sf::RectangleShape>&, vector<sf::Vector2f>&, sf::VideoMode);
    void moveDown(vector<sf::RectangleShape>&, vector<sf::Vector2f>&, sf::VideoMode);
    

    // Is Killed
    
    bool isKilledByItself(vector<sf::RectangleShape>&, vector<sf::Vector2f>&);
    bool isKilledByWall(vector<sf::Vector2f>, sf::VideoMode);
    
    // Increase Length
    
    void increaseLength(vector<sf::RectangleShape>&, vector<sf::Vector2f>&);
};