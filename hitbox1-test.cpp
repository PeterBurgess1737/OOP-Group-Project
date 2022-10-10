#include <iostream>
using std::cout;
using std::endl;

#include <cmath>
using std::sqrt;

#include <SFML/Graphics.hpp>
using sf::CircleShape;
using sf::Color;
using sf::RectangleShape;
using sf::RenderWindow;

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

    // Entities to play with
    Entity unmoving;
    unmoving.body.setPosition(300.f, 300.f);
    unmoving.body.setSize(Vector2f(100.f, 100.f));

    vector<Entity> moving_entities;

    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            Entity temp;
            temp.body.setSize(Vector2f(20.f, 20.f));

            temp.body.setPosition(220.f + x * 60.f,
                                  80.f + 520.f * y);

            if (y)
                temp.body.setFillColor(Color::Red);
            else
                temp.body.setFillColor(Color::Magenta);

            temp.changeVelocity(0.f, 1.f - 2.f * y);

            moving_entities.push_back(temp);
        }
    }

    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 2; x++)
        {
            Entity temp;
            temp.body.setSize(Vector2f(20.f, 20.f));

            temp.body.setPosition(80.f + 520.f * x,
                                  220.f + y * 60.f);

            if (x)
                temp.body.setFillColor(Color::Yellow);
            else
                temp.body.setFillColor(Color::Cyan);
            
            temp.changeVelocity(1.f - 2.f * x, 0.f);

            moving_entities.push_back(temp);
        }
    }

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

        // Updates here

        // Collecting hitboxes
        vector<RectangleHitbox> hitboxes;
        hitboxes.push_back(unmoving.body);
        
        // Moving
        for (Entity &moving : moving_entities)
        {
            moving.move(hitboxes);
        }

        // Drawing stuff
        window.clear();

        window.draw(unmoving.body);
        for (Entity &moving : moving_entities)
        {
            window.draw(moving.body);
        }

        // WOO
        window.display();
    }

    cout << "\n=============== End ===============\n"
         << endl;

    return 0;
}