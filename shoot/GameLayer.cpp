//
//  GameLayer.cpp
//  shoot
//
//  Created by kilua on 13-4-8.
//
//

#include "GameLayer.h"
#include "Timer.h"
#include "GamePaush.h"
#include "Bas.h"

GameLayer::GameLayer(){}
GameLayer::~GameLayer(){}

bool GameLayer::init()
{
    bool sRect = false;
    do {
        CC_BREAK_IF(!BasicLayer::init());
        
        setUpView();
        
        sRect = true;
    } while (0);
    return sRect;
}

CCScene *GameLayer::scene()
{
    CCScene *scene = NULL;
    do {
        scene = CCScene::create();
        CC_BREAK_IF(!scene);
        GameLayer *layer = GameLayer::create();
        CC_BREAK_IF(!layer);
        scene->addChild(layer);
    } while (0);
    return scene;
}

void GameLayer::setUpView()
{
    //初始化数组A，数组B，数组C..........
    playerBulletArray = CCArray::create();
    playerBulletArray->retain();
    enemyArray = CCArray::create();
    enemyArray->retain();
    enemyBulletArray = CCArray::create();
    enemyBulletArray->retain();
    deleteEnemyArray = CCArray::create();
    deleteEnemyArray->retain();
    deleteEnemyBulletArray = CCArray::create();
    deleteEnemyBulletArray->retain();
    deletePlayerBulletArray = CCArray::create();
    deletePlayerBulletArray->retain();
    deathTime = 0;
    
    //创建游戏背景
    GameLayerBGCreate("bg01.jpg");
    
    //创建分数标签
    score = Score::create();
    score->setPosition(ccp(getWinSize().width/8, getWinSize().height/30*29));
    this->addChild(score);
    
    //创建时间标签
    Timer *timeLayer = Timer::create();
    timeLayer->setPosition(ccp(getWinSize().width/2, getWinSize().height/30*29));
    this->addChild(timeLayer);
    
    //创建暂停按钮
    CCMenuItemImage *paushImage = CCMenuItemImage::create("pause.png", "pause.png", this, menu_selector(GameLayer::paushGame));
    paushImage->setPosition(ccp(getWinSize().width-paushImage->getContentSize().width/2,  paushImage->getContentSize().height/2));
    CCMenu *menu = CCMenu::create(paushImage,NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu,2);
    
    //创建游戏场景
    GamePaush *paushLayer = GamePaush::create();
    paushLayer->setPosition(CCPointZero);
    paushLayer->setVisible(false);
    this->addChild(paushLayer,3,104);
    
    //创建Player
    player = Player::create();
    this->addChild(player,1);
    
    //创建Player子弹
    bullet = Bullet::create();
    this->addChild(bullet,1);
    
    //创建敌人
    enemy = Enemy::create();
    this->addChild(enemy);
    
    //创建敌人子弹
    enemyBullet = EnemyBullet::create();
    this->addChild(enemyBullet);
    
    this->schedule(schedule_selector(GameLayer::addNewBullet),addPlayerBulletTime);
//    this->schedule(schedule_selector(GameLayer::addNewEnemy),addEnemyTime);
    this->schedule(schedule_selector(GameLayer::addEnemyBullet),addEnemyBulletTime);
    this->schedule(schedule_selector(GameLayer::enemyBulletMove),EnemyBulletTime);
    this->scheduleUpdate();
}

//暂停游戏
void GameLayer::paushGame(CCObject *pSender)
{
    getChildByTag(104)->setVisible(true);
    CCDirector::sharedDirector()->pause();
    if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()) {
        SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    }
}

void GameLayer::addNewBullet(float t)
{
    //根据Player坐标添加玩家子弹并加入数组
    playerBulletArray->addObject(bullet->addBullet(player->getPlayerPosition()));
}

void GameLayer::addNewEnemy()
{
    if (60/(deathTime + score->scoreNum) == 1) {
        //添加敌人并加入数组
        CCSprite *sp = enemy->addEnemy();
        enemyArray->addObject(sp);
        deathTime = 0;
    }
}

//添加敌机子弹
void GameLayer::addEnemyBullet(float t)
{
    CCObject *obj = NULL;
    CCARRAY_FOREACH(enemyArray, obj)
    {
        CCSprite *sp = (CCSprite*)obj;
        
        //根据敌机坐标创建子弹并加入数组
        enemyBulletArray->addObject(enemyBullet->addEnemyBullet(sp));
    }
}

//敌机子弹移动
void GameLayer::enemyBulletMove(float t)
{
    CCObject *obj = NULL;
    
    CCARRAY_FOREACH(enemyBulletArray, obj)
    {
        CCSprite *sp = (CCSprite*)obj;
        
        //敌人子弹移动
        enemyBullet->bulletMove(sp);
        
        //敌机子弹出屏幕删除
        if (sp->getPositionY() <= 0 - sp->getContentSize().height/2) {
            enemyBulletArray->removeObject(sp);
            enemyBullet->enemyBulletBatchNode->removeChild(sp, true);
        }
    }
    
    CCARRAY_FOREACH(playerBulletArray, obj)
    {
        CCSprite *sp = (CCSprite*)obj;
        
        //玩家子弹移动
        bullet->bulletMove(sp);
        
        //子弹出屏幕消失
        if (sp->getPositionY() >= getWinSize().height + sp->getContentSize().height/2) {
            playerBulletArray->removeObject(sp);
            bullet->bulletBatchNode->removeChild(sp, true);
        }
    }
    
    //碰撞检测
    this->GameLayer::check();
}

void GameLayer::check()
{
    CCObject *obj2 = NULL;
    CCObject *obj3 = NULL;
    
    //读取玩家子弹
    CCARRAY_FOREACH(playerBulletArray, obj2)
    {
        CCSprite *playerBullet = (CCSprite*)obj2;
        
        //读取敌人
        CCARRAY_FOREACH(enemyArray, obj3)
        {
            CCSprite *enemySprite = (CCSprite *)obj3;
            
            //根据玩家子弹和敌人碰撞检测
            if (playerBullet->boundingBox().intersectsRect(enemySprite->boundingBox())) {
                CCLog("moe");
                
                deleteEnemyArray->addObject(enemySprite);
                enemyArray->removeObject(enemySprite);
                
                playerBulletArray->removeObject(playerBullet);
                deletePlayerBulletArray->addObject(playerBullet);
                
                //杀敌加分
                score->addScore();
            }
        }
    }
    
    CCARRAY_FOREACH(enemyBulletArray, obj2)
    {
        CCSprite *enemyBulletSprite = (CCSprite*)obj2;
        
        //Player碰撞检测
        if (enemyBulletSprite->boundingBox().intersectsRect(player->player_01->boundingBox())) {
            player->playerShooted();
            enemyBulletArray->removeObject(enemyBulletSprite);
            deleteEnemyBulletArray->addObject(enemyBulletSprite);
            enemyBullet->enemyBulletBatchNode->removeChild(enemyBulletSprite, true);
            
            //被击中减分
            score->subSocre();
        }
    }
    
    this->GameLayer::deleteSprite();
}

//删除需要删除的CCSprite
void GameLayer::deleteSprite()
{
    CCObject *obj = NULL;
    CCARRAY_FOREACH(deletePlayerBulletArray, obj)
    {
        CCSprite *sp = (CCSprite*)obj;
        deletePlayerBulletArray->removeObject(sp);
        bullet->bulletBatchNode->removeChild(sp, true);
    }
    
    CCARRAY_FOREACH(deleteEnemyBulletArray, obj)
    {
        CCSprite *sp = (CCSprite*)obj;
        deleteEnemyBulletArray->removeObject(sp);
        enemyBullet->enemyBulletBatchNode->removeChild(sp, true);
    }
    
    CCARRAY_FOREACH(deleteEnemyArray, obj)
    {
        CCSprite *sp = (CCSprite*)obj;
        deleteEnemyArray->removeObject(sp);
        CCLog("%i",sp->getPositionY());
        enemy->enemyBatchNode->removeChild(sp, true);
    }
}

//暂时没用上
void GameLayer::update(float t)
{
    deathTime++;
    this->GameLayer::addNewEnemy();
}