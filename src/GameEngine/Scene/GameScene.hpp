//
//  GameScene.hpp
//  LoStudioEngine
//
//  Created by Yuhang Huang on 2019/07/11.
//  Copyright © 2019 Masaki Iwasaki. All rights reserved.
//

#ifndef GameScene_hpp
#include <iostream>
#include <vector>
#include "../Object/GameObject.hpp"
#include "../Camera/GameCamera.hpp"
#include "../Scene/GameSceneBG.hpp"
#include <SDL.h>
#define GameScene_hpp

class GameScene
{
private:
    GameSceneBG *background;
    unsigned int lastTime;
    
public:
    GameCamera *camera;
    std::vector < GameObject > object_vec;
    
    void initScene();
    void updateScene();
    void drawScene();
    
    void createBG( GameSceneBG *bg )
    {
        background = bg;
    }
    
    void createCamera( GameCamera *ca )
    {
        camera = ca;
    }
    
    void addObject( GameObject object)
    {
        object_vec.push_back(object);
    }
    
    unsigned int getDTime()
    {
        unsigned int dTime = SDL_GetTicks() - lastTime;
        lastTime = SDL_GetTicks();
        return dTime;
    }
    
protected:
    void virtual setup() = 0;
    void virtual update() = 0;
};

#endif /* GameScene_hpp */
