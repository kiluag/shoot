//
//  Bullet.h
//  shoot
//
//  Created by kilua on 13-4-9.
//
//

#ifndef __shoot__Bullet__
#define __shoot__Bullet__

#include "BasicLayer.h"

class Bullet : public BasicLayer
{
public:
    
    Bullet();
    ~Bullet();
    virtual bool init();
    
    void setUpView();
    CCSprite * addBullet(const CCPoint position);
    void bulletMove(CCSprite *bulletSprit);
    
    CREATE_FUNC(Bullet);
    CCSpriteBatchNode *bulletBatchNode;
    
};

#endif /* defined(__shoot__Bullet__) */
