#include "Entity.h"

#include <SFML/System.hpp>
using sf::Vector2f;

#include <math.h>

/*
 * Entities default constructor
 * Shoudnt be used in the actual game as this is just for testing purposes
 */
Entity::Entity()
{
    // Give everything some value
    health = 0;
    max_speed = 0;
    move_speed = 0;
}

/*
 * Reduces the health of the entity by damage amount
 * Returns true if the entity was 'killed' by the damage
 */
bool Entity::takeDamage(unsigned int damage)
{
    health -= damage;
    return health <= 0;
}

/*
 * Moves the entity by its current velocity
 */
void Entity::move(){
    body.move(velocity);
}

/*
 * Changes the entities velocity by the given amounts
 * If the new velocity magnitude exceeds the max speed then it is normalised to the max speed
 */
void Entity::changeVelocity(float xAdjustment, float yAdjustment)
{
    // Changes the velocity
    velocity.x += xAdjustment;
    velocity.y += yAdjustment;

    // Get the magnitude
    const float velocity_magnitude = sqrtf(xAdjustment * xAdjustment + yAdjustment * yAdjustment);

    // If the magnitude is larger than the speed make the magnitude the speed
    if (velocity_magnitude > max_speed)
    {
        velocity.x = velocity.x / velocity_magnitude * max_speed;
        velocity.y = velocity.y / velocity_magnitude * max_speed;
    }
}

/*
 * Change velocity with a vector rather than 2 floats
 */
void Entity::changeVelocity(Vector2f adjustment)
{
    Entity::changeVelocity(adjustment.x, adjustment.y);
}

/*
 * Gets the current velocity
 */
Vector2f Entity::getVelocity()
{
    return velocity;
}

/*
 * Gets the origin from the body and returns it
 */
Vector2f Entity::getOrigin()
{
    return body.getOrigin();
}

/*
 * PAIN
 */
void Entity::update()
{

}