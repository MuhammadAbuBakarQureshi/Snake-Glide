#include "Game.h"

#include "../Target/Target.h"

Target target_obj;
Snake snake_movement;

void Game::initVariables()
{
    // Snake 

    snake_movement.snakeInput(*window, video_mode);

    // Creating target

    target.setSize(sf::Vector2f(10.f, 10.f));
    target.setOrigin(0, 5);
    target.setFillColor(sf::Color(255, 0, 0));

    // updating target

    updateTarget();
        
    score = 0;
}

//// Constructor

Game::Game(sf::RenderWindow* window, sf::Event evnt, sf::VideoMode video_mode)
{
    this->window = window;
    this->video_mode = video_mode;
    this->evnt = evnt;

   
    initVariables();
    //initSnake();
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

    snake_movement.move();

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {

        snake_movement.moveLeft();
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {

        snake_movement.moveUp();
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {

        snake_movement.moveDown();
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {

        snake_movement.moveRight();
    }

    this_thread::sleep_for(chrono::microseconds(50000));

    // checks is target is hit

   // if (target_obj.isTargetHit(snake, snake_pos, snake_movement) == true) { updateTarget(); }


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

void Game::update()
{

    this->pollEvent();

    this->keyboardInput();
}

// Render

void Game::renderTarget()
{

    window->draw(target);
}

void Game::render()
{

    window->clear(sf::Color(0, 31, 63));

    snake_movement.render();

    renderTarget();

    window->display();
}

void Game::run()
{
   
    while (!snake_movement.isKilledByWall() && !snake_movement.isKilledByItself()) {

        // Update

        update();

        // Render

        render();
    }

    cout << score << endl;
    
}
