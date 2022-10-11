#ifndef OOP_GROUP_PROJECT_GAMEMANAGER_H
#define OOP_GROUP_PROJECT_GAMEMANAGER_H

#include <vector>
using std::vector;

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

#include "Entity.h"
class Entity;

#include "Hitbox.h"

class GameManager
{
public:
    // The window being drawn to
    RenderWindow *window;

    // Constructor, window is necessary for the draw functions
    explicit GameManager(RenderWindow *window);

    // Contains pointers to all the hitboxes in all entities that are handled
    vector<RectangleHitbox *> all_enemy_hitboxes;

    // Player
    Entity *player;
    // Set the player entity
    void setPlayer(Entity *new_player);
    // Updates the player entity
    void updatePlayer();
    // Draws the player to the window given in construction
    void drawPlayer() const;

    // Enemies
    vector<Entity *> enemies;
    // Add an enemy
    void addEnemy(Entity *enemy);
    // Update all enemies
    void updateEnemies();
    // Draws all the enemies
    void drawEnemies();
};

#endif // OOP_GROUP_PROJECT_GAMEMANAGER_H
