/*#pragma once
#include "Mechanics.h"
#include <SFML/Graphics.hpp>

class Entity
{
	private:
		sf::RenderWindow &window;
	public:
		int manaCost;
		
		struct Status{
			int *hpMax; 
			int *hpCur; 
			int *manaMax; 
			int *manaCur;
			int *dmg; 	
		};
		
		classEntity(struct Status, int);
		
		void drawEntity(sf::RenderWindow &window);
		
		// void manaRed(struct status *stats, int);
		
		int light(int);
		int medium(int);
		int heavy(int);
}; */

