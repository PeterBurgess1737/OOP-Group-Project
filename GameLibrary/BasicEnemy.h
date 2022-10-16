#ifndef OOP_GROUP_PROJECT_BASICENEMY_H
#define OOP_GROUP_PROJECT_BASICENEMY_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

#include "Entity.h"
#include "GameManager.h"

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

#endif // OOP_GROUP_PROJECT_BASICENEMY_H
