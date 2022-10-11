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
        direction_to_mouse *= 3.f; // Bullet speed
        manager->addProjectile(
                new Projectile(
                        getCenter(),
                        3.f,
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
    // Basic stats
    this->health = 5;
    this->max_speed = 1.f;
    this->move_speed = 0.1f;

    // Size
    this->body.setSize(Vector2f(27.f, 32.f));

    // Colouring
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


class FastEnemy : public BasicEnemy
{
public:
    int counter = 0;

    FastEnemy();

    void update(GameManager *manager) override;
};

FastEnemy::FastEnemy()
{
    // Basic stats
    this->health = 2;
    this->max_speed = 2.f;
    this->move_speed = 0.2f;

    // Size
    this->body.setSize(Vector2f(42.f, 24.f));

    // Colouring
    this->body.setFillColor(Color::Yellow);

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

void FastEnemy::update(GameManager *manager)
{
    // Chase logic
    Vector2f vec = getUnitVectorToPlayer(manager);
    vec *= move_speed;
    changeVelocity(vec);
}


class BigEnemy: public BasicEnemy
{
public:
    BigEnemy();

    void update(GameManager *manager) override;
};

BigEnemy::BigEnemy()
{
    // Basic stats
    this->health = 40;
    this->max_speed = 0.5f;
    this->move_speed = 0.01f;

    // Size
    this->body.setSize(Vector2f(51.f, 53.f));

    // Colouring
    this->body.setFillColor(Color::Magenta);

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

void BigEnemy::update(GameManager *manager)
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
    int difficulty = 0;

    int difficulty_increase = 420; // 420

    int basic_enemy_spawn_delay = 120;
    int basic_enemy_max_spawn_threshold = 40; // Enemy 3/2 times a second means 7.5 damage/s

    int fast_enemy_difficulty = 5;
    int fast_enemy_spawn_delay = 150;
    int fast_enemy_max_spawn_threshold = 30; // Enemy 2 times a second means 4 damage/s

    int big_enemy_difficulty = 10;
    int big_enemy_spawn_delay = 300;
    int big_enemy_max_spawn_threshold = 60; // Enemy 1 times a second means 40 damage/s

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

        cout << "========== Frame ==========" << endl;

        // Frame counting
        frame_counter++;

        // Increasing difficulty
        if (frame_counter % difficulty_increase == 0)
        {
            difficulty++;

            if (basic_enemy_spawn_delay > basic_enemy_max_spawn_threshold)
                basic_enemy_spawn_delay--;

            if (difficulty > fast_enemy_difficulty)
            {
                if (fast_enemy_spawn_delay > fast_enemy_max_spawn_threshold)
                    fast_enemy_spawn_delay--;
            }

            if (difficulty > big_enemy_difficulty)
            {
                if (big_enemy_spawn_delay > big_enemy_max_spawn_threshold)
                    big_enemy_spawn_delay--;
            }
        }

        // Spawning basic enemy
        if (frame_counter % basic_enemy_spawn_delay == 0)
        {
            manager.addEnemy(new BasicEnemy());
        }

        // Spawning fast enemy
        if (frame_counter % fast_enemy_spawn_delay == 0)
        {
            manager.addEnemy(new FastEnemy());
        }

        // Spawning big enemy
        if (frame_counter % big_enemy_spawn_delay == 0)
        {
            manager.addEnemy(new BigEnemy());
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