#include "Snake.h"

using namespace std;

enum Direction dir;

void addressSwap(vector<sf::Vector2f>& snake_pos) {

    for (int i = 0; i < snake_pos.size() - 1; i++) {

        swap(snake_pos.at(i).x, snake_pos.at(i + 1).x);
        swap(snake_pos.at(i).y, snake_pos.at(i + 1).y);
    }
}

// Movement

void Snake::initSnake()
{

    sf::Color clr(0, 191, 255);

    snake.push_back(sf::RectangleShape(sf::Vector2f(10.f, 10.f)));
    snake.push_back(sf::RectangleShape(sf::Vector2f(10.f, 10.f)));
    snake.push_back(sf::RectangleShape(sf::Vector2f(10.f, 10.f)));
    snake.push_back(sf::RectangleShape(sf::Vector2f(10.f, 10.f)));

    for (int i = 0; i < 4; i++) {

        snake.at(i).setOrigin(5, 5);
        snake.at(i).setFillColor(clr);
    }

    // Head with different color

    snake.at(3).setFillColor(sf::Color(255, 165, 0));

    float head = 70;
    float speed = 10;

    snake.at(0).setPosition(head, 100);
    snake.at(1).setPosition(head + speed, 100);
    snake.at(2).setPosition(head + speed + speed, 100);
    snake.at(3).setPosition(head + speed + speed + speed, 100);

    snake_pos.push_back(snake.at(0).getPosition());
    snake_pos.push_back(snake.at(1).getPosition());
    snake_pos.push_back(snake.at(2).getPosition());
    snake_pos.push_back(snake.at(3).getPosition());
}

Snake::Snake(sf::RenderWindow& window,sf::VideoMode video_mode)
{
    this->video_mode = video_mode;

    this->window = &window;

    initSnake();
}

void Snake::snakeInput(sf::RenderWindow& window, sf::VideoMode video_mode)
{
    this->window = &window;
    this->video_mode = video_mode;

    initSnake();
}

void Snake::move() {

    switch (dir)
    {
    case RIGHT:

        moveRight();
        break;
    
    case LEFT:

        moveLeft();
        break;
    
    case UP:

        moveUp();
        break;

    case DOWN:

        moveDown();
        break;

    default:
        break;
    }
}

void Snake::moveRight()
{
    if (dir == LEFT) {return;}

    dir = RIGHT;

    sf::Vector2f head = snake_pos.at(snake_pos.size() - 1);

    head.x += snake_speed;

    if (head.x <= video_mode.width) {

        update(head);
    }
}

void Snake::moveLeft()
{
    if (dir == RIGHT) { return; }

    dir = LEFT;

    sf::Vector2f head = snake_pos.at(snake_pos.size() - 1);

    head.x += -snake_speed;

    if (head.x >= 0) {

        update(head);
    }
}

void Snake::moveUp()
{
    if (dir == DOWN) { return; }

    dir = UP;

    sf::Vector2f head = snake_pos.at(snake_pos.size() - 1);

    head.y += -snake_speed;

    if (head.y >= 0) {

        update(head);
    }
}

void Snake::moveDown()
{
    if (dir == UP) { return; }

    dir = DOWN;

    sf::Vector2f head = snake_pos.at(snake_pos.size() - 1);

    head.y += snake_speed;

    if (head.y <= video_mode.height) {

        update(head);
    }
}



// Is Killed

void Snake::update(sf::Vector2f head)
{
    addressSwap(snake_pos);

    snake_pos.at(snake_pos.size() - 1) = head;

    for (int i = snake.size() - 1; i >= 0; i--) {

        snake.at(i).setPosition(snake_pos.at(i));
    }
}

void Snake::render()
{
    for (auto& s : snake) {

        window->draw(s);
    }
}

bool Snake::isKilledByItself() {

    // This code executed when snake hit itself

    float head_column = snake_pos.at(snake.size() - 1).x;
    float head_row = snake_pos.at(snake.size() - 1).y;

    for(int i = 0; i < snake.size() - 2; i++){

        if (head_column == snake_pos.at(i).x && head_row == snake_pos.at(i).y) {

            dir = RIGHT;
            return true;
        }
    }

    return false;
}

bool Snake::isKilledByWall(){

    int wall_x = video_mode.width;
    int wall_y = video_mode.height;
    float head_x = snake_pos.at(snake_pos.size() - 1).x;
    float head_y = snake_pos.at(snake_pos.size() - 1).y;

    // Max sides

    if (head_x == wall_x || head_y == wall_y) {

        dir = RIGHT;
        return true;
    }

    // Min sides

    if (head_x == 0 || head_y == 0) {

        dir = RIGHT;
        return true;
    }

    return false;
}



// Increase Length

void Snake::increaseLength(vector<sf::RectangleShape>& snake, vector<sf::Vector2f>& snake_pos)
{

    sf::RectangleShape head = snake.at(snake.size() - 1);

    snake.push_back(head);

    sf::RectangleShape snake_box = sf::RectangleShape(sf::Vector2f(10.f, 10.f));
    snake_box.setOrigin(5.f, 5.f);
    snake_box.setFillColor(sf::Color(0, 191, 255));

    snake.at(snake.size() - 2) = snake_box;

    sf::Vector2f new_box;

    switch (dir)
    {
    case RIGHT:

        new_box.x = snake_pos.at(snake_pos.size() - 1).x + snake_speed;
        new_box.y = snake_pos.at(snake_pos.size() - 1).y;
        snake_pos.push_back(new_box);
        break;
    case LEFT:

        new_box.x = snake_pos.at(snake_pos.size() - 1).x - snake_speed;
        new_box.y = snake_pos.at(snake_pos.size() - 1).y;
        snake_pos.push_back(new_box);
        break;
    case UP:

        new_box.y = snake_pos.at(snake_pos.size() - 1).y - snake_speed;
        new_box.x = snake_pos.at(snake_pos.size() - 1).x;
        snake_pos.push_back(new_box);

        break;
    case DOWN:

        new_box.y = snake_pos.at(snake_pos.size() - 1).y + snake_speed;
        new_box.x = snake_pos.at(snake_pos.size() - 1).x;
        snake_pos.push_back(new_box);
        break;
    }
}
