//
//  EnemyBullet.cpp
//  shoot
//
//  Created by kilua on 13-4-9.
//
//

#include "EnemyBullet.h"
#include "Bas.h"

EnemyBullet::EnemyBullet(){}

EnemyBullet::~EnemyBullet()
{
    CC_SAFE_DELETE_ARRAY(enemyBulletArray);
}

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
    enemyBulletArray = CCArray::create();
    enemyBulletArray->retain();
    
    enemyBulletBatch = CCSpriteBatchNode::create("bullet.png");
    enemyBulletBatch->setPosition(CCPointZero);
    ccBlendFunc tmp_oBlendFunc = {GL_SRC_ALPHA, GL_ONE};
    enemyBulletBatch->setBlendFunc(tmp_oBlendFunc);
    this->addChild(enemyBulletBatch);
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("bullet.plist");
}

void EnemyBullet::addEnemyBullet(const CCPoint position)
{
    CCSprite *enemyBulletSprite = CCSprite::createWithSpriteFrameName("W2.png");
    enemyBulletArray->addObject(enemyBulletSprite);
    enemyBulletBatch->addChild(enemyBulletSprite);
    enemyBulletSprite->setPosition(position);
}

void EnemyBullet::enemyBulletMove(float t)
{
    CCObject *obj = NULL;
    CCARRAY_FOREACH(enemyBulletArray, obj)
    {
        CCSprite *enemyBulletSprite = (CCSprite*)obj;
        enemyBulletSprite->setPositionY(enemyBulletSprite->getPositionY()-enemyBulletSpeed);
        
        if ((enemyBulletSprite->getPositionY()<=0-enemyBulletSprite->getContentSize().height/2)) {
            enemyBulletBatch->removeChild(enemyBulletSprite, true);
            enemyBulletArray->removeObject(enemyBulletSprite);
        }
    }
}