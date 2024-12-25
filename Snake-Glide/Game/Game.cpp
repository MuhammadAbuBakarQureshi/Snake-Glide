#include "Game.h"

#include "../Target/Target.h"

Target target_obj;

void Game::initVariables()
{
    // Creating target

    target.setSize(sf::Vector2f(10.f, 10.f));
    target.setOrigin(0, 5);
    target.setFillColor(sf::Color(255, 0, 0));

    // updating target

    updateTarget();
        
    score = 0;
}

void Game::initSnake()
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

//// Constructor

Game::Game(sf::RenderWindow* window, sf::Event evnt, sf::VideoMode video_mode)
{
    this->window = window;
    this->video_mode = video_mode;
    this->evnt = evnt;

        
    initVariables();
    initSnake();
}
int Game::getScore()
{
    return score;
}
//
//// Destructor



// Game

void Game::keyboardInput()
{

    Snake snake_movement;

    snake_movement.move(snake, snake_pos, video_mode);

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {

        snake_movement.moveLeft(snake, snake_pos, video_mode);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {

        snake_movement.moveUp(snake, snake_pos, video_mode);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {

        snake_movement.moveDown(snake, snake_pos, video_mode);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {

        snake_movement.moveRight(snake, snake_pos, video_mode);
    }

    this_thread::sleep_for(chrono::microseconds(50000));

    // checks is target is hit

    if (target_obj.isTargetHit(snake, snake_pos, snake_movement) == true) { updateTarget(); }


    // checks if it is hit by wall or itself

    //isKilledInGame(snake_movement.isKilledByItself(snake, snake_pos), window);

    //isKilledInGame(snake_movement.isKilledByWall(snake_pos, video_mode), window);
}

// Poll Event

void Game::pollEvent()
{
    while (window->pollEvent(evnt)) {

        switch (evnt.type)
        {
        case sf::Event::Closed:

            cout << "Closing Window" << endl;
            window->close();
            break;

        case sf::Event::KeyPressed:

            if (evnt.key.code == sf::Keyboard::Escape) {

                cout << "Closing Window" << endl;
                window->close();
            }
            break;
        }
    }
}

// Update

void Game::updateTarget()
{

    target_pos = target_obj.targetGeneration(video_mode);

    target.setPosition(target_pos);

    score++;
}

void Game::updateSnake(){

    this->keyboardInput();
}

void Game::update()
{

    this->pollEvent();

    updateSnake();
}

// Render

void Game::renderTarget()
{

    window->draw(target);
}

void Game::renderSnake() {

    for (auto& s : snake) {

        window->draw(s);
    }
}

void Game::render()
{

    window->clear(sf::Color(0, 31, 63));

    renderSnake();
    
    renderTarget();

    window->display();
}

void Game::run()
{
    Snake snake_movement;

    while (!snake_movement.isKilledByWall(snake_pos, video_mode) && !snake_movement.isKilledByItself(snake, snake_pos)) {

        // Update

        update();

        // Render

        render();
    }

    cout << score << endl;
    
}
