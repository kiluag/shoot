//
//  Option.cpp
//  shoot
//
//  Created by kilua on 13-4-8.
//
//

#include "Option.h"
#include "MainMenuImage.h"

Option::Option(){}
Option::~Option(){}

bool Option::init()
{
    bool sRect = false;
    do {
        CC_BREAK_IF(!BasicLayer::init());
        
        setUpView();
        
        sRect = true;
    } while (0);
    return sRect;
}


CCScene *Option::scene()
{
    CCScene *scene = NULL;
    do {
        scene = CCScene::create();
        CC_BREAK_IF(!scene);
        Option *layer = Option::create();
        CC_BREAK_IF(!layer);
        scene->addChild(layer);
    } while (0);
    return scene;
}

void Option::setUpView()
{
    setBackgroundImage("loading.png");
    CCLabelBMFont *bmFont = CCLabelBMFont::create("kilua", "arial-14.fnt");
    
    CCMenuItemLabel *back = CCMenuItemLabel::create(bmFont, this, menu_selector(Option::backGameCallBack));
    
    CCMenuItemToggle *music = CCMenuItemToggle::createWithTarget(this, menu_selector(Option::mainMainMusicPlay),CCMenuItemFont::create("Music On"),CCMenuItemFont::create("Music Off"),NULL);
    music->setPosition(ccp(0, getWinSize().height/5*3));
    
    if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()) {
        music->setSelectedIndex(1);
    }else{
        music->setSelectedIndex(0);
    }
    
    CCMenu *menu = CCMenu::create(back,music,NULL);
    menu->setPosition(ccp(getWinSize().width/2, getWinSize().height/5));
    this->addChild(menu);
    
}

void Option::backGameCallBack(CCObject *pSender)
{
    CCDirector::sharedDirector()->pushScene(CCTransitionCrossFade::create(1.5f, MainMenuImage::scene()));
}

void Option::mainMainMusicPlay(CCObject *pSender)
{
    if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()) {
        SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
        CCUserDefault::sharedUserDefault()->setBoolForKey("mainMainMusic", true);
    }else{
        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
        CCUserDefault::sharedUserDefault()->setBoolForKey("mainMainMusic", false);
    }
}