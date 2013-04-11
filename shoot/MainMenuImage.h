//
//  MainMenuImage.h
//  shoot
//
//  Created by kilua on 13-4-7.
//
//

#ifndef __shoot__MainMenuImage__
#define __shoot__MainMenuImage__

#include <iostream>
#include "BasicLayer.h"

class MainMenuImage : public BasicLayer
{
public:
    MainMenuImage();
    ~MainMenuImage();
    virtual bool init();
    static CCScene *scene();
    void setUpView();
    
    void startGameCallBack(CCObject *pSender);
    void aboutGameCallBack(CCObject *pSender);
    void optionGameCallBack(CCObject *pSender);
    
    virtual void onEnter();
    CREATE_FUNC(MainMenuImage);
};

#endif /* defined(__shoot__MainMenuImage__) */
