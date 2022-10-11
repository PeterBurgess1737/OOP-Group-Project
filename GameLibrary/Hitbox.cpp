#include "Hitbox.h"

#include <SFML/System.hpp>
using sf::Vector2f;

float RectangleHitbox::getLeft() const
{
    return getPosition().x;
}
float RectangleHitbox::getRight() const
{
    return getPosition().x + getSize().x;
}
float RectangleHitbox::getTop() const
{
    return getPosition().y;
}
float RectangleHitbox::getBottom() const
{
    return getPosition().y + getSize().y;
}

void RectangleHitbox::setLeft(float value)
{
    setPosition(
        Vector2f(value, getPosition().y)
    );
}
void RectangleHitbox::setRight(float value)
{
    setPosition(
        Vector2f(value - getSize().x, getPosition().y)
    );
}
void RectangleHitbox::setTop(float value)
{
    setPosition(
        Vector2f(getPosition().x, value)
    );
}
void RectangleHitbox::setBottom(float value)
{
    setPosition(
        Vector2f(getPosition().x, value - getSize().y)
    );
}

bool RectangleHitbox::collidesWith(const RectangleHitbox &rectangle)
{
    if (getLeft() < rectangle.getRight())
        if (getRight() > rectangle.getLeft())
            if (getTop() < rectangle.getBottom())
                if (getBottom() > rectangle.getTop())
                    return true;
    
    return false;
}

bool CircleHitbox::collidesWith(const RectangleHitbox &rectangle) {


    return false;
}
