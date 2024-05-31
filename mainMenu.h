#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>

class mainMenu
{
private:
    sf::Font font;
    sf::RenderWindow window;
    sf::RenderWindow game1;
    sf::RenderWindow About;

    //Defining texture and image for background
    sf::Texture image;
    sf::Sprite loadImage;

public:
    mainMenu();
    ~mainMenu();
    void DrawAbout();
};
