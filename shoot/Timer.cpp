//
//  Timer.cpp
//  shoot
//
//  Created by kilua on 13-4-8.
//
//

#include "Timer.h"

Timer::Timer()
{
    counter = 0;
}
Timer::~Timer(){}

bool Timer::init()
{
    bool sRect = false;
    do {
        CC_BREAK_IF(!BasicLayer::init());
        
        setUpView();
        
        sRect = true;
    } while (0);
    return sRect;
}

void Timer::setUpView()
{
    CCLabelBMFont* scoreFont = CCLabelBMFont::create("Time : 20", "arial-14.fnt");
    scoreFont->setPosition(CCPointZero);
    this->addChild(scoreFont,0,103);
    this->schedule(schedule_selector(Timer::timeUpdate),1.0f);
}

void Timer::timeUpdate(float t)
{
    CCLabelBMFont *scoreFont = (CCLabelBMFont*)getChildByTag(103);
    char str[20] = {};
    sprintf(str, "Time : %d",counter);
    scoreFont->setString(str);
    counter++;
}