#include "GameManager.h"

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include "Entity.h"

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
 *
 */
void GameManager::updatePlayer()
{
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

    // Grab its hitbox
    all_enemy_hitboxes.push_back(&enemy->body);
}

/*
 * Updates all handled enemy entities
 */
void GameManager::updateEnemies()
{
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
void GameManager::drawEnemies()
{
    for (Entity *enemy : enemies)
    {
        window->draw(enemy->body);
    }
}
