#include "mainMenu.h"
#include "Button.h"
#include <iostream>

mainMenu::mainMenu() = default;

void mainMenu::DrawAbout() //untuk menampilkan About
{
	Button btn3("Back", {190,50}, 30, sf::Color::White, sf::Color::Transparent); //membuat tombol back, utnuk kemabli ke menu
	btn3.setPosition({20, 650});
	
	sf::Font font;
	font.loadFromFile("Assets/Font.ttf");
	btn3.setFont(font);
	
	About.create(sf::VideoMode(1280, 720), "Joni Bizzare", sf::Style::Titlebar | sf::Style::Close); //membuat window untuk about
	sf::Texture about;
	about.loadFromFile("Assets/background4.png");//background untuk about
		
		sf::Sprite abouts;
		abouts.setTexture(about);
		while(About.isOpen())
		{
			sf::Event event;
			while (About.pollEvent(event))
			{
				switch(event.type){
				    case sf::Event::Closed:
						About.close();
						break;
					case sf::Event::MouseButtonPressed:
						if (btn3.isMouseOver(About)) {
				            About.close();
			              	break;	
						} 
					case sf::Event::MouseMoved:
						if(btn3.isMouseOver(About)){ //ketika mouse diarahkan ke tombol back, maka background tombol akan berwarna putih
							btn3.setBackColor(sf::Color::White);
						} 
						else {
							btn3.setBackColor(sf::Color::Transparent);
						}
						break;
				}
				About.clear();
			    About.draw(abouts);
			    btn3.drawTo(About);
				About.display();
			}
		}
}
mainMenu::~mainMenu(){
    window.close();
    
}
