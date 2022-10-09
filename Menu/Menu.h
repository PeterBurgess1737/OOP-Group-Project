#ifndef OOP_GROUP_PROJECT_MAINMENU_H
#define OOP_GROUP_PROJECT_MAINMENU_H

#include <SFML/System.hpp>

class Menu {

    int position; 
    sf::RenderWindow * window; 
    sf::RectangleShape * windowclose;
    sf::Vector2i position_mouse;
    sf::Vector2i coordinates_of_mouse;

    sf::Vector2i mouse_position;
    sf::Vector2i mouse_coordinates;

    // Coordinates and size of the text options. 
    std::vector<sf::Text> texts; 
    std::vector<sf::Vector2f> coordinates;
    std::vector<std::size_t> sizes;
    std::vector<const char *> options;


protected:
    void draw_all();
    void set_values();

public:
    Menu();
    ~Menu();
    void run_menu();
};

#endif //OOP_GROUP_PROJECT_MAINMENU_H