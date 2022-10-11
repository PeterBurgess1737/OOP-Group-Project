#include "GameManager.h"

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

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
        window->draw(enemy->body);
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
    // For each projectile
    for (Projectile *projectile : projectiles)
    {
        // Move it
        projectile->move();

        // Check for collisions
        projectile->checkForCollisions(this);
    }
}

/*
 *
 */
void GameManager::drawProjectiles() const
{
    for (Projectile *projectile : projectiles)
    {
        projectile->draw(window);
    }
}

/*
 *
 */
void GameManager::deleteCollidedProjectiles() {
    // Iterate backwards to avoid skipping elements when deleting when looping over a list
    const int size = (int)projectiles.size();
    int index;
    for (int i = 0; i < size; i++)
    {
        index = size - i - 1;
        if (projectiles[index]->collided)
        {
            delete projectiles[index];
            projectiles.erase(projectiles.begin() + index);
        }
    }
}