// Include necessary libraries. 
#include "Menu.h"
#include "SFML/Graphics.hpp"
#include <iostream>

// Implementation of constructing the menu page.
Menu::Menu(){
    window = new sf::RenderWindow();
    windowclose = new sf::RectangleShape;

    set_values();
}

Menu::~Menu(){
    delete window;
    delete windowclose;
}

// Implementation of setting the values on the menu screen.
void Menu::set_values(){
    window->create(sf::VideoMode(800,800), "MAIN MENU");
    window->setPosition(sf::Vector2i(0,0));

    // Set the coordinates of the mouse. 
    mouse_position = {0,0};
    mouse_coordinates = {0, 0};

    // Information for the buttons available to the user on the main menu. 
    options = {"Play", "Pause", "Resume", "Quit"};
    texts.resize(5);
    coordinates = {{590,40},{610,191},{590,282},{600,370}};
    sizes = {20,28,24,24};
}

// Implementation of the 'set values' function 

// Implementation of the 'loop events' function

// Implementation of the 'draw all' function

// Implementation of the 'run menu' function 