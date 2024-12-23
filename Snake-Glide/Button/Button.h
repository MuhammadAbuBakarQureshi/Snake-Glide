#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

class Button
{
private:
	
	sf::Text text;
	sf::Font font;
	sf::RectangleShape button;
	sf::Color button_color;
	sf::Vector2f button_size;
	sf::Vector2f button_position;
	
	void initVariables(string);
	
public:

	Button(string);
	~Button();

	// Initialization

	void setColors(sf::Color, sf::Color);
	void setButtonPosition(sf::Vector2f);
	void setTextPosition(sf::Vector2f);

	// Functions on Button

	bool isMouseOnButton(sf::RenderWindow&);
	bool isHover(sf::RenderWindow&, sf::Event);
	bool isClick(sf::RenderWindow&, sf::Event);



	void update(sf::RenderWindow&, sf::Event);
	void render(sf::RenderWindow&);
};