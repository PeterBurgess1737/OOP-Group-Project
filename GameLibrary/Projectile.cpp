#include "Projectile.h"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Projectile::Projectile(Vector2f position, float radius, Vector2f velocity, int damage, bool player_fired, int lifespan)
{
    body.setPosition(position);
    body.setRadius(radius);
    this->velocity = velocity;
    this->damage = damage;
    this->player_fired = player_fired;
    this->lifespan = lifespan;
}

void Projectile::move()
{
    body.move(velocity);
}

void Projectile::update(GameManager *manager)
{
}

void Projectile::checkForCollisions(GameManager *manager)
{
    if (player_fired)
    {
        for (Entity *enemy : manager->enemies)
        {
            if (body.collidesWith(enemy->body))
            {
                enemy->takeDamage(damage);
                to_delete = true;
                return;
            }
        }
    }
}

void Projectile::draw(RenderWindow *window)
{
    window->draw(body);
}

void Projectile::reduceLifespan()
{
    lifespan--;
    if (lifespan <= 0)
    {
        to_delete = true;
    }
}