#include "HeroKnight.h"

HeroKnight::HeroKnight(sf::Texture* texture, sf::Vector2u imageCount, float switchTime):
	animation(texture, imageCount, switchTime) {
	
	row=0;
	
	
	heroKnight.setTexture(texture);
}

HeroKnight::~HeroKnight(){
}

void HeroKnight::Update(float deltaTime){
	animation.Update(row, deltaTime);
	heroKnight.setTextureRect(animation.uvRect);
}

void HeroKnight::drawTo(sf::RenderWindow &window){
	window.draw(heroKnight);
	
}
