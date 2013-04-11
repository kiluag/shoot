//
//  BasicLayer.cpp
//  shoot
//
//  Created by kilua on 13-4-7.
//
//

#include "BasicLayer.h"
BasicLayer::BasicLayer(){}
BasicLayer::~BasicLayer(){}
bool BasicLayer::init()
{
    bool sRect = false;
    do {
        CC_BREAK_IF(!CCLayer::init());
        sRect = true;
    } while (0);
    return sRect;
}
CCSize BasicLayer::getWinSize()
{
    return CCDirector::sharedDirector()->getWinSize();
}

void BasicLayer::setBackgroundImage(const char* filename)
{
    CCSprite *sp = CCSprite::create(filename);
    sp->setPosition(ccp(getWinSize().width/2, getWinSize().height/2));
    this->addChild(sp);
}

void BasicLayer::GameLayerBGCreate(const char *filename)
{
    CCSprite *bg1 = CCSprite::create(filename);
    CCSprite *bg2 = CCSprite::create(filename);
    bg1->setPosition(ccp(getWinSize().width/2, getWinSize().height/2));
    bg2->setPosition(ccp(getWinSize().width/2, getWinSize().height/2+bg1->getContentSize().height));
    this->addChild(bg1, 0, 101);
    this->addChild(bg2, 0, 102);
    this->schedule(schedule_selector(BasicLayer::GameLayerBGCircle), 0.5f);
}

void BasicLayer::GameLayerBGCircle(float t)
{
    CCSprite *bg1 = (CCSprite *)getChildByTag(101);
    CCSprite *bg2 = (CCSprite *)getChildByTag(102);
    bg1->setPositionY(bg1->getPositionY()-1);
    bg2->setPositionY(bg2->getPositionY()-1);
    
    if (bg1->getPositionY() <= 0-bg1->getContentSize().height/2) {
        bg1->setPositionY(bg2->getPositionY()+bg2->getContentSize().height);
    }
    if (bg2->getPositionY() <= 0-bg2->getContentSize().height/2) {
        bg2->setPositionY(bg1->getPositionY()+bg1->getContentSize().height);
    }
}