#include "Mechanics.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Button.h"

#include "Animation.h"
#include "HeroKnight.h"
#include "King.h"
#include "Wizard.h"
#include "Monster.h"



///// Constructor function to create new memories for the struct pointers /////
Mechanics::Mechanics(){
	
	struct Status *entity;
	
    mStats = new Status;
    pStats = new Status;

    pStats->hpMax = new int;
    pStats->hpCur = new int;
    pStats->dmg = new int;

    mStats->hpMax = new int;
    mStats->hpCur = new int;
    mStats->dmg = new int;
    
}


void Mechanics::atkMechBtn(float dt, int classChoice){
	
	switch (classChoice){
        case 1:
            *(pStats->hpMax) = 500;
            *(pStats->hpCur) = *(pStats->hpMax);

            *(mStats->hpMax) = 1000;
            *(mStats->hpCur) = *(mStats->hpMax);
        break;
        case 2:
            *(pStats->hpMax) = 400;
            *(pStats->hpCur) = *(pStats->hpMax);

            *(mStats->hpMax) = 1000;
            *(mStats->hpCur) = *(mStats->hpMax);
        break;
        case 3:
            *(pStats->hpMax) = 300;
            *(pStats->hpCur) = *(pStats->hpMax);

            *(mStats->hpMax) = 1000;
            *(mStats->hpCur) = *(mStats->hpMax);
        break;
    }
    
	///// Render Window Game Play /////
	sf::RenderWindow gamePlay;
	gamePlay.create(sf::VideoMode(1920, 1080), "Summoner's Rift", sf::Style::None);
			
	///// Render Text Bar Game Play /////					
	Button btnText1("", {1920, 360}, 20, sf::Color::Black, sf::Color::Blue);
	btnText1.setPosition({0, 760});
	
	///// Render Button Choice For Light Attack ///// 
	Button btnChoice1("Light", {250, 100}, 30, sf::Color::Black, sf::Color::Blue); //membuat button untuk serangan "light"
	btnChoice1.setPosition({1280, 805});
	
	///// Render Button Choice For Medium Attack /////
	Button btnChoice2("Medium", {250, 100}, 30, sf::Color::Black, sf::Color::Blue); //membuat button untuk serangan "medium"
	btnChoice2.setPosition({1580, 805});
	
	
	///// Render Button Choice For Heavy Attack /////
	Button btnChoice3("Heavy", {250, 100}, 30, sf::Color::Black, sf::Color::Blue); //membuat button untuk serangan "heavy"
	btnChoice3.setPosition({1280, 940});
	
	///// Render Button Choice For Heal /////
	Button btnChoice4("Heal", {250, 100}, 30, sf::Color::Black, sf::Color::Blue); //membuat button untuk "heal"
	btnChoice4.setPosition({1580, 940});
	
	///// Render Texture For Background /////
	sf::Texture texture2;
	texture2.loadFromFile("Assets/background21.png");
	sf::Sprite bgTexture2;
	bgTexture2.setTexture(texture2);
	
	///// Load Button Font From File /////
	font.loadFromFile("Assets/Font.ttf");
	btnText1.setFont(font);
	btnChoice1.setFont(font);
	btnChoice2.setFont(font);
	btnChoice3.setFont(font);
	btnChoice4.setFont(font);
	
	//// Load Animation /////
	sf::Texture HerosKnightTexture;
	HerosKnightTexture.loadFromFile("Assets/HeroKnight2.png");
	
	HeroKnight Knights(&HerosKnightTexture, {10,6}, 0.1f);
	Knights.heroKnight.setPosition(300.0f,350.0f);
	Knights.heroKnight.setSize(sf::Vector2f(400.0f, 300.f));
	
	sf::Texture KingsTexture;
	KingsTexture.loadFromFile("Assets/king2.png");
	
	King Kingss(&KingsTexture, {4,1}, 0.25f);
	Kingss.king.setPosition(300.0f,175.0f);
	Kingss.king.setSize(sf::Vector2f(400.0f, 500.f));
	
	sf::Texture WizardsTexture;
	WizardsTexture.loadFromFile("Assets/wiz2.png");
	
	Wizard Wizz(&WizardsTexture, {8,1}, 0.12f);
	Wizz.wizard.setPosition(300.0f,270.0f);
	Wizz.wizard.setSize(sf::Vector2f(400.0f, 500.f));
	
	sf::Texture MonsterTexture;
	MonsterTexture.loadFromFile("Assets/Ghoul.png");

	Monster Ghoul(&MonsterTexture, {6,3}, 0.2f);
	Ghoul.monster.setPosition(1150.0f,380.0f);
	Ghoul.monster.setSize(sf::Vector2f(400.0f, 300.f));
	
	float deltaTime = 0.0f;
	sf::Clock clock;
	
	///// Load Music from file /////
	sf::Music battleMusic1;
	if(!battleMusic1.openFromFile("Assets/music1.ogg")){
			std::cout<<"ERROR"<<std::endl;
	}
	
	sf::Music battleMusic2;
	if(!battleMusic2.openFromFile("Assets/music2.ogg")){
			std::cout<<"ERROR"<<std::endl;
	}
	
	battleMusic2.play();
	battleMusic2.setVolume(30.f);
					
	battleMusic1.play();
	battleMusic1.setVolume(30.f);
	battleMusic1.setLoop(true);	
	
	///// Declaring Player HP Counter Font, Size, Color, and Position /////
	sf::Text hpCounter; 
	hpCounter.setFont(font);
	hpCounter.setCharacterSize(30);
	hpCounter.setFillColor(sf::Color::Red);
	hpCounter.setPosition(420, 660);
	
	///// Declaring Monster HP Counter Font, Size, Color, and Position /////
	sf::Text mhpCounter; 
	mhpCounter.setFont(font);
	mhpCounter.setCharacterSize(30);
	mhpCounter.setFillColor(sf::Color::Red);
	mhpCounter.setPosition(1230, 660);
	
	///// Declaring Game State Counter Font, Size, Color, and Position /////
	sf::Text gameStateTxt;
	gameStateTxt.setFont(font);
	gameStateTxt.setCharacterSize(20);
	gameStateTxt.setFillColor(sf::Color::Black);
	gameStateTxt.setPosition(300, 900);
	gameStateTxt.setString("Welcome to Summoner's Rift!");
	///// Integer for game conditions /////
	int cond = 1;
	
	///// While loop for the game to run on /////
	while(gamePlay.isOpen() && cond == 1){
		sf::Event ev3;	
		attackCD = 2;
		deltaTime = clock.restart().asSeconds();
		
		///// While loop for when the event is started /////
		while(gamePlay.pollEvent(ev3)){
			hpCounter.setString(patch::to_string((*pStats->hpCur)) + "/" + patch::to_string((*pStats->hpMax))); // Using patch.h functions to regenerate the text after damage has been dealt
			mhpCounter.setString(patch::to_string((*mStats->hpCur)) + "/" + patch::to_string((*mStats->hpMax))); // Using patch.h functions to regenerate the text after damage has been dealt
			
			///// Switch that decides what happens to the button /////
			switch(ev3.type){
				case sf::Event::Closed:
					gamePlay.close();
				break;
				case sf::Event::KeyPressed:
					if(ev3.key.code == sf::Keyboard::Escape){
						gamePlay.close();
					}
				case sf::Event::MouseMoved:
					if(btnChoice1.isMouseOver(gamePlay)){
						btnChoice1.setBackColor(sf::Color::White);
					} else {
						btnChoice1.setBackColor(sf::Color::Blue);
					}
					if(btnChoice2.isMouseOver(gamePlay)){
						btnChoice2.setBackColor(sf::Color::White);
					} else {
						btnChoice2.setBackColor(sf::Color::Blue);
					}
					if(btnChoice3.isMouseOver(gamePlay)){
						btnChoice3.setBackColor(sf::Color::White);
					} else {
						btnChoice3.setBackColor(sf::Color::Blue);
					}
					if(btnChoice4.isMouseOver(gamePlay)){
						btnChoice4.setBackColor(sf::Color::White);
					} else {
						btnChoice4.setBackColor(sf::Color::Blue);
					}
				break;		
				case sf::Event::MouseButtonReleased: 
					if(btnChoice1.isMouseOver(gamePlay)){ // Light Attack
						damage(mStats, 30, dt, 0); // To deal damage to the Monster
						damage(pStats, 30, dt, 2); // To deal damage to the Player
						gameCondition(mStats, 1); // To check the game condition
						gameCondition(pStats, 1);
						if(*(mStats->hpCur)== 0){
							gameStateTxt.setString("You won! Press Esc to exit the game.");
							if(sf::Event::KeyPressed){
								if(ev3.key.code == sf::Keyboard::Escape){
									gamePlay.close();	
								}
								
							}
						} else if(*(pStats->hpCur) == 0){
							gameStateTxt.setString("You Died. Press Esc to exit the game.");
						} else {
							gameStateTxt.setString("Welcome to Summoner's Rift!");
						}
					}
					if(btnChoice2.isMouseOver(gamePlay)){ // Medium Attack
						damage(mStats, 50, dt, 0); // To deal damage to the Monster
						damage(pStats, 50, dt, 2); // To deal damage to the Player
						gameCondition(mStats, 1); // To check the game condition
						gameCondition(pStats, 1);
						if(*(mStats->hpCur)== 0){
							gameStateTxt.setString("You won! Press Esc to exit the game.");
							if(sf::Event::KeyPressed){
								if(ev3.key.code == sf::Keyboard::Escape){
									gamePlay.close();	
								}
								
							}
						} else if(*(pStats->hpCur) == 0){
							gameStateTxt.setString("You Died. Press Esc to exit the game.");
						} else {
							gameStateTxt.setString("Welcome to Summoner's Rift!");
						}
					}
					if(btnChoice3.isMouseOver(gamePlay)){ // Heavy Attack
						damage(mStats, 75, dt, 0); // To deal damage to the Monster
						damage(pStats, 50, dt, 2); // To deal damage to the Player
						gameCondition(mStats, 1); // To check the game condition
						gameCondition(pStats, 1);
						if(*(mStats->hpCur)== 0){
							gameStateTxt.setString("You won! Press Esc to exit the game.");
							if(sf::Event::KeyPressed){
								if(ev3.key.code == sf::Keyboard::Escape){
									gamePlay.close();	
								}	
							}
						} else if(*(pStats->hpCur) == 0){
							gameStateTxt.setString("You Died. Press Esc to exit the game.");
						} else {
							gameStateTxt.setString("Welcome to Summoner's Rift!");
						}
					}
					if(btnChoice4.isMouseOver(gamePlay)){ 
						damage(pStats, -75, dt, 0); // To heal the player
					}
				break;	
			}	
		}
		
		
		///// Draws, renders, and clearing window (gamePlay) /////
		gamePlay.clear();
		gamePlay.draw(bgTexture2);
		btnText1.drawTo(gamePlay);
		gamePlay.draw(gameStateTxt);
		btnChoice1.drawTo(gamePlay);
		btnChoice2.drawTo(gamePlay);
		btnChoice3.drawTo(gamePlay);
		btnChoice4.drawTo(gamePlay);
		gamePlay.draw(hpCounter);
		gamePlay.draw(mhpCounter);
		
		Knights.Update(deltaTime);
		Kingss.Update(deltaTime);
		Wizz.Update(deltaTime);
		Ghoul.Update(deltaTime);
						
		switch(classChoice){
			case 1:
				Knights.drawTo(gamePlay);
				break;
			case 2:
				Kingss.drawTo(gamePlay);
				break;
			case 3:
				Wizz.drawTo(gamePlay);
				break;
		}
		Ghoul.drawTo(gamePlay);
		
		gamePlay.display();
	}
}	 

///// Function for damage mechanics, health deduction and cooldowns /////
void Mechanics::damage(struct Status *entity, int dmg, float dt, float CD){
	*entity->hpCur -= dmg;
	attackCD = CD;
	CD -= dt;

}

///// Function to determine the game condition (whether to terminate or continue) /////

int Mechanics::gameCondition(struct Status* entity, int cond)
{
    if (*entity->hpCur <= 0){
        *entity->hpCur = 0;
    	return cond = 0;
    } else {
        return cond = 1;
    }
    
} 









