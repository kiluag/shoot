//
//  Score.h
//  shoot
//
//  Created by kilua on 13-4-8.
//
//

#ifndef __shoot__Score__
#define __shoot__Score__

#include "BasicLayer.h"

class Score : public BasicLayer
{
public:
    Score();
    ~Score();
    virtual bool init();
    CCLabelBMFont *scoreFont;
    int scoreNum;
    
    void setUpView();
    void addScore();
    void subSocre();
    
    CREATE_FUNC(Score)
};

#endif /* defined(__shoot__Score__) */
