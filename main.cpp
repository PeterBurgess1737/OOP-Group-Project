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
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

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