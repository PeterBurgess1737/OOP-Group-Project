#include "Projectile.h"

Projectile::Projectile(Vector2f position, float radius, Vector2f velocity, int damage, bool player_fired) {
    body.setPosition(position);
    body.setRadius(radius);
    this->velocity = velocity;
    this->damage = damage;
    this->player_fired = player_fired;
}

void Projectile::move() {
    body.move(velocity);
}

void Projectile::update(GameManager *manager) {

}

void Projectile::checkForCollisions(GameManager *manager) {
    if (player_fired)
    {
        for (Entity *enemy : manager->enemies)
        {
            if (body.collidesWith(enemy->body))
            {
                enemy->takeDamage(damage);
                collided = true;
                return;
            }
        }
    }
}
