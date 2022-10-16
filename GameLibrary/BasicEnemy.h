#ifndef OOP_GROUP_PROJECT_BASICENEMY_H
#define OOP_GROUP_PROJECT_BASICENEMY_H

#include "Entity.h"
#include "GameManager.h"

#include <SFML/System.hpp>
using sf::Vector2f;

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

class BasicEnemy : public Entity
{
public:
    // CONSTRUCTOR
    BasicEnemy();

    // Determines enemy's direction of travel
    Vector2f getUnitVectorToPlayer(GameManager *manager);

    // Updates enemy's movement vector
    void update(GameManager *manager) override;

    // Draws enemy to the screen
    void draw(RenderWindow *window) override;
};

#endif //OOP_GROUP_PROJECT_BASICENEMY_H
