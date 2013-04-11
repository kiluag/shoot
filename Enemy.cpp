//
//  Enemy.cpp
//  shoot
//
//  Created by kilua on 13-4-9.
//
//

#include "Enemy.h"
#include "Time.h"
#include "Bas.h"

Enemy::Enemy(){}

Enemy::~Enemy()
{
    CC_SAFE_DELETE_ARRAY(enemyArray);
}

bool Enemy::init()
{
    if (!BasicLayer::init()) {
        return  false;
        
    }
    setUpView();
    return true;
}

void Enemy::setUpView()
{
    CCLog("12312312321321312");
    enemyArray = CCArray::create();
    enemyArray->retain();
    enemyBatch = CCSpriteBatchNode::create("Monster.png");
    enemyBatch->setPosition(CCPointZero);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Monster.plist");
    this->addChild(enemyBatch);
    char enemyFilename[10];
    sprintf(enemyFilename, "%s%d%s","Monster",rand()%6+1,".png");
    CCLog("%s",enemyFilename);
    this->addEnemy(enemyFilename);
}

void Enemy::addEnemy(const char *filename)
{
    CCSprite *enemySprite = CCSprite::createWithSpriteFrameName("Monster1.png");
    enemySprite->setPosition(Enemy::enemyRandPosition(enemySprite));
    enemyArray->addObject(enemySprite);
    enemyBatch->addChild(enemySprite);
}

CCPoint Enemy::enemyRandPosition(CCSprite *sp)
{
    srand(time(NULL));
    
    return ccp(rand()%((int)getWinSize().width-(int)(sp->getContentSize().width))+sp->getContentSize().width/2, getWinSize().height-sp->getContentSize().height/2);
}

void Enemy::enemyMove()
{
    CCObject *obj;
    CCARRAY_FOREACH(enemyArray, obj)
    {
        CCSprite *sp = (CCSprite*)obj;
        sp->setPositionY(sp->getPositionY()-enemyMoveSpeed);
        if (sp->getPositionY()<=0-sp->getContentSize().height/2) {
            enemyArray->removeObject(sp);
            enemyBatch->removeChild(sp, true);
        }
    }
}