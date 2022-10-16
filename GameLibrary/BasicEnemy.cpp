#include "BasicEnemy.h"

#include <cmath>
#include <cstdlib>

using namespace std;

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

#include "GameManager.h"

BasicEnemy::BasicEnemy()
{
    // Basic stats
    this->health = 5;
    this->max_speed = 1.f;
    this->move_speed = 0.1f;

    // Size
    this->body.setSize(Vector2f(51.f, 60.f));

    // Random position spawning
    switch (rand() % 4)
    {
    case 0: // The top
        this->body.setPosition((float)(rand() % 1480), -400.f);
        break;
    case 1: // The bottom
        this->body.setPosition((float)(rand() % 1480), -920.f);
        break;
    case 2: // The left
        this->body.setPosition(-400.f, (float)(rand() % 920));
        break;
    case 3: // The right
        this->body.setPosition(1480.f, (float)(rand() % 920));
        break;
    }
}

Vector2f BasicEnemy::getUnitVectorToPlayer(GameManager *manager)
{
    Vector2f vec = manager->player->getCenter() - getCenter();
    const float vec_mag = sqrt(vec.x * vec.x + vec.y * vec.y);
    vec /= vec_mag;
    return vec;
}

void BasicEnemy::update(GameManager *manager)
{
    // Chase logic
    Vector2f vec = getUnitVectorToPlayer(manager);
    vec *= move_speed;
    changeVelocity(vec);

    // Swap if to the left
    // if (vec.x > 0)
    //    body.setScale(-1.f, 1.f);
}

void BasicEnemy::draw(RenderWindow *window)
{
    window->draw(body);
}
