//
//  GameSceneBGUniverse.hpp
//  LoStudioEngine
//
//  Created by Yuhang Huang on 2019/07/17.
//  Copyright © 2019 Masaki Iwasaki. All rights reserved.
//

#ifndef GameSceneBGUniverse_hpp
#include "../GameEngine/Scene/GameSceneBG.hpp"
#include "../BaseSystem.h"
#include <random>
#define GameSceneBGUniverse_hpp

const int STAR_NUM = 150;
const int STAR_SCALE = 3;

class GameSceneBGUniverse : public GameSceneBG
{
public:
    int starX[STAR_NUM];
    int starY[STAR_NUM];
    int starScale[STAR_NUM];
    GameSceneBGUniverse(){
        for (int i = 0; i < STAR_NUM; i++) {
            starX[i] = rand() % SCREEN_WIDTH;
            starY[i] = rand() % SCREEN_HEIGHT;
            starScale[i] = rand() % STAR_SCALE + 1;
        }
    }
protected:
    void draw();
};

#endif /* GameSceneBGUniverse_hpp */
