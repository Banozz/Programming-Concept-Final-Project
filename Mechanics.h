#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "patch.h"

class Mechanics
{
	public:
		Mechanics();
		struct Status{ 
			int *hpMax; 
			int *hpCur; 
			int *dmg;
		};
		
		struct Status entity;
		
		Status* mStats;
    	Status* pStats;
		
		int light();
		int medium();
		int heavy();
		void updateHUD();
		float attackCD;
		
		//void attackMechanics(int classChoice);
		void damage(struct Status *entity, int, float, float);
		void atkMechBtn(float, int);
		int gameCondition(struct Status *entity, int);
		int gameState(int stCh2);
		
		unsigned int row;
		
	private:
		sf::Font font;
		sf::Text text;
		sf::Text hpCounter;
		sf::RenderWindow gamePlay;
		sf::Text gameStateTxt;
		sf::Texture Knights;
};
