//
//  GamePaush.h
//  shoot
//
//  Created by kilua on 13-4-8.
//
//

#ifndef __shoot__GamePaush__
#define __shoot__GamePaush__

#include "BasicLayer.h"

class GamePaush : public CCLayerColor
{
public:
    GamePaush();
    ~GamePaush();
    virtual bool init();
    
    void setUpView(const char* filename);
    void resumeGame(CCObject *pSender);
    
    CREATE_FUNC(GamePaush)
};

#endif /* defined(__shoot__GamePaush__) */
