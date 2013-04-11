//
//  Enemy.h
//  shoot
//
//  Created by kilua on 13-4-10.
//
//

#ifndef __shoot__Enemy__
#define __shoot__Enemy__

#include "BasicLayer.h"
#include "EnemyBullet.h"


class Enemy : public BasicLayer
{
public:
    
    Enemy();
    ~Enemy();
    virtual bool init();
    
    void setUpView();
    CCSpriteBatchNode *enemyBatchNode;
    CCSprite * addEnemy();
    CCPoint getRandPosition(CCSprite *m_sprite);
    
    CREATE_FUNC(Enemy);
    
private:
    EnemyBullet *enemyBullet;
};

#endif /* defined(__shoot__Enemy__) */
