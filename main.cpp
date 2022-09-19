#include <iostream>
using std::cout;
using std::endl;

#include <SFML/Graphics.hpp>

int main()
{
    cout << "\n========== Program Start ==========\n"
         << endl;

    // Create the window
    sf::RenderWindow window(
        sf::VideoMode(1280, 720),
        "OOP Group Project");

    // Circle
    sf::CircleShape shape(100.f); // Radius
    shape.setFillColor(sf::Color::Green); // Color
    shape.setPosition(100.f, 100.f); // Position

    // For movement of the shape
    float x_movement;
    float y_movement;

    // Where the event being handled is stored
    sf::Event event;

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
            }
        }

        // Moving the shape
        x_movement = 0.f;
        y_movement = 0.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            x_movement -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            x_movement += 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            y_movement -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            y_movement += 1.f;

        shape.move(x_movement, y_movement);

        // Drawing stuff
        window.clear();
        window.draw(shape);

        // WOOO
        window.display();
    }

    cout << "\n=============== End ===============\n"
         << endl;

    return 0;
}