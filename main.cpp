#include <iostream>
using std::cout;
using std::endl;

#include <cmath>
using std::sqrt;

#include <cstdlib>
using std::rand;

#include <SFML/Graphics.hpp>
using sf::CircleShape;
using sf::Color;
using sf::Image;
using sf::RectangleShape;
using sf::RenderWindow;
using sf::Texture;

#include <SFML/System.hpp>
using sf::Vector2f;
using sf::Vector2i;

#include <SFML/Window.hpp>

#include "GameLibrary/GameLibrary.h"

class PlayerProjectile : public Projectile
{
public:
    PlayerProjectile(Vector2f position, Vector2f velocity);

    void update(GameManager *manager) override;

    void draw(RenderWindow *window) override;

    int timer = rand() % 50;
    float glow_scale_default = 1.5f;
    float glow_scale = 1.5f;
};

PlayerProjectile::PlayerProjectile(Vector2f position, Vector2f velocity) : Projectile(position, 3.f, velocity, 1, true, 120) {}

void PlayerProjectile::update(GameManager *manager)
{
    timer++;

    float temp = (float)(timer % 50);

    if (temp < 25.f)
        glow_scale = glow_scale_default + (temp / 25);
    else
        glow_scale = glow_scale_default + ((50 - temp) / 25);
}

void PlayerProjectile::draw(sf::RenderWindow *window)
{
    window->draw(body);

    CircleShape temp_circle(body.getRadius());
    temp_circle.setPosition(body.getCenter());

    for (int i = 0; i < 3; i++)
    {
        temp_circle.setOrigin(temp_circle.getRadius(), temp_circle.getRadius());
        temp_circle.setScale(glow_scale * (float)(i + 1), glow_scale * (float)(i + 1));

        Color temp_colour = body.getFillColor();
        temp_colour.a = (uint8_t)(255 / (i + 3));
        temp_circle.setFillColor(temp_colour);
        window->draw(temp_circle);
    }
}

class Player : public Entity
{
public:
    Player();

    void update(GameManager *manager) override;

    void fire(GameManager *manager, Vector2i mouse_pos);

    int bullet_delay = 3;
    int current_bullet_delay = 0;
};

Player::Player()
{
    this->body.setSize(Vector2f(32.f, 34.f));
    this->body.setPosition(628, 343);
}

void Player::update(GameManager *manager)
{
    if (current_bullet_delay > 0)
    {
        current_bullet_delay--;
    }
}

void Player::fire(GameManager *manager, Vector2i mouse_pos)
{
    if (current_bullet_delay <= 0)
    {
        Vector2f direction_to_mouse = Vector2f(
            (float)mouse_pos.x - getCenter().x,
            (float)mouse_pos.y - getCenter().y);
        float magnitude = sqrt(direction_to_mouse.x * direction_to_mouse.x + direction_to_mouse.y * direction_to_mouse.y);
        direction_to_mouse /= magnitude;
        direction_to_mouse *= 3.f; // Bullet speed
        auto *temp = new PlayerProjectile(
            getCenter(),
            direction_to_mouse);
        temp->body.setFillColor(Color(235, 179, 12));
        manager->addProjectile(temp);

        current_bullet_delay = bullet_delay;
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
    this->body.setSize(Vector2f(51.f, 60.f));

    // Random position spawning
    switch (rand() % 4)
    {
    case 0: // The top
        this->body.setPosition((float)(rand() % 1280), -200.f);
        break;
    case 1: // The bottom
        this->body.setPosition((float)(rand() % 1280), -920.f);
        break;
    case 2: // The left
        this->body.setPosition(-200.f, (float)(rand() % 720));
        break;
    case 3: // The right
        this->body.setPosition(1480.f, (float)(rand() % 720));
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
    this->body.setSize(Vector2f(70.f, 40.f));

    // Random position spawning
    switch (rand() % 4)
    {
    case 0: // The top
        this->body.setPosition((float)(rand() % 1280), -200.f);
        break;
    case 1: // The bottom
        this->body.setPosition((float)(rand() % 1280), -920.f);
        break;
    case 2: // The left
        this->body.setPosition(-200.f, (float)(rand() % 720));
        break;
    case 3: // The right
        this->body.setPosition(1480.f, (float)(rand() % 720));
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

class BigEnemy : public BasicEnemy
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
    this->body.setSize(Vector2f(131.f, 137.f));
    // this->body.setOrigin(-82.f/2.f, 0);

    // Random position spawning
    switch (rand() % 4)
    {
    case 0: // The top
        this->body.setPosition((float)(rand() % 1280), -200.f);
        break;
    case 1: // The bottom
        this->body.setPosition((float)(rand() % 1280), -920.f);
        break;
    case 2: // The left
        this->body.setPosition(-200.f, (float)(rand() % 720));
        break;
    case 3: // The right
        this->body.setPosition(1480.f, (float)(rand() % 720));
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

int main()
{
    cout << "\n========== Program Start ==========\n"
         << endl;

    // Create the window
    RenderWindow window(sf::VideoMode(1280, 720),
                        "OOP Group Project");

    // Reducing the framerate to 60fps
    window.setFramerateLimit(60);

    // Loading and creating textures
    Texture player_texture;
    player_texture.loadFromFile("images/Not-Mooncake.png");
    Texture basic_enemy_texture;
    basic_enemy_texture.loadFromFile("images/Chonk-Child.png");
    Texture fast_enemy_texture;
    fast_enemy_texture.loadFromFile("images/Smol-Child.png");
    Texture big_enemy_texture;
    big_enemy_texture.loadFromFile("images/Mega-Chonk.png");

    // Where the event being handled is stored
    sf::Event event;

    // Game manager yay
    GameManager manager(&window);

    // The player
    Player player;
    player.body.setTexture(&player_texture);
    manager.setPlayer(&player);

    // Frame counting
    int frame_counter = -1;

    // Difficulty, increases spawn rate, increases every 7 seconds
    int difficulty = 0;

    int difficulty_increase = 420; // 420

    int basic_enemy_spawn_delay = 120;        // 120
    int basic_enemy_max_spawn_threshold = 40; // Enemy 3/2 times a second means 7.5 damage/s

    int fast_enemy_difficulty = 5;           // 5
    int fast_enemy_spawn_delay = 150;        // 150
    int fast_enemy_max_spawn_threshold = 30; // Enemy 2 times a second means 4 damage/s

    int big_enemy_difficulty = 10;          // 10
    int big_enemy_spawn_delay = 300;        // 300
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
            auto *temp = new BasicEnemy();
            temp->body.setTexture(&basic_enemy_texture, true);
            manager.addEnemy(temp);
        }

        // Spawning fast enemy
        if (frame_counter % fast_enemy_spawn_delay == 0)
        {
            auto *temp = new FastEnemy();
            temp->body.setTexture(&fast_enemy_texture);
            manager.addEnemy(temp);
        }

        // Spawning big enemy
        if (frame_counter % big_enemy_spawn_delay == 0)
        {
            auto *temp = new BigEnemy();
            temp->body.setTexture(&big_enemy_texture);
            manager.addEnemy(temp);
        }

        // Bullet spawning
        Vector2i mouse_pos = sf::Mouse::getPosition(window);
        player.fire(&manager, mouse_pos);

        // Updates
        manager.updateEnemies();
        manager.updateProjectiles();
        manager.updatePlayer();

        // Drawing stuff
        window.clear(Color(37, 37, 37));

        manager.drawPlayer();
        manager.drawEnemies();
        manager.drawProjectiles();

        // Deleting necessary stuff
        manager.deleteDeadEnemies();
        manager.deleteNecessaryProjectiles();

        // WOO
        window.display();
    }

    cout << "\n=============== End ===============\n"
         << endl;

    return 0;
}