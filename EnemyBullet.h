//
//  EnemyBullet.h
//  shoot
//
//  Created by kilua on 13-4-9.
//
//

#ifndef __shoot__EnemyBullet__
#define __shoot__EnemyBullet__

#include "BasicLayer.h"

class EnemyBullet : public BasicLayer
{
public:
    EnemyBullet();
    ~EnemyBullet();
    virtual bool init();
    void setUpView();
    void addEnemyBullet(const CCPoint position);
    void enemyBulletMove(float t);
    
    CCArray *enemyBulletArray;
    CCSpriteBatchNode *enemyBulletBatch;
    
    CREATE_FUNC(EnemyBullet);
};

#endif /* defined(__shoot__EnemyBullet__) */
