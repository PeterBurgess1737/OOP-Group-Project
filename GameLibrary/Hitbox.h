#ifndef OOP_GROUP_PROJECT_HITBOX_H
#define OOP_GROUP_PROJECT_HITBOX_H

#include <SFML/System.hpp>
using sf::Vector2f;

#include <SFML/Graphics.hpp>
using sf::RectangleShape;

class RectangleHitbox: public RectangleShape
{
public:
    float getLeft() const;
    float getRight() const;
    float getTop() const;
    float getBottom() const;

    void setLeft(float value);
    void setRight(float value);
    void setTop(float value);
    void setBottom(float value);

    bool collidesWith(const RectangleShape &rectangle);
    bool collidesWith(const RectangleHitbox &rectangle);
};

#endif // OOP_GROUP_PROJECT_HITBOX_H