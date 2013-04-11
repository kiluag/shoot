//
//  Enemy.cpp
//  shoot
//
//  Created by kilua on 13-4-10.
//
//

#include "Enemy.h"
#include "Time.h"
#include "Bas.h"

Enemy::Enemy(){}
Enemy::~Enemy(){}

bool Enemy::init()
{
    if (!BasicLayer::init()) {
        return false;
    }
    setUpView();
    return true;
}

void Enemy::setUpView()
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Monster.plist");
    enemyBatchNode = CCSpriteBatchNode::create("Monster.png");
    enemyBatchNode->setPosition(CCPointZero);
    this->addChild(enemyBatchNode);
}

CCSprite * Enemy::addEnemy()
{
//    srand(unsigned(time(0)));
    char buff[20] = "Monster1.png";
    int a = rand()%6+1;
    sprintf(buff, "%s%i%s","Monster",a,".png");
    const char *filename = buff;
    CCLog("%s",filename);
    CCSprite *sp = CCSprite::createWithSpriteFrameName(filename);
    sp->setPosition(Enemy::getRandPosition(sp));
    enemyBatchNode->addChild(sp);
    sp->runAction(CCMoveTo::create(3.0f, ccp(sp->getPositionX(), 0 - sp->getContentSize().height/2)));
    return sp;
}

CCPoint Enemy::getRandPosition(CCSprite *m_sprite)
{
    CCSize Winsize = CCDirector::sharedDirector()->getWinSize();
    srand(time(NULL));
    
    return ccp(rand()%((int)getWinSize().width-(int)(m_sprite->getContentSize().width)) + m_sprite->getContentSize().width/2, getWinSize().height + m_sprite->getContentSize().height/2);
}