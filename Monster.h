#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
class Monster{
	public:
		Monster(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
		~Monster();
		
		void Update( float deltaTime);
		void drawTo(sf::RenderWindow &window); //untuk menampilkan button
		sf::RectangleShape monster;
		
		unsigned int row;
		
	private:
		Animation animation;
		int i;
};
