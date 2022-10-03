#include <iostream>
using std::cout;
using std::endl;

#include <SFML/Graphics.hpp>
using sf::RenderWindow;
using sf::CircleShape;
using sf::RectangleShape;

#include <SFML/System.hpp>
using sf::Vector2f;

#include "classes.h"

int main()
{
    cout << "\n========== Program Start ==========\n"
         << endl;

    // Create the window
    RenderWindow window(sf::VideoMode(1280, 720),
                        "OOP Group Project");

    // Create the game manager
    GameManager manager(window);

    // Create an enemy
    BasicEnemy someEnemy(Vector2f(10.f, 10.f));

    // Add the enemy
    manager.addEnemy(&someEnemy);

    // Where the event being handled is stored
    sf::Event event{};

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

        // Drawing stuff
        window.clear();
        manager.drawEnemies();

        // WOO
        window.display();
    }

    cout << "\n=============== End ===============\n"
         << endl;

    return 0;
}