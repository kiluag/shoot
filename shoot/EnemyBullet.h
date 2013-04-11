//
//  EnemyBullet.h
//  shoot
//
//  Created by kilua on 13-4-10.
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
    CCSpriteBatchNode *enemyBulletBatchNode;
    CCSprite * addEnemyBullet(CCSprite *enemySprite);
    void bulletMove(CCSprite *sp);
    
    CREATE_FUNC(EnemyBullet);
};

#endif /* defined(__shoot__EnemyBullet__) */
