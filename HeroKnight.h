#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
class HeroKnight{
	public:
		HeroKnight(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
		~HeroKnight();
		
		void Update( float deltaTime);
		void drawTo(sf::RenderWindow &window);
		sf::RectangleShape heroKnight;
		
		unsigned int row;
	private:
		Animation animation;
		int i;
};
