#include "Monster.h"

Monster::Monster(sf::Texture* texture, sf::Vector2u imageCount, float switchTime):
	animation(texture, imageCount, switchTime) {
	row=0;
	monster.setTexture(texture);
}

Monster::~Monster(){
}

void Monster::Update(float deltaTime){
	animation.Update(row, deltaTime);
	monster.setTextureRect(animation.uvRect);
}

void Monster::drawTo(sf::RenderWindow &window){
	window.draw(monster);
	
}
