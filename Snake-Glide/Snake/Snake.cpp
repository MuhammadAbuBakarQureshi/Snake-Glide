#include "Snake.h"

enum Direction dir;

using namespace std;

void addressSwap(vector<sf::Vector2f>& snake_pos) {

    for (int i = 0; i < snake_pos.size() - 1; i++) {

        swap(snake_pos.at(i).x, snake_pos.at(i + 1).x);
        swap(snake_pos.at(i).y, snake_pos.at(i + 1).y);
    }
}

// static variable

int Snake::score = 0;

// Movement

void Snake::move(vector<sf::RectangleShape>& snake, vector<sf::Vector2f>& snake_pos, sf::VideoMode video_mode) {

    switch (dir)
    {
    case RIGHT:

        moveRight(snake, snake_pos, video_mode);
        break;
    
    case LEFT:

        moveLeft(snake, snake_pos, video_mode);
        break;
    
    case UP:

        moveUp(snake, snake_pos, video_mode);
        break;

    case DOWN:

        moveDown(snake, snake_pos, video_mode);
        break;

    default:
        break;
    }
}

void updateSnake(sf::Vector2f head, vector<sf::RectangleShape>& snake, vector<sf::Vector2f>& snake_pos) {

    addressSwap(snake_pos);

    snake_pos.at(snake_pos.size() - 1) = head;

    for (int i = snake.size() - 1; i >= 0; i--) {

        snake.at(i).setPosition(snake_pos.at(i));
    }
}

void Snake::moveRight(vector<sf::RectangleShape>& snake, vector<sf::Vector2f>& snake_pos, sf::VideoMode video_mode)
{
    if (dir == LEFT) {return;}

    dir = RIGHT;

    sf::Vector2f head = snake_pos.at(snake_pos.size() - 1);

    head.x += snake_speed;

    if (head.x <= video_mode.width) {

        updateSnake(head, snake, snake_pos);
    }
}

void Snake::moveLeft(vector<sf::RectangleShape>& snake, vector<sf::Vector2f>& snake_pos, sf::VideoMode video_mode)
{
    if (dir == RIGHT) { return; }

    dir = LEFT;

    sf::Vector2f head = snake_pos.at(snake_pos.size() - 1);

    head.x += -snake_speed;

    if (head.x >= 0) {

        updateSnake(head, snake, snake_pos);
    }
}

void Snake::moveUp(vector<sf::RectangleShape>& snake, vector<sf::Vector2f>& snake_pos, sf::VideoMode video_mode)
{
    if (dir == DOWN) { return; }

    dir = UP;

    sf::Vector2f head = snake_pos.at(snake_pos.size() - 1);

    head.y += -snake_speed;

    if (head.y >= 0) {

        updateSnake(head, snake, snake_pos);
    }
}

void Snake::moveDown(vector<sf::RectangleShape>& snake, vector<sf::Vector2f>& snake_pos, sf::VideoMode video_mode)
{
    if (dir == UP) { return; }

    dir = DOWN;

    sf::Vector2f head = snake_pos.at(snake_pos.size() - 1);

    head.y += snake_speed;

    if (head.y <= video_mode.height) {

        updateSnake(head, snake, snake_pos);
    }
}



// Is Killed

bool Snake::isKilledByItself(vector<sf::RectangleShape>& snake, vector<sf::Vector2f>& snake_pos) {

    // This code executed when snake hit itself

    float head_column = snake_pos.at(snake.size() - 1).x;
    float head_row = snake_pos.at(snake.size() - 1).y;

    for(int i = 0; i < snake.size() - 2; i++){

        if (head_column == snake_pos.at(i).x && head_row == snake_pos.at(i).y) {

            return true;
        }
    }

    return false;
}

bool Snake::isKilledByWall(vector<sf::Vector2f> snake_pos, sf::VideoMode video_mode){

    int wall_x = video_mode.width;
    int wall_y = video_mode.height;
    float head_x = snake_pos.at(snake_pos.size() - 1).x;
    float head_y = snake_pos.at(snake_pos.size() - 1).y;

    // Max sides

    if (head_x == wall_x || head_y == wall_y) {
        
        return true;
    }

    // Min sides

    if (head_x == 0 || head_y == 0) {

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

    score++;

    //snake.push_back(254);
    //snake_x.push_back(x);
    //snake_y.push_back(y);
    //int snake_head = snake.size() - 1;

    //dim.setCursorPosition(snake_x.at(snake_head), snake_y.at(snake_head));
    //cout << snake.at(0);
}
