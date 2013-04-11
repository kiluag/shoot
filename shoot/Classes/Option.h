//
//  Option.h
//  shoot
//
//  Created by kilua on 13-4-8.
//
//

#ifndef __shoot__Option__
#define __shoot__Option__

#include "BasicLayer.h"

class Option : public BasicLayer
{
public:
    Option();
    ~Option();
    virtual bool init();
    static CCScene *scene();
    
    void setUpView();
    void backGameCallBack(CCObject *pSender);
    void mainMainMusicPlay(CCObject *pSender);
    
    CREATE_FUNC(Option);
};

#endif /* defined(__shoot__Option__) */
