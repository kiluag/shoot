//
//  MainMenuImage.cpp
//  shoot
//
//  Created by kilua on 13-4-7.
//
//

#include "MainMenuImage.h"
#include "About.h"
#include "Option.h"
#include "GameLayer.h"

MainMenuImage::MainMenuImage(){}
MainMenuImage::~MainMenuImage(){}

bool MainMenuImage::init()
{
    bool sRect = false;
    do {
        CC_BREAK_IF(!BasicLayer::init());
        
        setUpView();
        
        sRect = true;
    } while (0);
    return sRect;
}

CCScene* MainMenuImage::scene()
{
    CCScene *scene = NULL;
    do {
        scene = CCScene::create();
        CC_BREAK_IF(!scene);
        MainMenuImage *layer = MainMenuImage::create();
        CC_BREAK_IF(!layer);
        scene->addChild(layer);
    } while (0);
    return scene;
}

void MainMenuImage::setUpView()
{
    setBackgroundImage("loading.png");
    
    CCTexture2D *bgmenu = CCTextureCache::sharedTextureCache()->addImage("menu.png");
    CCSprite *startGameNor = CCSprite::createWithTexture(bgmenu, CCRectMake(126*0, 0, 126, 33));
    CCSprite *startGamePre = CCSprite::createWithTexture(bgmenu,CCRectMake(126*0, 33, 126, 33));
    CCSprite *startGameDis = CCSprite::createWithTexture(bgmenu,CCRectMake(126*0, 66, 126, 33));
    CCMenuItemSprite *startGameMenu = CCMenuItemSprite::create(startGameNor, startGamePre, startGameDis, this, menu_selector(MainMenuImage::startGameCallBack));
    
    CCSprite *aboutNor = CCSprite::createWithTexture(bgmenu,CCRectMake(126*1, 0, 126, 33));
    CCSprite *aboutPre = CCSprite::createWithTexture(bgmenu,CCRectMake(126*1, 33, 126, 33));
    CCSprite *aboutDis = CCSprite::createWithTexture(bgmenu,CCRectMake(126*1, 66, 126, 33));
    CCMenuItemSprite *aboutMenu = CCMenuItemSprite::create(aboutNor, aboutPre, aboutDis, this, menu_selector(MainMenuImage::optionGameCallBack));
    
    CCSprite *sectionNor = CCSprite::createWithTexture(bgmenu,CCRectMake(126*2, 0, 126, 33));
    CCSprite *sectionPre = CCSprite::createWithTexture(bgmenu,CCRectMake(126*2, 33, 126, 33));
    CCSprite *sectionDis = CCSprite::createWithTexture(bgmenu,CCRectMake(126*2, 66, 126, 33));
    CCMenuItemSprite *sectionMenu = CCMenuItemSprite::create(sectionNor, sectionPre, sectionDis, this, menu_selector(MainMenuImage::aboutGameCallBack));
    
    CCMenu *startMenu = CCMenu::create(startGameMenu,aboutMenu,sectionMenu,NULL);
    startMenu->setPosition(ccp(getWinSize().width/2, getWinSize().height/2));
    startMenu->alignItemsVerticallyWithPadding(10);
    this->addChild(startMenu);
    
    CCSprite *logo = CCSprite::create("logo.png");
    logo->setPosition(ccp(getWinSize().width/2, getWinSize().height/5*4));
    this->addChild(logo);
}

void MainMenuImage::startGameCallBack(CCObject *pSender)
{
    CCLog("start");
    CCDirector::sharedDirector()->pushScene(CCTransitionCrossFade::create(1.0f, GameLayer::scene()));
}

void MainMenuImage::aboutGameCallBack(CCObject *pSender)
{
    CCLog("about");
    CCDirector::sharedDirector()->pushScene(CCTransitionCrossFade::create(1.0f, About::scene()));
}

void MainMenuImage::optionGameCallBack(CCObject *pSender)
{
    CCLog("option");
    CCDirector::sharedDirector()->pushScene(CCTransitionCrossFade::create(1.0f, Option::scene()));
}

void MainMenuImage::onEnter()
{
    CCLayer::onEnter();
    bool flag = CCUserDefault::sharedUserDefault()->getBoolForKey("mainMainMusic");
    if (flag == false && !SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()) {
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic("mainMainMusic.mp3", true);
    }else{
        
    }
}
