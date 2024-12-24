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
    
    sf::RenderWindow* window;
    sf::VideoMode video_mode;

    // Snake

    vector <sf::RectangleShape> snake;
    vector <sf::Vector2f> snake_pos;

    // Snake Function

    void initSnake();

public:

    Snake(sf::RenderWindow&, sf::VideoMode);
    Snake() {};

    void snakeInput(sf::RenderWindow&, sf::VideoMode);

    // Movement

    void move();

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    
    // Update

    void update(sf::Vector2f);
    void render();

    // Is Killed
    
    bool isKilledByItself();
    bool isKilledByWall();
    
    // Increase Length
    
    void increaseLength(vector<sf::RectangleShape>&, vector<sf::Vector2f>&);
};