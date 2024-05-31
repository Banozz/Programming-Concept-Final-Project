#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
class King{
	public:
		King(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
		~King();
		
		void Update(float deltaTime);
		void drawTo(sf::RenderWindow &window); //untuk menampilkan button
		sf::RectangleShape king;
		
		unsigned int row;
	private:
		Animation animation;
		
		
		int i;
};
