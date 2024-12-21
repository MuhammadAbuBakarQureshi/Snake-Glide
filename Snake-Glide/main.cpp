#include "Game/Game.h"

using namespace std;

int main() {

	Game game;

	while (game.isRunning()) {

		game.update();

		game.render();
	}

	cout << "Total Score = " << Snake::score << endl;

	sf::RenderWindow window(sf::VideoMode(1000, 800), "Game", sf::Style::Default);

	while (window.isOpen()) {

		sf::Event ev;

		while (window.pollEvent(ev)) {

			switch (ev.type)
			{
			case sf::Event::Closed:

				window.close();
				break;
			}
		}

		window.clear(sf::Color(0, 31, 63));
		window.display();
	}

	return 0;
}