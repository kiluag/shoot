//
//  Player.cpp
//  shoot
//
//  Created by kilua on 13-4-9.
//
//

#include "Player.h"

Player::Player(){}
Player::~Player(){}

bool Player::init()
{
    bool sRect = false;
    do {
        CC_BREAK_IF(!BasicLayer::init());
        sRect = true;
        
        this->setTouchEnabled(true);
        setUpView();
    } while (0);
    return sRect;
}

void Player::setUpView()
{
    bulletPosition = false;
    player_01 = CCSprite::create("ship01.png",CCRectMake(0, 0, 60, 42));
    player_01->setPosition(ccp(getWinSize().width/2, getWinSize().height/10));
    this->addChild(player_01);
    
    CCAnimation *animation = CCAnimation::create();
    animation->addSpriteFrame(CCSpriteFrame::create("ship01.png", CCRectMake(0, 0, 60, 42)));
    animation->addSpriteFrame(CCSpriteFrame::create("ship01.png", CCRectMake(60, 0, 60, 42)));
    animation->setDelayPerUnit(0.1f);
    CCAnimate *animate = CCAnimate::create(animation);
    player_01->runAction(CCRepeatForever::create(animate));
    
}

bool Player::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    player_01->setPosition(pTouch->getLocation());
    return true;
}

void Player::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    player_01->setPosition(pTouch->getLocation());
}

void Player::registerWithTouchDispatcher(void)
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

CCPoint Player::getPlayerPosition()
{
    if (!bulletPosition) {
        bulletPosition = true;
        return ccp(player_01->getPositionX()+player_01->getContentSize().width/4, player_01->getPositionY()+player_01->getContentSize().height/2);
    }
    bulletPosition = false;
    return ccp(player_01->getPositionX()-player_01->getContentSize().width/4, player_01->getPositionY()+player_01->getContentSize().height/2);
}

void Player::playerShooted()
{
    player_01->runAction(CCBlink::create(1.0f, 10));
}