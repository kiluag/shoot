//
//  EnemyManager.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-27.
//
//

#include "EnemyManager.h"
#include "EnemyModel.h"

EnemyManager::EnemyManager(){

    enemyArray = CCArray::create();
    enemyArray->retain();
    
}
EnemyManager::~EnemyManager(){

    CC_SAFE_DELETE_ARRAY( enemyArray );
    
    
    
}

bool EnemyManager::init(){
    
    if( !BasicLayer::init() ){
    
        return false;
    }
    
    setupViews();
    
    return true;

}

void EnemyManager::setupViews(){
    
    //  初始化一个敌机
    Monster monster = { monster2 };
    
    EnemyModel* enemyModel = EnemyModel::getEnemey( monster);
    
    enemyArray->addObject( enemyModel );
    
    this->addChild(enemyModel,1);

    
}



void EnemyManager::addEnemy( float t ){}



CCArray* EnemyManager::getEnemyArray(){

    
    return enemyArray;
}