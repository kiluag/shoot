//
//  Timer.h
//  shoot
//
//  Created by kilua on 13-4-8.
//
//

#ifndef __shoot__Timer__
#define __shoot__Timer__

#include "BasicLayer.h"

class Timer : public BasicLayer
{
public:
    Timer();
    ~Timer();
    virtual bool init();
    
    void setUpView();
    void timeUpdate(float t);
    
    CREATE_FUNC(Timer)
    
private:
    int counter;
};

#endif /* defined(__shoot__Timer__) */
