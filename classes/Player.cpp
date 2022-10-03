#include "Player.h"

#include <SFML/Graphics.hpp>
using sf::RectangleShape;

#include <SFML/System.hpp>
using sf::Vector2f;

#include "Entity.h"
#include "GameManager.h"

// Implementation of moving the player
void Player::move()
{

}

// Implementation of updating the player
void Player::update(GameManager manager)
{

}

Player::Player(float x, float y, float width, float height, int speed)
{
    RectangleShape body(Vector2f(width, height));
    body.setPosition(x,y);
    body.setOrigin(width / 2, height / 2);
}

Player::Player(Vector2f position, Vector2f size)
{

}