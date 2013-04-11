//
//  Player.h
//  shoot
//
//  Created by kilua on 13-4-9.
//
//

#ifndef __shoot__Player__
#define __shoot__Player__

#include "BasicLayer.h"

class Player : public BasicLayer
{
public:
    Player();
    ~Player();
    virtual bool init();
    
    CCSprite *player_01;
    CCPoint playerPoint;
    void setUpView();
    void playerShooted();
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void registerWithTouchDispatcher(void);
    CCPoint getPlayerPosition();
    
    CREATE_FUNC(Player);
    
private:
    bool bulletPosition;
};

#endif /* defined(__shoot__Player__) */
