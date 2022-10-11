#include <iostream>
using std::cout;
using std::endl;

#include <cmath>
using std::sqrt;

#include <cstdlib>
using std::rand;

#include <SFML/Graphics.hpp>
using sf::RenderWindow;
using sf::CircleShape;
using sf::RectangleShape;
using sf::Color;

#include <SFML/System.hpp>
using sf::Vector2f;
using sf::Vector2i;

#include <SFML/Window.hpp>

#include "GameLibrary/GameLibrary.h"


class Player : public Entity
{
public:
    Player();

    void update(GameManager *manager) override;

    void fire(GameManager *manager, Vector2i mouse_pos);

    int bullet_delay = 0;
};

Player::Player()
{
    this->body.setSize(Vector2f (30.f, 30.f));
    this->body.setPosition(625, 345);
    this->body.setFillColor(Color::Cyan);
}

void Player::update(GameManager *manager)
{
    if (bullet_delay > 0)
    {
        bullet_delay--;
    }
}

void Player::fire(GameManager *manager, Vector2i mouse_pos)
{
    if (bullet_delay == 0)
    {
        Vector2f direction_to_mouse = Vector2f(
                (float)mouse_pos.x - getCenter().x,
                (float)mouse_pos.y - getCenter().y
                );
        float magnitude = sqrt(direction_to_mouse.x * direction_to_mouse.x + direction_to_mouse.y * direction_to_mouse.y);
        direction_to_mouse /= magnitude;
        direction_to_mouse *= 3.f;
        manager->addProjectile(
                new Projectile(
                        getCenter(),
                        2.5f,
                        direction_to_mouse,
                        1,
                        true
                        )
                );

        bullet_delay = 3;
    }
}


class BasicEnemy : public Entity
{
public:
    BasicEnemy();

    Vector2f getUnitVectorToPlayer(GameManager *manager);

    void update(GameManager *manager) override;
};

BasicEnemy::BasicEnemy()
{
    this->health = 5;
    this->max_speed = 2.f;
    this->move_speed = 0.2f;

    this->body.setSize(Vector2f(20.f, 20.f));

    this->body.setFillColor(Color::Red);

    // Random position spawning
    switch (rand() % 4) {
        case 0: // The top
            this->body.setPosition((float)(rand() % 1280), -50.f);
            break;
        case 1: // The bottom
            this->body.setPosition((float)(rand() % 1280), -770.f);
            break;
        case 2: // The left
            this->body.setPosition(-50.f, (float)(rand() % 720));
            break;
        case 3: // The right
            this->body.setPosition(1330.f, (float)(rand() % 720));
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
}


int main()
{
    cout << "\n========== Program Start ==========\n"
         << endl;

    // Create the window
    RenderWindow window(sf::VideoMode(1280, 720),
                        "OOP Group Project");

    // Reducing the framerate to 60fps
    window.setFramerateLimit(60);

    // Where the event being handled is stored
    sf::Event event;

    // Game manager yay
    GameManager manager(&window);

    // The player
    Player player;
    manager.setPlayer(&player);

    // Frame counting
    int frame_counter = 0;

    // Difficulty, increases spawn rate, increases every 7 seconds
    int difficulty = 1;

    // Game loop
    while (window.isOpen())
    {
        // Event handler
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed: // Window closed
                window.close();
                break;

            case sf::Event::KeyPressed: // Escape key pressed
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            default:
                break;
            }
        }

        // Frame counting
        frame_counter++;

        // Increasing difficulty
        if (frame_counter % 420 == 0)
        {
            difficulty++;
        }

        // Spawning basic enemy
        if (frame_counter % (120 - difficulty) == 0)
        {
            manager.addEnemy(new BasicEnemy());
        }

        // Spawning faster enemy
        if (difficulty > 5)
        {

        }

        // Spawning in TANK
        if (difficulty > 10)
        {

        }

        // Bullet spawning
        Vector2i mouse_pos = sf::Mouse::getPosition(window);
        player.fire(&manager, mouse_pos);

        // Updates
        manager.updateEnemies();
        manager.updateProjectiles();
        manager.updatePlayer();

        // Drawing stuff
        window.clear();

        manager.drawPlayer();
        manager.drawEnemies();
        manager.drawProjectiles();

        // Deleting necessary stuff
        manager.deleteDeadEnemies();
        manager.deleteCollidedProjectiles();

        // WOO
        window.display();
    }

    cout << "\n=============== End ===============\n"
         << endl;

    return 0;
}