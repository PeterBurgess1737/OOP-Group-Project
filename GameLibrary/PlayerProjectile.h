#ifndef OOP_GROUP_PROJECT_PLAYERPROJECTILE_H
#define OOP_GROUP_PROJECT_PLAYERPROJECTILE_H

#include "Projectile.h"
#include "GameManager.h"

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

#include <SFML/System.hpp>
using sf::Vector2f;

#include <cstdlib>
using std::rand;

class PlayerProjectile : public Projectile
{
public:
    // CONSTRUCTOR
    PlayerProjectile(Vector2f position, Vector2f velocity, int lifespan = 250);

    // Updates the projectile
    void update(GameManager *manager) override;

    // Draws the projectile to the screen
    void draw(RenderWindow *window) override;

    // A timer to control the glow effect, starts at a random value to prevent patterns
    int timer = rand() % 50;
    // The default scale of the glow
    float glow_scale_default = 1.5f;
    // The current glow scale, as it changes with respect to timer
    float glow_scale = 1.5f;
};

#endif // OOP_GROUP_PROJECT_PLAYERPROJECTILE_H
