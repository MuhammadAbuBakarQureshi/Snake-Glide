#include "Button.h"

void Button::initVariables(string text)
{
	// Set Button

	this->button_size.x = 300;
	this->button_size.y = 70;

	this->button.setSize(button_size);

	// Set Text

	this->text.setString(text);

	// Set Size

	this->text.setCharacterSize(24);

	// Set Font

	font.loadFromFile("Fonts/Buttons/tipo.ttf");

	this->text.setFont(font);
}

Button::Button(string text)
{
	initVariables(text);
}

Button::~Button()
{
}

void Button::setColors(sf::Color button_color, sf::Color text_color)
{
	this->button_color = button_color;
	this->text_color = text_color;
	this->button.setFillColor(this->button_color);
	this->text.setFillColor(text_color);
}


void Button::setButtonPosition(sf::Vector2f button_pos)
{
	this->button.setPosition(button_pos);
	this->button_position = button_pos;
}

void Button::setTextPosition(sf::Vector2f text_pos)
{
	this->text.setPosition(text_pos);
}

void Button::setText(string text)
{
	this->text.setString(text);
}


bool Button::isMouseOnButton(sf::RenderWindow& window)
{
	sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

	if (mouse_position.x > button_position.x && mouse_position.y > button_position.y
		&& mouse_position.x < button_position.x + button_size.x 
		&& mouse_position.y < button_position.y + button_size.y) {

		return true;
	}

	return false;
}

bool Button::isClick(sf::RenderWindow& window, sf::Event evnt)
{
	if (isHover(window, evnt)) {

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			this->button.setFillColor(sf::Color(0, 85, 170));
			this->text.setFillColor(sf::Color(204, 204, 0));

			return true;
		}
	}

	return false;
}

bool Button::isHover(sf::RenderWindow& window, sf::Event evnt)
{
	sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

	if (isMouseOnButton(window)){
	
		this->button.setFillColor(sf::Color(0, 170, 255));
		this->text.setFillColor(sf::Color(255, 255, 128));
		return true;

		//cout << "--- Mouse X = " << mouse_position.x << " Y = " << mouse_position.y << endl;
	}
	else {

		//cout << "Button  x = " << button_position.x << " Y = " << button_position.y
			//<< "--- Mouse X = " << mouse_position.x << " Y = " << mouse_position.y << endl;


		this->button.setFillColor(button_color);
		this->text.setFillColor(text_color);

		return false;
	}
}

void Button::update(sf::RenderWindow& window, sf::Event evnt)
{
}

void Button::render(sf::RenderWindow& window)
{
	window.draw(button);
	window.draw(text);
}
