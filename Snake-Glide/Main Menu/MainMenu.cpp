#include "MainMenu.h"


void MainMenu::initVariables()
{
    this->window = nullptr;

    // Init Window size

    this->video_mode.height = 800;
    this->video_mode.width = 1000;

    // Main Menu

    main_menu = true;
}

void MainMenu::initWindow()
{
    this->window = new sf::RenderWindow(this->video_mode, "Snake Game", sf::Style::Close);
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

void MainMenu::main_menu_window(Button& strt, Button& ex) {

	while (main_menu) {
		if (strt.isClick(*window, evnt)) {
			
            main_menu = false;
		}

		if (ex.isClick(*window, evnt)) {

			this->window->close();
            main_menu = false;
		}
		this->window->clear(sf::Color(0, 31, 63));
		strt.render(*window);
		ex.render(*window);
		this->window->display();
	}
}

void MainMenu::gameLoop()
{

    Button start_game("Start Game");
    start_game.setColors(sf::Color(20, 20, 60), sf::Color(128, 180, 255));
    start_game.setButtonPosition(sf::Vector2f(355, 200));
    start_game.setTextPosition(sf::Vector2f(440, 220));

    Button exit("Exit");
    exit.setColors(sf::Color(20, 20, 60), sf::Color(128, 180, 255));
    exit.setButtonPosition(sf::Vector2f(355, 400));
    exit.setTextPosition(sf::Vector2f(480, 420));

    while (this->window->isOpen()) {

        if (start_game.isClick(*window, evnt)) {

            Game game(video_mode);

            game.run(window, evnt);
        }

        if(exit.isClick(*window, evnt)){

            this->window->close();
        }

        this->window->clear(sf::Color(0, 31, 63));
        start_game.render(*window);
        exit.render(*window);
        this->window->display();
    }

}

void MainMenu::update()
{
}

void MainMenu::render()
{
}
