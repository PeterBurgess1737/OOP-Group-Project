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

    // Entities to play with
    Entity unmoving;
    unmoving.body.setPosition(100.f, 100.f);
    unmoving.body.setSize(Vector2f(100.f, 100.f));

    Entity moving;
    moving.body.setPosition(1000.f, 125.f);
    moving.body.setSize(Vector2f(50.f, 50.f));
    moving.body.setFillColor(Color(255, 125, 125));
    moving.changeVelocity(-1.f, 0.f);

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
        vector<RectangleShape> temp;
        temp.push_back(unmoving.body);

        // Moving
        moving.move(temp);

        // Drawing stuff
        window.clear();

        window.draw(unmoving.body);
        window.draw(moving.body);

        // WOO
        window.display();
    }

    cout << "\n=============== End ===============\n"
         << endl;

    return 0;
}