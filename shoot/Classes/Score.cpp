//
//  Score.cpp
//  shoot
//
//  Created by kilua on 13-4-8.
//
//

#include "Score.h"
#include "Time.h"

Score::Score(){}
Score::~Score(){}

bool Score::init()
{
    bool sRect = false;
    do {
        CC_BREAK_IF(!BasicLayer::init());
        
        setUpView();
        
        sRect = true;
    } while (0);
    return sRect;
}

void Score::setUpView()
{
    scoreNum = 0;
    scoreFont = CCLabelBMFont::create("Score : 20", "arial-14.fnt");
    scoreFont->setPosition(CCPointZero);
    this->addChild(scoreFont);
}

void Score::addScore()
{
    srand(time(0));
    char str[20];
    sprintf(str, "%s%d","Score : ",scoreNum);
    scoreFont->setString(str);
    scoreNum++;
}

void Score::subSocre()
{
    srand(time(0));
    char str[20];
    sprintf(str, "%s%d","Score : ",scoreNum);
    scoreFont->setString(str);
    scoreNum = scoreNum - 5;
}