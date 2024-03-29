#ifndef OOP_GROUP_PROJECT_ENTITY_H
#define OOP_GROUP_PROJECT_ENTITY_H

#include <vector>

using namespace std;

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

#include "GameManager.h"
class GameManager;
#include "Hitbox.h"

class Entity
{
protected:
    // The current velocity of the entity
    Vector2f velocity;

public:
    // The current health of the entity
    int health;

    // The max speed of the entity
    float max_speed;

    // The speed the entity moves at, or the distance per frame
    float move_speed;

    // Holds both the display information and the hitbox information
    // Needs to be properly initialised
    RectangleHitbox body;

    // Returns true if the damage taken results in death
    bool takeDamage(int damage);

    // Moves the entity's location by the current velocity
    void move(const vector<RectangleHitbox *> &hitboxes);

    // Adjusts the velocity by the values given
    void changeVelocity(Vector2f adjustment);
    void changeVelocity(float xAdjustment, float yAdjustment);

    // Gets the velocity of the entity
    Vector2f getVelocity();

    // Gets the origin of the entity
    Vector2f getOrigin();

    // Gets the center of the hitbox/body
    Vector2f getCenter();

    // Receive the entities health
    int getHealth() const;

    // Update function to be specified for more interesting behaviour
    virtual void update(GameManager *manager) = 0;

    // Draw function to dictate how the entity is drawn
    virtual void draw(RenderWindow *window) = 0;
};

#endif // OOP_GROUP_PROJECT_ENTITY_H
