#ifndef OOP_GROUP_PROJECT_ENTITY_H
#define OOP_GROUP_PROJECT_ENTITY_H

#include <SFML/System.hpp>
using sf::Vector2f;

#include <SFML/Graphics.hpp>
using sf::RectangleShape;

#include <vector>
using std::vector;

#include "GameManager.h"
class GameManager;

#include "Hitbox.h"

class Entity
{
private:
    // The current velocity of the entity
    Vector2f velocity;

protected:
    // The current health of the entity
    int health;

    // The max speed of the entity
    float max_speed;

    // The speed the entity moves at, or the distance per frame
    float move_speed;

public:
    // Holds both the display information and the hitbox information
    // Needs to be properly initilised
    RectangleHitbox body;

    // Simple default constructor, just for testing purposes and shouldn't be used
    Entity();

    // Returns true if the damage taken results in death
    bool takeDamage(int damage);

    // Moves the entity's location by the current velocity
    void move(vector<RectangleHitbox *> hitboxes);

    // Adjusts the velocity by the values given
    void changeVelocity(Vector2f adjustment);
    void changeVelocity(float xAdjustment, float yAdjustment);

    // Gets the velocity of the entity
    Vector2f getVelocity();

    // Gets the origin of the entity
    Vector2f getOrigin();

    // Gets the center of the hitbox/body
    Vector2f getCenter();

    // Update function to be specified for more interesting behaviour
    virtual void update(GameManager *manager);
};

#endif // OOP_GROUP_PROJECT_ENTITY_H
