#include "FastEnemy.h"
#include "GameManager.h"

#include <cmath>
using std::sqrt;

#include <cstdlib>
using std::rand;

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

#include <SFML/System.hpp>
using sf::Vector2f;

FastEnemy::FastEnemy()
{
    // Basic stats
    this->health = 2;
    this->max_speed = 2.f;
    this->move_speed = 0.2f;

    // Size
    this->body.setSize(Vector2f(70.f, 40.f));

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

void FastEnemy::update(GameManager *manager)
{
    // Chase logic
    Vector2f vec = getUnitVectorToPlayer(manager);
    vec *= move_speed;
    changeVelocity(vec);

    // Swap if to the left
    // if (vec.x > 0)
    //    body.setScale(-1.f, 1.f);
}

void FastEnemy::draw(RenderWindow *window)
{
    window->draw(body);
}

class BigEnemy : public BasicEnemy
{
public:
    BigEnemy();

    void update(GameManager *manager) override;

    void draw(RenderWindow *window) override;
};
