#ifndef OOP_GROUP_PROJECT_BIGENEMY_H
#define OOP_GROUP_PROJECT_BIGENEMY_H

#include "BasicEnemy.h"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

#include "GameManager.h"

class BigEnemy : public BasicEnemy
{
public:
    // CONSTRUCTOR
    BigEnemy();

    // Updates enemy's movement vector
    void update(GameManager *manager) override;

    // Draws enemy to the screen
    void draw(RenderWindow *window) override;
};

#endif // OOP_GROUP_PROJECT_BIGENEMY_H
