#include <iostream>
using std::cout;
using std::endl;

#include <cmath>
using std::sqrt;

#include <SFML/Graphics.hpp>
using sf::RenderWindow;
using sf::CircleShape;
using sf::RectangleShape;
using sf::Color;

#include <SFML/System.hpp>
using sf::Vector2f;

#include "GameLibrary/GameLibrary.h"

int main()
{
    cout << "\n========== Program Start ==========\n"
         << endl;

    // Create the window
    RenderWindow window(sf::VideoMode(1280, 720),
                        "Menu Test");

    // Reducing the framerate to 60fps
    window.setFramerateLimit(60);

    // Create the manager and pass the necessary stuff to it
    GameManager manager(&window);

    // Where the event being handled is stored
    sf::Event event;

    // Game loop
    while (window.isOpen())
    {
        // Event handler
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed: // Window closed
                    window.close();
                    break;

                case sf::Event::KeyPressed: // Escape key pressed
                    if (event.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
                default:
                    break;
            }
        }

        // Drawing entities
        window.clear();

        manager.drawPlayer();
        manager.drawEnemies();

        window.display();
    }

    cout << "\n=============== End ===============\n"
         << endl;

    return 0;
}