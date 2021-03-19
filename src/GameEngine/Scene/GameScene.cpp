//
//  GameScene.cpp
//  LoStudioEngine
//
//  Created by Yuhang Huang on 2019/07/11.
//  Copyright © 2019 Masaki Iwasaki. All rights reserved.
//

#include "GameScene.hpp"

#include "RenderApi.h"


void GameScene::initScene()
{
    setup();
    lastTime = SDL_GetTicks();
    if(background == nullptr)
    {
        background = new GameSceneBG();
    }
}
void GameScene::updateScene()
{
    update();
    if(object_vec.size() > 0)
    {
        for (auto& object : object_vec) {
            object.updateMeshes();
        }
    }
    if(camera != nullptr)
    {
        camera->updateCamera();
    }
}
void GameScene::drawScene()
{
    background->drawBackGround();
    
    if(object_vec.size() > 0 && camera != nullptr)
    {
        RenderAPI::ResetzBuffer();
        std::vector< GameObject * > meshes_group;
        for (auto& object : object_vec) {
            meshes_group.push_back(&object);
        }
        camera->drawObjects(meshes_group);
    }
}
