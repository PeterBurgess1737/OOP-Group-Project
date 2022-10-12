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
                        "OOP Group Project");

    // Reducing the framerate to 60fps
    window.setFramerateLimit(60);

    // Create the manager
    GameManager manager(&window);

    // Where the event being handled is stored
    sf::Event event;

    int frame_number = 0;

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

        // Counting the frames
        frame_number++;

        // Adding in enemies
        if (!(frame_number % 60))
        {
            Entity *temp = new Entity;
            temp->health = 10;
            temp->max_speed = 2;
            temp->changeVelocity(-1.f, 0.f);
            temp->body.setSize(Vector2f(25.f, 25.f));
            temp->body.setPosition(1000.f, 300.f);
            temp->body.setFillColor(Color::Red);

            manager.addEnemy(temp);
        }

        // Adding in projectiles
        if (!(frame_number % 6))
        {
            Projectile *temp = new Projectile(Vector2f(100.f, 305.f), 5.f, Vector2f(1.f, 0), 1, true, 1000);

            manager.addProjectile(temp);
        }

        // Updates here
        manager.updateEnemies();
        manager.updateProjectiles();

        manager.deleteDeadEnemies();
        manager.deleteNecessaryProjectiles();

        // Drawing stuff
        window.clear();

        manager.drawEnemies();
        manager.drawProjectiles();

        // WOO
        window.display();
    }

    cout << "\n=============== End ===============\n"
         << endl;

    return 0;
}
