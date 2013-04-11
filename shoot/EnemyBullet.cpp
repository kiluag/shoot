//
//  EnemyBullet.cpp
//  shoot
//
//  Created by kilua on 13-4-10.
//
//

#include "EnemyBullet.h"
#include "Bas.h"


EnemyBullet::EnemyBullet(){}
EnemyBullet::~EnemyBullet(){}

bool EnemyBullet::init()
{
    if (!BasicLayer::init()) {
        return false;
    }
    setUpView();
    return true;
}

void EnemyBullet::setUpView()
{
    enemyBulletBatchNode = CCSpriteBatchNode::create("bullet.png");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("bullet.plist");
    enemyBulletBatchNode->setPosition(CCPointZero);
    ccBlendFunc tmp_oBlendFunc = {GL_SRC_ALPHA, GL_ONE};
    enemyBulletBatchNode->setBlendFunc(tmp_oBlendFunc);
    this->addChild(enemyBulletBatchNode);
    
}

CCSprite * EnemyBullet::addEnemyBullet(CCSprite *enemySprite)
{
    CCSprite *enemyBulletSprite = CCSprite::createWithSpriteFrameName("W2.png");
    enemyBulletSprite->setPosition(ccp(enemySprite->getPositionX(), enemySprite->getPositionY() - enemySprite->getContentSize().height/2));
    enemyBulletBatchNode->addChild(enemyBulletSprite);
    return enemyBulletSprite;
}

void EnemyBullet::bulletMove(CCSprite *sp)
{
        sp->setPositionY(sp->getPositionY() - EnemyBulletSpeed);
}