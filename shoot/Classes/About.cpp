//
//  About.cpp
//  shoot
//
//  Created by kilua on 13-4-7.
//
//

#include "About.h"
#include "MainMenuImage.h"
About::About(){}
About::~About(){}

bool About::init()
{
    bool sRect = false;
    do {
        CC_BREAK_IF(!BasicLayer::init());
        sRect = true;
        
        setUpView();
        
    } while (0);
    return sRect;
}

CCScene *About::scene()
{
    CCScene *scene = NULL;
    do {
        scene = CCScene::create();
        CC_BREAK_IF(!scene);
        About *layer = About::create();
        CC_BREAK_IF(!layer);
        scene->addChild(layer);
    } while (0);
    return scene;
}

void About::setUpView()
{
    setBackgroundImage("loading.png");
    CCLabelBMFont *bmFont = CCLabelBMFont::create("kilua", "arial-14.fnt");
    
    CCMenuItemLabel *back = CCMenuItemLabel::create(bmFont, this, menu_selector(About::backGameCallBack));
    CCMenu *menu = CCMenu::create(back,NULL);
    menu->setPosition(ccp(getWinSize().width/2, getWinSize().height/5));
    this->addChild(menu);
}

void About::backGameCallBack(CCObject *pSender)
{
    CCLog("back");
    CCDirector::sharedDirector()->pushScene(CCTransitionCrossFade::create(1.5f, MainMenuImage::scene()));
}