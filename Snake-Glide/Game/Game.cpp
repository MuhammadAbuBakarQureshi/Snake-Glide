#include "Game.h"
//
//#include "../Snake/Snake.h"
#include "../Target/Target.h"
//
//using namespace std;

Target target_obj;

void Game::generateTarget()
{
    target_pos = target_obj.targetGeneration(video_mode);

    target.setPosition(target_pos);

    score++;
}

void Game::initVariables()
{
    //this->window = nullptr;

    // Init Window size

    //this->video_mode.height = 800;
    //this->video_mode.width = 1000;

    // Creating target

    target.setSize(sf::Vector2f(10.f, 10.f));
    target.setOrigin(0, 5);
    target.setFillColor(sf::Color(255, 0, 0));

    // updating target

    generateTarget();

    main_menu = false;

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

Game::Game(sf::VideoMode video_mode)
{
    this->video_mode = video_mode;

    initVariables();
    //initWindow();
    initSnake();
}
//
//// Destructor



// Game

void Game::keyboardInput(sf::RenderWindow* window)
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

    if (target_obj.isTargetHit(snake, snake_pos, snake_movement) == true) { generateTarget(); }


    // checks if it is hit by wall or itself

    //isKilledInGame(snake_movement.isKilledByItself(snake, snake_pos), window);

    //isKilledInGame(snake_movement.isKilledByWall(snake_pos, video_mode), window);
}

// Poll Event

void Game::pollEvent(sf::RenderWindow* window)
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

void Game::updateTarget(sf::RenderWindow* window)
{

}

void Game::updateSnake(sf::RenderWindow* window){

    this->keyboardInput(window);
}

void Game::update(sf::RenderWindow* window)
{

    this->pollEvent(window);

    updateSnake(window);

    updateTarget(window);
}

// Render

void Game::renderTarget(sf::RenderWindow* window)
{

    window->draw(target);
}

void Game::renderSnake(sf::RenderWindow* window) {

    for (auto& s : snake) {

        window->draw(s);
    }
}

void Game::render(sf::RenderWindow* window)
{

    window->clear(sf::Color(0, 31, 63));

    renderSnake(window);
    
    renderTarget(window);

    window->display();
}

void Game::run(sf::RenderWindow* window, sf::Event evnt)
{
    this->evnt = evnt;

    Snake snake_movement;

    while (!snake_movement.isKilledByWall(snake_pos, video_mode) && !snake_movement.isKilledByItself(snake, snake_pos)) {

        // Update

        update(window);

        // Render

        render(window);
    }

    cout << score << endl;
    
}
