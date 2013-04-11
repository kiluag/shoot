//
//  GameLayer.h
//  shoot
//
//  Created by kilua on 13-4-8.
//
//

#ifndef __shoot__GameLayer__
#define __shoot__GameLayer__

#include "BasicLayer.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Score.h"

class GameLayer : public BasicLayer {
public:
    GameLayer();
    ~GameLayer();
    virtual bool init();
    static CCScene *scene();
    int deathTime;
    
    void setUpView();
    void paushGame(CCObject *pSender);
    void addNewBullet(float t);
    void addNewEnemy();
    void addEnemyBullet(float t);
    void enemyBulletMove(float t);
    void update(float t);
    void check();
    void deleteSprite();
    
    CCArray *enemyArray;
    CCArray *enemyBulletArray;
    CCArray *playerBulletArray;
    CCArray *deleteEnemyArray;
    CCArray *deleteEnemyBulletArray;
    CCArray *deletePlayerBulletArray;
    
    CREATE_FUNC(GameLayer);
    
private:
    Bullet *bullet;
    Player *player;
    Enemy *enemy;
    EnemyBullet *enemyBullet;
    Score *score;
};

#endif /* defined(__shoot__GameLayer__) */
