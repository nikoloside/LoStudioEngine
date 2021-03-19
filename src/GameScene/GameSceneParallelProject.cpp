#include "GameSceneParallelProject.hpp"
#include "GameSceneBGUniverse.hpp"
#include "../KeyBoardAPI.hpp"

void GameSceneParallelProject::setup()
{
    GameSceneBGUniverse * bg = new GameSceneBGUniverse();
    bg->setType(BG_DIY);
    createBG(bg);
    
    GameObject * object2 = new GameObject();
    object2->moveMat(-2,0, 0);
    object2->loadMeshes("triangle_cube.obj");
    object2->setColor(0, 1, 0, 1);
    addObject(*object2);
    
    GameObject * object3 = new GameObject();
    object3->moveMat(2, 0, 0);
    object3->loadMeshes("triangle_cube.obj");
    object3->setColor(0, 0, 1, 1);
    addObject(*object3);
    
    GameObject * object1 = new GameObject();
    object1->moveMat(  0,0,0);
    object1->loadMeshes("triangle_cone.obj");
    object1->setColor(1, 0, 0, 1);
    addObject(*object1);
    
    GameCamera * camera = new GameCamera();
    camera->moveMat(0, 0, -5);
    camera->setCamera(0, 0, 1, 0, 1, 0);
    
    createCamera(camera);
}

void GameSceneParallelProject::update()
{
    unsigned int dTime = getDTime();
    //std::cout << SDL_GetTicks() << " " << (float)dTime << std::endl;
    float speed = 1 * (float)dTime / 1000 ;
    object_vec[0].rotateMat(0, speed, speed);
    object_vec[1].rotateMat(speed, speed, 0);
    object_vec[2].rotateMat(speed, speed, 0);
    
    if (KeyBoardAPI::Left()) {
        object_vec[1].moveMat(-speed, 0,  0);
    }
    if (KeyBoardAPI::Right()) {
        object_vec[1].moveMat(speed, 0,  0);
    }
    if (KeyBoardAPI::Up()) {
        object_vec[1].moveMat(0, -speed, 0);
    }
    if (KeyBoardAPI::Down()) {
        object_vec[1].moveMat(0, speed, 0);
    }
    if (KeyBoardAPI::Front()) {
        object_vec[1].moveMat(0, 0, speed);
    }
    if (KeyBoardAPI::Back()) {
        object_vec[1].moveMat(0, 0, -speed);
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
