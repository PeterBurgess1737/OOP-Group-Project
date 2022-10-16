#include "PlayerProjectile.h"
#include "GameManager.h"

#include <SFML/Graphics.hpp>
using sf::CircleShape;
using sf::Color;

#include <SFML/System.hpp>
using sf::Vector2f;

PlayerProjectile::PlayerProjectile(Vector2f position, Vector2f velocity, int lifespan) : Projectile(position, 3.f, velocity, 1, true, lifespan) {}

void PlayerProjectile::update(GameManager *manager)
{
    timer++;

    auto temp = (float)(timer % 50);

    if (temp < 25.f)
        glow_scale = glow_scale_default + (temp / 25);
    else
        glow_scale = glow_scale_default + ((50 - temp) / 25);
}

void PlayerProjectile::draw(RenderWindow *window)
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
