#ifndef OOP_GROUP_PROJECT_GAMEMANAGER_H
#define OOP_GROUP_PROJECT_GAMEMANAGER_H
#include "Projectile.h"

#include <vector>
using std::vector;

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

#include "Entity.h"
#include "Projectile.h"
#include "Scoreboard.h"

class GameManager {
public:
    RenderWindow &window;

    explicit GameManager(RenderWindow &window);

    vector<Projectile> projectiles;
    void updateProjectiles();
    void drawProjectiles();

    vector<Entity *> enemies;
    void addEnemy(Entity *enemy);
    void updateEnemies();
    void drawEnemies();

    Entity *player;
    void setPlayer(Entity *player);
    void updatePlayer();
    void drawPlayer();
};


#endif //OOP_GROUP_PROJECT_GAMEMANAGER_H