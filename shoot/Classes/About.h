//
//  About.h
//  shoot
//
//  Created by kilua on 13-4-7.
//
//

#ifndef __shoot__About__
#define __shoot__About__

#include "BasicLayer.h"

class About : public BasicLayer
{
public:
    About();
    ~About();
    virtual bool init();
    static CCScene *scene();
    void setUpView();
    
    void backGameCallBack(CCObject *pSender);
    
    CREATE_FUNC(About);
};

#endif /* defined(__shoot__About__) */
