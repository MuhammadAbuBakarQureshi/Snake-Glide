#include "MainMenu.h"

#include <sstream>

void MainMenu::initVariables()
{
    this->window = nullptr;

    // Init Window size

    this->video_mode.height = 800;
    this->video_mode.width = 1000;

}

void MainMenu::initWindow()
{
    this->window = new sf::RenderWindow(this->video_mode, "Snake Game", sf::Style::Titlebar);
}

void MainMenu::scoreWindow(Game game)
{

    Button main_menu("Main Menu");
    main_menu.setColors(sf::Color(20, 20, 60), sf::Color(128, 180, 255));
    main_menu.setButtonPosition(sf::Vector2f(370, 340));
    main_menu.setTextPosition(sf::Vector2f(440, 365));

    while (true) {

        if (main_menu.isClick(*window, evnt)) {

            break;
        }

        this->window->clear(sf::Color(0, 31, 63));

        sf::Text text;

        text.move(460, 260);

        sf::Font font;

        font.loadFromFile("Fonts/Score/VT323-Regular.ttf");

        text.setFont(font);

        int score = game.getScore();

        stringstream s;

        s << score;

        text.setString(s.str().c_str());

        text.setCharacterSize(40);

        text.setFillColor(sf::Color(255, 255, 0));

        text.setStyle(sf::Text::Bold);

        window->draw(text);

        main_menu.render(*window);

        this->window->display();

    }
}

MainMenu::MainMenu()
{

    initVariables();
    initWindow();
}

MainMenu::~MainMenu()
{
    delete this->window;
}

void MainMenu::gameLoop()
{
    Button start_game("Start Game");
    start_game.setColors(sf::Color(20, 20, 60), sf::Color(128, 180, 255));
    start_game.setButtonPosition(sf::Vector2f(370, 230));
    start_game.setTextPosition(sf::Vector2f(430, 255));

    Button exit("Exit");
    exit.setColors(sf::Color(20, 20, 60), sf::Color(128, 180, 255));
    exit.setButtonPosition(sf::Vector2f(370, 400));
    exit.setTextPosition(sf::Vector2f(490, 425));

    while (this->window->isOpen()) {

        if (start_game.isClick(*window, evnt)) {

            Game game(window, evnt, video_mode);

            game.run();

            //scoreWindow(game);
        }

        if(exit.isClick(*window, evnt)){

            this->window->close();
        }

        this->window->clear(sf::Color(0, 31, 63));
        updateTitle();
        start_game.render(*window);
        exit.render(*window);
        this->window->display();
    }
}

void MainMenu::updateScore()
{
    
    
}

void MainMenu::updateTitle()
{
    sf::Text text;

    text.move(290, 100);

    sf::Font font;

    font.loadFromFile("Fonts/Title/PressStart2P.ttf");

    text.setFont(font);

    text.setString("SNAKE GLIDE");

    text.setCharacterSize(40);

    text.setFillColor(sf::Color(255, 255, 0));

    text.setStyle(sf::Text::Bold);

    window->draw(text);
}

void MainMenu::update()
{
}

void MainMenu::render()
{
}
