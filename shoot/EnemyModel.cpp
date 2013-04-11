//
//  EnemyModel.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-27.
//
//

#include "EnemyModel.h"


EnemyModel::EnemyModel( Monster mMonster){

       
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    int length = sqrt(size.width*size.width+size.height*size.height);
    int monsterLength;
    
    switch ( mMonster) {
            
        case monster1:
            m_sprite = CCSprite::createWithSpriteFrameName( "Monster1.png" );
            monsterLength = sqrt(m_sprite->getPositionY()*m_sprite->getPositionY()+m_sprite->getPositionX()*m_sprite->getPositionX());
            m_action = CCMoveTo::create( 1.0f*monsterLength/length, getRandPosition() );
            break;
            
        case monster2:
            m_sprite = CCSprite::createWithSpriteFrameName( "Monster2.png" );
            monsterLength = sqrt(m_sprite->getPositionY()*m_sprite->getPositionY()+m_sprite->getPositionX()*m_sprite->getPositionX());
            m_action = CCMoveTo::create( 1.0f*monsterLength/length, getRandPosition() );
            break;
            
        case monster3:
            m_sprite = CCSprite::createWithSpriteFrameName( "Monster3.png" );
            monsterLength = sqrt(m_sprite->getPositionY()*m_sprite->getPositionY()+m_sprite->getPositionX()*m_sprite->getPositionX());
            m_action = CCMoveTo::create( 1.0f*monsterLength/length, getRandPosition() );
            break;
            
        case monster4:
            m_sprite = CCSprite::createWithSpriteFrameName( "Monster4.png" );
            monsterLength = sqrt(m_sprite->getPositionY()*m_sprite->getPositionY()+m_sprite->getPositionX()*m_sprite->getPositionX());
            m_action = CCMoveTo::create( 1.0f*monsterLength/length, getRandPosition() );
            break;
            
        case monster5:
            m_sprite = CCSprite::createWithSpriteFrameName( "Monster5.png" );
            monsterLength = sqrt(m_sprite->getPositionY()*m_sprite->getPositionY()+m_sprite->getPositionX()*m_sprite->getPositionX());
            m_action = CCMoveTo::create( 1.0f*monsterLength/length, getRandPosition() );
            break;
            
        default:
            break;
    }

}
EnemyModel::~EnemyModel(){}

bool EnemyModel::init(){
    
    //  初始化子弹数组
    bulletArray = CCArray::create();
    bulletArray->retain();
 

    
    
    //  1.将子弹的plist 文件加入到CCSpriteFrameCache 中
    
//    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("bullet.plist", "bullet.png" );
    
    
    //  2.读取其中敌机的子弹然后加入到CCSpriteBatchNode中
    
    enemyBulletBatchNode = CCSpriteBatchNode::create( "bullet.png" );
    CCLog("monster 123123 123 12");
    
    //  3.为CCSpritBatchNode 加入光晕效果
    ccBlendFunc cb = {GL_SRC_ALPHA, GL_ONE };
    
    enemyBulletBatchNode->setBlendFunc( cb );
    
    this->addChild( enemyBulletBatchNode );
    
    
    //  设置飞机CCsprite的位置胃0
    m_sprite->setPosition( CCPointZero );
    this->addChild( m_sprite );
    //  执行动画
    m_sprite->runAction( m_action  );
    
    //  执行加入子弹和移动子弹的schedule
    this->schedule( schedule_selector( EnemyModel::addNewBullet),0.1f );
    this->schedule( schedule_selector( EnemyModel::moveBullet),0.015f );
    
        
    return true;
}


EnemyModel* EnemyModel::getEnemey( Monster mMonster ){

    
    EnemyModel* model = new EnemyModel( mMonster);
    
    
    
    if( model && model->init()){
    
    
        model->autorelease();
        
        return  model;
    }
    
    
    CC_SAFE_DELETE( model );
    return NULL;
}

void EnemyModel::addNewBullet( float t ){
    
    CCSprite* sp = CCSprite::createWithSpriteFrameName( "W1.png" );
    
    sp->setPosition(  m_sprite->getPosition() );

    
    enemyBulletBatchNode->addChild( sp );
    
    bulletArray->addObject( sp );
    
    
    
}

void EnemyModel::moveBullet( float t ){
    
    CCObject* obj = NULL;
    
    CCARRAY_FOREACH( bulletArray, obj){
        
        CCSprite* sp = ( CCSprite* )obj;
        
    
        sp->setPositionY( sp->getPositionY() - 10 );
        
        if( sp->getPositionY() <= -200){
        
            bulletArray->removeObject( obj );
            
            enemyBulletBatchNode->removeChild( sp, true );
        }
        
    }

}

CCPoint EnemyModel::getRandPosition()
{
    CCSize Winsize = CCDirector::sharedDirector()->getWinSize();
    srand(time(NULL));
    
    return ccp(rand()%((int)Winsize.width-(int)(m_sprite->getContentSize().width))+m_sprite->getContentSize().width/2, Winsize.height-m_sprite->getContentSize().height/2);
}