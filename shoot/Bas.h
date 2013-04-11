//
//  Bas.h
//  shoot
//
//  Created by kilua on 13-4-9.
//
//

#ifndef shoot_Bas_h
#define shoot_Bas_h

enum Monster {
    monster1 = 0,
    monster2 = 1,
    monster3 = 2,
    monster4 = 3 ,
    monster5 = 4,
};

#define playerBulletSpeed 15
#define addPlayerBulletTime 0.05f

//敌机子弹每次移动距离
#define EnemyBulletSpeed 2
//敌机子弹移动时间间隔
#define EnemyBulletTime 0.01f
//产生敌机子弹移动时间间隔
#define addEnemyBulletTime 1.0f
//敌机移动速度
#define enemyMoveSpeed 10
//敌机移动时间间隔
#define addEnemyTime 1.0f

#endif
