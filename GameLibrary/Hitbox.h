#ifndef OOP_GROUP_PROJECT_HITBOX_H
#define OOP_GROUP_PROJECT_HITBOX_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class RectangleHitbox : public RectangleShape
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

    bool collidesWith(const RectangleHitbox &rectangle) const;
};

class CircleHitbox : public CircleShape
{
public:
    // Gets centre of circle hitbox
    Vector2f getCenter();

    // Checks for collision with a rectangle hitbox
    bool collidesWith(const RectangleHitbox &rectangle) const;
};

#endif // OOP_GROUP_PROJECT_HITBOX_H