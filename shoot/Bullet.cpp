//
//  Bullet.cpp
//  shoot
//
//  Created by kilua on 13-4-9.
//
//

#include "Bullet.h"
#include "Bas.h"

Bullet::Bullet(){}
Bullet::~Bullet(){}

bool Bullet::init()
{
    if (!BasicLayer::init()) {
        return false;
    }
    setUpView();
    
    return true;
}

void Bullet::setUpView()
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("bullet.plist");
    bulletBatchNode = CCSpriteBatchNode::create("bullet.png");
    bulletBatchNode->setPosition(CCPointZero);
    
    ccBlendFunc tmp_oBlendFunc = {GL_SRC_ALPHA, GL_ONE}; 
    bulletBatchNode->setBlendFunc(tmp_oBlendFunc);
    this->addChild(bulletBatchNode);
}

CCSprite * Bullet::addBullet(const CCPoint position)
{
    CCSprite *bulletSprite = CCSprite::createWithSpriteFrameName("W1.png");
    bulletBatchNode->addChild(bulletSprite);
    bulletSprite->setPosition(position);
    return bulletSprite;
}

void Bullet::bulletMove(CCSprite *bulletSprit)
{
        bulletSprit->setPositionY(bulletSprit->getPositionY()+playerBulletSpeed);
}