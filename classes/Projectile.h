#ifndef OOP_GROUP_PROJECT_PROJECTILE_H
#define OOP_GROUP_PROJECT_PROJECTILE_H

#include <vector>
using std::vector;

#include <SFML/System.hpp>
using sf::Vector2f;

#include <SFML/Graphics.hpp>
using sf::CircleShape;

#include "Entity.h"


class Projectile{
protected:
    Vector2f velocity;
    int lifespan;
    unsigned int damage;

    sf::CircleShape body;

public:
    Projectile(Vector2f position, Vector2f velocity, float size);

    void move();

    // Damages the given entity, returns true if the damage resulted in death
    bool damageEntity(Entity *entity);

    // Can be redefined by child class for different movement patterns
    void update(vector<Projectile> projectiles, vector<Entity *> enemies, Entity *player);
};


#endif //OOP_GROUP_PROJECT_PROJECTILE_H
