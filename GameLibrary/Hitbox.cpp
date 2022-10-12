#include "Hitbox.h"

#include <SFML/System.hpp>
using sf::Vector2f;

#include <cmath>
using std::sqrt;

/*
 * Rectangle Hitbox
 */

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

bool RectangleHitbox::collidesWith(const RectangleHitbox &rectangle) const
{
    if (getLeft() < rectangle.getRight())
        if (getRight() > rectangle.getLeft())
            if (getTop() < rectangle.getBottom())
                if (getBottom() > rectangle.getTop())
                    return true;
    
    return false;
}

/*
 * Circle Hitbox
 */

Vector2f CircleHitbox::getCenter()
{
    Vector2f temp = getPosition();
    const float radius = getRadius();
    temp.x += radius;
    temp.y += radius;

    return temp;
}

bool CircleHitbox::collidesWith(const RectangleHitbox &rectangle) const
{
    const Vector2f rect_pos = rectangle.getPosition();
    const Vector2f rect_size = rectangle.getSize();
    const Vector2f circle_pos = getPosition();
    Vector2f circle_center = getPosition();

    const float circle_radius = getRadius();
    circle_center.x += circle_radius;
    circle_center.y += circle_radius;

    // If the center of the circle is within the bounds of the sides of the rectangle
    // Then consider the circle a rectangle
    if (
            rect_pos.x <= circle_center.x && circle_center.x <= rect_pos.x + rect_size.x ||
            rect_pos.y <= circle_center.y && circle_center.y <= rect_pos.y + rect_size.y)
    {
        const float circle_diameter = circle_radius * 2;
        RectangleHitbox binding_rectangle;
        binding_rectangle.setSize(Vector2f(circle_diameter, circle_diameter));
        binding_rectangle.setPosition(circle_pos);

        return rectangle.collidesWith(binding_rectangle);
    }

    // Find the corner the circle is closest to and get x and y displacement
    float x_diff, y_diff, distance;
    const bool circle_above = circle_center.y < rect_pos.y;
    if (circle_center.x < rect_pos.x) // If the circle is to the left of the rectangle
        if (circle_above)             // If the circle is above the rectangle
        {
            // Get displacement to the rectangles top left corner
            x_diff = circle_center.x - rect_pos.x;
            y_diff = circle_center.y - rect_pos.y;
        }
        else // If the circle is below the rectangle
        {
            // Get displacement to the rectangles bottom left corner
            x_diff = circle_center.x - rect_pos.x;
            y_diff = circle_center.x - rect_pos.y - rect_size.y;
        }
    else                  // If the circle is to the right of the rectangle
    if (circle_above) // If the circle is above the rectangle
    {
        // Get the displacement to the rectangles top right corner
        x_diff = circle_center.x - rect_pos.x - rect_size.x;
        y_diff = circle_center.y - rect_pos.y;
    }
    else // If the circle is below the rectangle
    {
        // Get the displacement to the rectangles bottom right corner
        x_diff = circle_center.x - rect_pos.x - rect_size.x;
        y_diff = circle_center.y - rect_pos.y - rect_size.y;
    }

    // Find the distance and check against radius
    distance = sqrt(x_diff * x_diff + y_diff * y_diff);
    if (distance < circle_radius)
        return true;

    return false;
}
