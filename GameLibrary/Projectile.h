#ifndef OOP_GROUP_PROJECT_PROJECTILE_H
#define OOP_GROUP_PROJECT_PROJECTILE_H

#include <vector>

using namespace std;

#include <SFML/System.hpp>

using namespace sf;

#include "Hitbox.h"
#include "GameManager.h"
class GameManager;

class Projectile
{
protected:
    Vector2f velocity;

public:
    // Constructor
    Projectile(Vector2f position, float radius, Vector2f velocity, int damage, bool player_fired, int lifespan);

    // The lifespan of the projectile in frames (assumes a constant frame rate)
    int lifespan;

    // Holds both the display information and the hitbox information
    // Needs to be properly initialised
    CircleHitbox body;

    // Whether the projectile was fired by the player
    bool player_fired = false;

    // The damage to be done when colliding with an entity
    int damage;

    // If this projectile needs to be deleted
    bool to_delete = false;

    // Moves the projectile with respect to its velocity
    void move();

    // Update function to be specified for more interesting behaviour
    virtual void update(GameManager *manager);

    // Checks for collisions against necessary entities and damages them if there is a collision
    void checkForCollisions(GameManager *manager);

    // Draws the projectile to the given window, can be rewritten for more interesting drawings
    virtual void draw(RenderWindow *window);

    // Reduces the lifespan of the projectile
    void reduceLifespan();
};

#endif // OOP_GROUP_PROJECT_PROJECTILE_H
