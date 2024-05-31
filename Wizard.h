#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
class Wizard{
	public:
		Wizard(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
		~Wizard();
		
		void Update( float deltaTime);
		void drawTo(sf::RenderWindow &window); //untuk menampilkan button
		sf::RectangleShape wizard;
		
		unsigned int row;
	private:
		Animation animation;
		
		
		int i;
};
