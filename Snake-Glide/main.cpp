#include "Game/Game.h"
#include "Button/Button.h"
#include "Main Menu/MainMenu.h"

using namespace std;

int WinMain() {

	//Game game;

	//Button start_game("Start Game");
	//start_game.setColors(sf::Color(20, 20, 60), sf::Color(128, 180, 255));
	//start_game.setButtonPosition(sf::Vector2f(355, 200));
	//start_game.setTextPosition(sf::Vector2f(440, 220));

	//Button exit("Exit");
	//exit.setColors(sf::Color(20, 20, 60), sf::Color(128, 180, 255));
	//exit.setButtonPosition(sf::Vector2f(355, 400));
	//exit.setTextPosition(sf::Vector2f(480, 420));

	//while (game.isRunning()) {

	//	game.update();

	//	game.render();
	//}

	MainMenu menu;

	menu.gameLoop();

	return 0;
}