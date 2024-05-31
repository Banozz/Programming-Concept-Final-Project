#include "Wizard.h"

Wizard::Wizard(sf::Texture* texture, sf::Vector2u imageCount, float switchTime):
	animation(texture, imageCount, switchTime) {
	
	row=0;
	
	
	wizard.setTexture(texture);
}

Wizard::~Wizard(){
}

void Wizard::Update(float deltaTime){
	animation.Update(row, deltaTime);
	wizard.setTextureRect(animation.uvRect);
}

void Wizard::drawTo(sf::RenderWindow &window){
	window.draw(wizard);
	
}
