#ifndef OOP_GROUP_PROJECT_FASTENEMY_H
#define OOP_GROUP_PROJECT_FASTENEMY_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

#include "BasicEnemy.h"
#include "GameManager.h"

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
