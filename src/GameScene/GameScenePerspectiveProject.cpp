//
//  GameScenePerspectiveProject.cpp
//  LoStudioEngine
//
//  Created by Niko Huang on 2019/7/21.
//  Copyright © 2019 Masaki Iwasaki. All rights reserved.
//

#include "GameScenePerspectiveProject.hpp"
#include "GameSceneBGUniverse.hpp"
#include "../GameEngine/Camera/GameCameraPerspective.hpp"
#include "../KeyBoardAPI.hpp"

void GameScenePerspectiveProject::setup()
{
    GameSceneBGUniverse * bg = new GameSceneBGUniverse();
    bg->setType(BG_DIY);
    createBG(bg);
    
    GameObject * objectsun = new GameObject();
    objectsun->moveMat(0,0,5);
    objectsun->scalingMat(3,3,3);
    objectsun->loadMeshes("/Users/nikolos/Documents/MacOS_workspace/LoStudioEngineProject/meshes/triangle_sphere.obj");
    objectsun->setColor(1, 0, 0, 1);
    addObject(*objectsun);
    
    GameObject * objectearch = new GameObject();
    objectearch->moveMat(-15,0, 5);
    objectearch->loadMeshes("/Users/nikolos/Documents/MacOS_workspace/LoStudioEngineProject/meshes/triangle_sphere.obj");
    objectearch->setColor(0, 0, 1, 1);
    addObject(*objectearch);
    
    GameObject * objectmoon = new GameObject();
    objectmoon->moveMat(-13, 0, 5);
    objectmoon->scalingMat(.5,.5,.5);
    objectmoon->loadMeshes("/Users/nikolos/Documents/MacOS_workspace/LoStudioEngineProject/meshes/triangle_sphere.obj");
    objectmoon->setColor(.5, .5, .5, 1);
    addObject(*objectmoon);
    
    GameCameraPerspective * camera = new GameCameraPerspective();
    camera->moveMat(0, 0, -20);
    camera->setCamera(0, 0, 1, 0, 1, 0);
    
    createCamera(camera);
}

void GameScenePerspectiveProject::update()
{
    unsigned int dTime = getDTime();
    //std::cout << SDL_GetTicks() << " " << (float)dTime << std::endl;
    float speed = 1 * (float)dTime / 1000 ;
    float speed2 = 3 * (float)dTime / 1000 ;
    object_vec[0].rotateMat(0, speed, speed);
    object_vec[1].rotateMat(speed, speed, 0);
    object_vec[2].rotateMat(speed, speed, 0);
    
    glm::vec3 es = object_vec[1].getLocation() - object_vec[0].getLocation();
    glm::vec3 me = object_vec[2].getLocation() - object_vec[1].getLocation();
    
    glm::vec3 n_v_es = glm::normalize(glm::cross(es, glm::vec3(0,1,0)));
    glm::vec3 n_v_me = glm::normalize(glm::cross(me, glm::vec3(0,1,0)));
    
    glm::vec3 v_es = n_v_es * speed;
    glm::vec3 v_me = v_es + n_v_me * speed2;
    
    object_vec[1].moveMat(v_es.x, v_es.y, v_es.z);
    object_vec[2].moveMat(v_me.x, v_me.y, v_me.z);
    
    if (KeyBoardAPI::Left()) {
        camera->moveMat(-speed2, 0,  0);
    }
    if (KeyBoardAPI::Right()) {
        camera->moveMat(speed2, 0,  0);
    }
    if (KeyBoardAPI::Up()) {
        camera->moveMat(0, -speed2, 0);
    }
    if (KeyBoardAPI::Down()) {
        camera->moveMat(0, speed2, 0);
    }
    if (KeyBoardAPI::Front()) {
        camera->moveMat(0, 0, speed2);
    }
    if (KeyBoardAPI::Back()) {
        camera->moveMat(0, 0, -speed2);
    }
    if (KeyBoardAPI::Rotatexp()) {
        camera->rotateMat(-speed, 0,  0);
    }
    if (KeyBoardAPI::Rotatexm()) {
        camera->rotateMat(speed, 0,  0);
    }
    if (KeyBoardAPI::Rotateyp()) {
        camera->rotateMat(0, -speed, 0);
    }
    if (KeyBoardAPI::Rotateym()) {
        camera->rotateMat(0, speed, 0);
    }
    if (KeyBoardAPI::Rotatezp()) {
        camera->rotateMat(0, 0, speed);
    }
    if (KeyBoardAPI::Rotatezm()) {
        camera->rotateMat(0, 0, -speed);
    }
}
