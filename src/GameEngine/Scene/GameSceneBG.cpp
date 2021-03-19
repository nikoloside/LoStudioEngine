//
//  GameSceneBG.cpp
//  LoStudioEngine
//
//  Created by Yuhang Huang on 2019/07/17.
//  Copyright © 2019 Masaki Iwasaki. All rights reserved.
//

#include "GameSceneBG.hpp"

#include "RenderApi.h"

void GameSceneBG::setType(int type){
    color_type = type;
}

void GameSceneBG::drawBackGround(){
    switch (color_type) {
        case BG_BLACK:
        {
            glm::vec3 black(0, 0, 0);
            RenderAPI::ClearScreen(black);
            break;
        }
        case BG_GRAY:
        {
            glm::vec3 gray(0.5, 0.5, 0.5);
            RenderAPI::ClearScreen(gray);
            break;
        }
        case BG_LIGHTGRAY:
        {
            glm::vec3 lightgray(0.75, 0.75, 0.75);
            RenderAPI::ClearScreen(lightgray);
            break;
        }
        case BG_WHITE:
        {
            glm::vec3 white(1, 1, 1);
            RenderAPI::ClearScreen(white);
            break;
        }
        case BG_DIY:
        {
            draw();
            break;
        }
        default:
        {
            glm::vec3 black(0, 0, 0);
            RenderAPI::ClearScreen(black);
            break;
        }
    }
}

void GameSceneBG::draw(){
    
}
