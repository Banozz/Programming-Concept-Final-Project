#include "King.h"

King::King(sf::Texture* texture, sf::Vector2u imageCount, float switchTime):
	animation(texture, imageCount, switchTime) {
	
	row=0;
	
	king.setTexture(texture);
}

King::~King(){
}

void King::Update(float deltaTime){
	animation.Update(row, deltaTime);
	king.setTextureRect(animation.uvRect);
}

void King::drawTo(sf::RenderWindow &window){
	window.draw(king);
	
}
