#ifndef OOP_GROUP_PROJECT_GAMEMANAGER_H
#define OOP_GROUP_PROJECT_GAMEMANAGER_H

#include <vector>
using std::vector;

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

#include "Hitbox.h"

#include "Entity.h"
class Entity;

#include "Projectile.h"
class Projectile;

class GameManager
{
public:
    // The window being drawn to
    RenderWindow *window;

    // If the game is paused
    bool paused = false;

    // If the game has been lost
    bool loss = false;

    // Constructor, window is necessary for the draw functions
    explicit GameManager(RenderWindow *window);

    // Player
    Entity *player;
    // Set the player entity
    void setPlayer(Entity *new_player);
    // Updates the player entity
    void updatePlayer();
    // Draws the player to the window given in construction
    void drawPlayer() const;
    // Checks if an enemy touches the player, returns true if this happens
    bool checkLoseCondition();

    // Enemies, must be dynamically allocated
    vector<Entity *> enemies;
    // Add an enemy
    void addEnemy(Entity *enemy);
    // Update all enemies
    void updateEnemies();
    // Draws all the enemies
    void drawEnemies() const;
    // Deletes dead enemies
    void deleteDeadEnemies();

    // Projectiles, must be dynamically allocated
    vector<Projectile *> projectiles;
    // Add a projectile
    void addProjectile(Projectile *projectile);
    // Update all projectiles
    void updateProjectiles();
    // Draws all projectiles
    void drawProjectiles() const;
    // Deletes all collided projectiles
    void deleteNecessaryProjectiles();

    // Updates everything
    void updateAll();
    // Draws everything
    void drawAll() const;
    // Deletes all the necessary things that need deleting
    void deleteAllNecessary();

    // Deletes everything
    ~GameManager();
};

#endif // OOP_GROUP_PROJECT_GAMEMANAGER_H
