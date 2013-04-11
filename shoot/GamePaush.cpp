//
//  GamePaush.cpp
//  shoot
//
//  Created by kilua on 13-4-8.
//
//

#include "GamePaush.h"
#include "GameLayer.h"

GamePaush::GamePaush(){}
GamePaush::~GamePaush(){}

bool GamePaush::init()
{
    if (!CCLayerColor::initWithColor(ccc4(0, 0, 0, 50))) {
        return false;
    }
    setUpView("play.png");
    
    return true;
}

void GamePaush::setUpView(const char* filename)
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCMenuItemImage *resumeImage = CCMenuItemImage::create(filename, filename, this, menu_selector(GamePaush::resumeGame));
    CCMenu *menu = CCMenu::create(resumeImage,NULL);
    this->addChild(menu);
}

void GamePaush::resumeGame(CCObject *pSender)
{
    GameLayer *gameLayer = (GameLayer*)getParent();
    GamePaush *gamePaush = (GamePaush*)gameLayer->getChildByTag(104);
    gamePaush->setVisible(false);
    
    CCDirector::sharedDirector()->resume();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    
}