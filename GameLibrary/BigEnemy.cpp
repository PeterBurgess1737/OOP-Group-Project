#include "BigEnemy.h"

#include <cmath>
#include <cstdlib>

using namespace std;

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

#include "GameManager.h"

BigEnemy::BigEnemy()
{
    // Basic stats
    this->health = 40;
    this->max_speed = 0.5f;
    this->move_speed = 0.01f;

    // Size
    this->body.setSize(Vector2f(131.f, 137.f));
    // this->body.setOrigin(-82.f/2.f, 0);

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

void BigEnemy::update(GameManager *manager)
{
    // Chase logic
    Vector2f vec = getUnitVectorToPlayer(manager);
    vec *= move_speed;
    changeVelocity(vec);

    // Swap if to the left
    // if (vec.x > 0)
    //    body.setScale(-1.f, 1.f);
}

void BigEnemy::draw(RenderWindow *window)
{
    window->draw(body);
}
