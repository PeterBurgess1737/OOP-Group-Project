#ifndef OOP_GROUP_PROJECT_PROJECTILE_H
#define OOP_GROUP_PROJECT_PROJECTILE_H

#include <SFML/System.hpp>
using sf::Vector2f;

#include <vector>
using std::vector;

#include "Hitbox.h"

#include "GameManager.h"
class GameManager;

class Projectile {
private:
    Vector2f velocity;

public:
    // Constructor
    Projectile(Vector2f position, float radius, Vector2f velocity, int damage, bool player_fired);

    // Holds both the display information and the hitbox information
    // Needs to be properly initialised
    CircleHitbox body;

    // Whether the projectile was fired by the player
    bool player_fired = false;

    // The damage to be done when colliding with an entity
    int damage;

    // If this projectile has collided with something
    bool collided = false;

    // Moves the projectile with respect to its velocity
    void move();

    // Update function to be specified for more interesting behaviour
    virtual void update(GameManager *manager);

    // Checks for collisions against necessary entities and damages them if there is a collision
    void checkForCollisions(GameManager *manager);

    // temp
    // ~Projectile() = default;
};


#endif //OOP_GROUP_PROJECT_PROJECTILE_H
