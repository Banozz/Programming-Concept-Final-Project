#include "Button.h"

Button::Button(std::string t, sf::Vector2f size, int charSize, sf::Color textColor, sf::Color btnColor){
	text.setString(t);
	text.setColor(textColor);
	text.setCharacterSize(charSize);

	button.setSize(size);
	button.setFillColor(btnColor);
}

void Button::setFont(sf::Font &font){
	text.setFont(font);
}

void Button::setBackColor(sf::Color color){
	button.setFillColor(color);
}

void Button::setTextColor(sf::Color color){
	text.setColor(color);
}

void Button::setPosition(sf::Vector2f pos){
	button.setPosition(pos);
	
	float xPos = (pos.x + button.getLocalBounds().width/7.5) - (text.getLocalBounds().width/2);
	float yPos = (pos.y + button.getLocalBounds().height/2.5) - (text.getLocalBounds().height/2);
	text.setPosition({xPos, yPos});
}

bool Button::isMouseOver(sf::RenderWindow &window){
	float xMouse = sf::Mouse::getPosition(window).x;
	float yMouse = sf::Mouse::getPosition(window).y;
	
	float btnPosX = button.getPosition().x;
	float btnPosY = button.getPosition().y;
	
	float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
	float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;
	
	if(xMouse < btnxPosWidth && xMouse > btnPosX && yMouse < btnyPosHeight && yMouse > btnPosY){
		return true;
	} 
	return false;	
}

void Button::drawTo(sf::RenderWindow &window){
	window.draw(button);
	window.draw(text);
}
