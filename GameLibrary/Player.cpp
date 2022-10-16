#include "Player.h"
#include "PlayerProjectile.h"
#include "GameManager.h"

#include <cmath>
using std::sqrt;

#include <SFML/Graphics.hpp>
using sf::RenderWindow;
using sf::Color;

#include <SFML/System.hpp>
using sf::Vector2i;

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

void Player::draw(RenderWindow *window)
{
    window->draw(body);
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