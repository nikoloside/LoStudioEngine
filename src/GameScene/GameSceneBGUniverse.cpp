//
//  GameSceneBGUniverse.cpp
//  LoStudioEngine
//
//  Created by Yuhang Huang on 2019/07/17.
//  Copyright © 2019 Masaki Iwasaki. All rights reserved.
//

#include "GameSceneBGUniverse.hpp"
#include "RenderApi.h"
#include "../BaseSystem.h"
#include "../glm/gtc/random.hpp"
#include "../KeyBoardAPI.hpp"

void GameSceneBGUniverse::draw()
{
    glm::vec3 black(0, 0, 0);
    RenderAPI::ClearScreen(black);
    
    int x = 0;
    int y = 0;
    int speed = 50;
    
    if (KeyBoardAPI::Rotateyp()) {
        y = speed;
    }
    if (KeyBoardAPI::Rotateym()) {
        y = -speed;
    }
    if (KeyBoardAPI::Rotatexp()) {
        x = -speed;
    }
    if (KeyBoardAPI::Rotatexm()) {
        x = speed;
    }
    for (int i = 0; i < STAR_NUM; i++) {
        RenderAPI::SetColor(glm::vec3(1,1,1));
        starX[i] += y;
        starY[i] += x;
        if (starX[i] < 0) starX[i] += SCREEN_WIDTH;
        if (starY[i] < 0) starY[i] += SCREEN_HEIGHT;
        if (starX[i] > SCREEN_WIDTH) starX[i] -= SCREEN_WIDTH;
        if (starY[i] > SCREEN_HEIGHT) starY[i] -= SCREEN_HEIGHT;
        RenderAPI::DrawCircle(glm::vec2(starX[i], starY[i]), starScale[i], DEPTH_INFINITE-1);
    }
}
