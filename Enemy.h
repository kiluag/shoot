//
//  Enemy.h
//  shoot
//
//  Created by kilua on 13-4-9.
//
//

#ifndef __shoot__Enemy__
#define __shoot__Enemy__

#include "BasicLayer.h"

class Enemy : public BasicLayer
{
public:
    
    Enemy();
    ~Enemy();
    virtual bool init();
    
    void setUpView();
    void addEnemy(const char *filename);
    CCPoint enemyRandPosition(CCSprite *sp);
    void enemyMove();
    
    CREATE_FUNC(Enemy);

private:
    CCArray *enemyArray;
    CCSpriteBatchNode *enemyBatch;
};

#endif /* defined(__shoot__Enemy__) */
