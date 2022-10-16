#ifndef OOP_GROUP_PROJECT_FASTENEMY_H
#define OOP_GROUP_PROJECT_FASTENEMY_H

#include "BasicEnemy.h"
#include "GameManager.h"

#include <SFML/System.hpp>
using sf::Vector2f;

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

class FastEnemy : public BasicEnemy
{
public:
    // Used to time the enemies movement to the player
    int counter = 0;

    // CONSTRUCTOR
    FastEnemy();

    // Updates enemy's movement vector
    void update(GameManager *manager) override;

    // Draws enemy to the screen
    void draw(RenderWindow *window) override;
};

#endif // OOP_GROUP_PROJECT_FASTENEMY_H
