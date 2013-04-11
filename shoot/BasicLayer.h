//
//  BasicLayer.h
//  shoot
//
//  Created by kilua on 13-4-7.
//
//

#ifndef __shoot__BasicLayer__
#define __shoot__BasicLayer__

#include <iostream>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

class BasicLayer : public CCLayer
{
public:
    
    BasicLayer();
    ~BasicLayer();
    virtual bool init();
    CCSize getWinSize();
    void setBackgroundImage(const char* filename);
    
    void GameLayerBGCreate(const char *filename);
    void GameLayerBGCircle(float t);

    CREATE_FUNC(BasicLayer);
};

#endif /* defined(__shoot__BasicLayer__) */
