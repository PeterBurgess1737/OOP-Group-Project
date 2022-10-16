#include "GameManager.h"

#include <iostream>
#include <vector>

using namespace std;

#include <SFML/Graphics.hpp>
#include "SFMl/Window.hpp"

using namespace sf;

#include "Entity.h"
#include "Projectile.h"

/*
 * Construct the manager with a render window
 */
GameManager::GameManager(RenderWindow *window)
{
    // Set the window
    this->window = window;
    // No player for now
    player = nullptr;
}

/*
 * Set the managers player entity
 */
void GameManager::setPlayer(Entity *new_player)
{
    // Player time
    player = new_player;
}

/*
 * Updates the player entity
 */
void GameManager::updatePlayer()
{
    if (paused)
        return;

    player->update(this);
}

/*
 * Draws the payer entity to the handled window
 */
void GameManager::drawPlayer() const
{
    window->draw(player->body);
}

/*
 * Checks if an enemy has touched the player
 * If so then true is returned and the game manager pauses
 */
bool GameManager::checkLoseCondition()
{
    for (Entity *enemy : enemies)
    {
        if (player->body.collidesWith(enemy->body))
        {
            paused = true;
            loss = true;
            break;
        }
    }

    return loss;
}

/*
 * Adds an enemy entity to the list of handled enemy entities
 */
void GameManager::addEnemy(Entity *enemy)
{
    // Add the enemy
    enemies.push_back(enemy);
}

/*
 * Updates all handled enemy entities
 */
void GameManager::updateEnemies()
{
    if (paused)
        return;

    // Grab all enemy hitboxes
    vector<RectangleHitbox *> all_enemy_hitboxes;
    for (Entity *enemy : enemies)
    {
        all_enemy_hitboxes.push_back(&enemy->body);
    }

    // Update all the entities
    for (Entity *enemy : enemies)
    {
        enemy->update(this);

        enemy->move(all_enemy_hitboxes);
    }
}

/*
 * Draws all handled enemy entities to the handled window
 */
void GameManager::drawEnemies() const
{
    for (Entity *enemy : enemies)
    {
        enemy->draw(window);
    }
}

/*
 * Deletes all enemies with health less than or equal to 0
 */
void GameManager::deleteDeadEnemies()
{
    // Iterate backwards to avoid skipping elements when deleting when looping over a list
    const int size = (int)enemies.size();
    int index;
    for (int i = 0; i < size; i++)
    {
        index = size - i - 1;
        if (enemies[index]->getHealth() <= 0)
        {
            delete enemies[index];
            enemies.erase(enemies.begin() + index);
        }
    }
}

/*
 * Adds a projectile to the list of handles projectiles
 */
void GameManager::addProjectile(Projectile *projectile)
{
    // Add the projectile
    projectiles.push_back(projectile);
}

/*
 * Updates all handled projectiles
 */
void GameManager::updateProjectiles()
{
    if (paused)
        return;

    // For each projectile
    for (Projectile *projectile : projectiles)
    {
        // Update it
        projectile->update(this);

        // Move it
        projectile->move();

        // Check for collisions
        projectile->checkForCollisions(this);

        // Reduce lifespan
        projectile->reduceLifespan();
    }
}

/*
 * Draws all handled projectiles
 */
void GameManager::drawProjectiles() const
{
    for (Projectile *projectile : projectiles)
    {
        projectile->draw(window);
    }
}

/*
 * Deletes all projectiles marked for deletion
 */
void GameManager::deleteNecessaryProjectiles()
{
    // Iterate backwards to avoid skipping elements when deleting when looping over a list
    const int size = (int)projectiles.size();
    int index;
    for (int i = 0; i < size; i++)
    {
        index = size - i - 1;
        if (projectiles[index]->to_delete)
        {
            delete projectiles[index];
            projectiles.erase(projectiles.begin() + index);
        }
    }
}

/*
 *
 */
void GameManager::updateAll()
{
    updatePlayer();
    updateEnemies();
    updateProjectiles();
}

/*
 *
 */
void GameManager::drawAll() const
{
    drawPlayer();
    drawEnemies();
    drawProjectiles();
}

/*
 *
 */
void GameManager::deleteAllNecessary()
{
    deleteDeadEnemies();
    deleteNecessaryProjectiles();
}

GameManager::~GameManager()
{
    for (Entity *enemy : enemies)
    {
        delete enemy;
    }
    enemies.clear();

    for (Projectile *projectile : projectiles)
    {
        delete projectile;
    }
    projectiles.clear();
}
