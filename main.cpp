#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Button.h"
#include "mainMenu.h"
#include "Mechanics.h"
#include "Animation.h"
#include "HeroKnight.h"
#include "King.h"
#include "Wizard.h"

int main(){
	
	int classChoice = 0;
	unsigned int row;
	mainMenu MainMenu;
	Mechanics gameMechanics;
	

   	sf::RenderWindow window;
    //sf::RenderWindow gamePlay;
    
	window.create(sf::VideoMode(1280, 720), "Joni Bizzare", sf::Style::Titlebar | sf::Style::Close);   
	
	window.setKeyRepeatEnabled(true);
	
	sf::Texture texture;
	texture.loadFromFile("Assets/background1.png");
	sf::Sprite bgTexture;
	bgTexture.setTexture(texture);
	
	sf::Texture texture2;
	texture2.loadFromFile("Assets/background3.png");
	
	sf::Sprite bgTexture2;
	bgTexture2.setTexture(texture2);
	
	sf::Texture texture3;
	texture3.loadFromFile("Assets/aboutback.png");
	sf::Sprite bgTexture3;
	bgTexture3.setTexture(texture3);	
	
	Button btn1("Play", {180, 90}, 30, sf::Color::Black, sf::Color::Transparent);
	btn1.setPosition({100, 200});
	
	Button btn2("About", {230, 90}, 30, sf::Color::Black, sf::Color::Transparent);
	btn2.setPosition({80, 310});
	
	Button btnEx("Exit", {180,90}, 30, sf::Color::Black, sf::Color::Transparent);
	btnEx.setPosition({100, 410});
	
	sf::Font font;
	font.loadFromFile("Assets/Font.ttf");
	btn1.setFont(font);
	btn2.setFont(font);
	btnEx.setFont(font);
	
	sf::RenderWindow game1;
					
	game1.create(sf::VideoMode(1280, 720), "Joni Bizzare", sf::Style::Titlebar | sf::Style::Close);
					
	Button btnJob1("Knight", {290, 90}, 30, sf::Color::White, sf::Color::Transparent);
	btnJob1.setPosition({160, 500});
									
	Button btnJob2("King", {200, 90}, 30, sf::Color::White, sf::Color::Transparent);
	btnJob2.setPosition({560, 500});
					
	Button btnJob3("Wizard", {300, 90}, 30, sf::Color::White, sf::Color::Transparent);
	btnJob3.setPosition({880, 500});
					
	font.loadFromFile("Assets/Font.ttf");
	btnJob1.setFont(font);
	btnJob2.setFont(font);
	btnJob3.setFont(font);
	
	//animasi
	
		
	sf::Texture HeroKnightTexture;
	HeroKnightTexture.loadFromFile("Assets/HeroKnight3.png");
	
	HeroKnight Knight(&HeroKnightTexture, {8,1}, 0.1f);
	Knight.heroKnight.setPosition(120.0f,220.0f);
	Knight.heroKnight.setSize(sf::Vector2f(400.0f, 350.f));
	
	sf::Texture KingTexture;
	KingTexture.loadFromFile("Assets/king1.png");
	
	King Kings(&KingTexture, {8,1}, 0.1f);
	Kings.king.setPosition(450.0f,20.0f);
	Kings.king.setSize(sf::Vector2f(400.0f, 500.f));
	
	sf::Texture WizardTexture;
	WizardTexture.loadFromFile("Assets/wiz1.png");
	
	Wizard Wiz(&WizardTexture, {6,1}, 0.1f);
	Wiz.wizard.setPosition(840.0f,125.0f);
	Wiz.wizard.setSize(sf::Vector2f(400.0f, 500.f));
	
	float deltaTime = 0.0f;
	sf::Clock clock;
	
	//musik
	sf::Music menuMusic;
	if(!menuMusic.openFromFile("Assets/music.ogg"))
		{
			std::cout<<"ERROR"<<std::endl;
		}
	menuMusic.play();
	menuMusic.setVolume(30.f);
	menuMusic.setLoop(true);
	
	// Main Menu Loop
	 while(window.isOpen()){
		deltaTime = clock.restart().asSeconds();
		sf::Event ev;
		game1.setVisible(false);
		
		while(window.pollEvent(ev)){
			switch(ev.type){
			case sf::Event::Closed:
				window.close();
				return 0;
			break;
			case sf::Event::MouseMoved:
				if(btn1.isMouseOver(window)){
					btn1.setBackColor(sf::Color::White);
			 	} else {
					btn1.setBackColor(sf::Color::Transparent);
				}
				if(btn2.isMouseOver(window)){
					btn2.setBackColor(sf::Color::White);
			 	} else {
					btn2.setBackColor(sf::Color::Transparent);
				}
				if(btnEx.isMouseOver(window)){
					btnEx.setBackColor(sf::Color::White);
			 	} else {
					btnEx.setBackColor(sf::Color::Transparent);
				}
			break; 
			case sf::Event::MouseButtonReleased:
				if(btn1.isMouseOver(window)){
					
					window.close();
					game1.setVisible(true);	
					
					while(game1.isOpen()){
						deltaTime = clock.restart().asSeconds();
						sf::Event ev2;			
						while(game1.pollEvent(ev2)){
							switch(ev2.type){
								case sf::Event::Closed:
									game1.close();
									
									return 0;
								break;
								case sf::Event::MouseMoved:
									if(btnJob1.isMouseOver(game1)){
										btnJob1.setBackColor(sf::Color::Black);
									 	} else {
										btnJob1.setBackColor(sf::Color::Transparent);
										}
									if(btnJob2.isMouseOver(game1)){
										btnJob2.setBackColor(sf::Color::Black);
									 	} else {
										btnJob2.setBackColor(sf::Color::Transparent);
										}
									if(btnJob3.isMouseOver(game1)){
										btnJob3.setBackColor(sf::Color::Black);
									 	} else {
										btnJob3.setBackColor(sf::Color::Transparent);
										}
								break;		
								case sf::Event::MouseButtonReleased:
									menuMusic.stop();
									if(btnJob1.isMouseOver(game1)){
										gameMechanics.atkMechBtn(deltaTime, 1);
									}
									if(btnJob2.isMouseOver(game1)){
										gameMechanics.atkMechBtn(deltaTime, 2);
									}
									if(btnJob3.isMouseOver(game1)){
										gameMechanics.atkMechBtn(deltaTime, 3);
									}
							}	
						}
						
						game1.clear();
						
						game1.draw(bgTexture2);
						btnJob1.drawTo(game1);
						btnJob2.drawTo(game1);
						btnJob3.drawTo(game1);
						
						Knight.Update(deltaTime);
						Kings.Update(deltaTime);
						Wiz.Update(deltaTime);
						
						Knight.drawTo(game1);
						Kings.drawTo(game1);
						Wiz.drawTo(game1);
						
						game1.display();
					}
				}
				if(btn2.isMouseOver(window)){
					MainMenu.DrawAbout();		
				}
				if(btnEx.isMouseOver(window)){
					return 0;
				}
			}
		} 
		window.clear();
		
		
		window.draw(bgTexture);
		btn1.drawTo(window);
		btn2.drawTo(window);
		btnEx.drawTo(window);
		window.display();
		
	} 
	window.close();
	
	

}

