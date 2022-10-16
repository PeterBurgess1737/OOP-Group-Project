#ifndef OOP_GROUP_PROJECT_PLAYER_H
#define OOP_GROUP_PROJECT_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

#include "Entity.h"
#include "GameManager.h"

class Player : public Entity
{
public:
    // CONSTRUCTOR
    Player();

    // Updates the player
    void update(GameManager *manager) override;

    // Draws the player to the window
    void draw(RenderWindow *window) override;

    // Attempts to fire the bullets from the player
    void fire(GameManager *manager, Vector2i mouse_pos);

    // The delay in frames between the player firing bullets
    int bullet_delay = 3;
    // The current bullet delay, duh
    int current_bullet_delay = 0;
};

#endif // OOP_GROUP_PROJECT_PLAYER_H
