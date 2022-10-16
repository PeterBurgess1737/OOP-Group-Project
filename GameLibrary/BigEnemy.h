#ifndef OOP_GROUP_PROJECT_BIGENEMY_H
#define OOP_GROUP_PROJECT_BIGENEMY_H

#include "BasicEnemy.h"
#include "GameManager.h"

#include <SFML/System.hpp>
using sf::Vector2f;

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

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

#endif //OOP_GROUP_PROJECT_BIGENEMY_H
