//#include "GameScene/GameSceneRasterize.hpp"
//#include "GameScene/GameSceneParallelProject.hpp"
#include "GameScene/GameScenePerspectiveProject.hpp"

#include "GameSceneMain.hpp"
#include "GameEngine/Scene/GameScene.hpp"

int GameSceneMain::Init()
{
    GameScenePerspectiveProject *scene = new GameScenePerspectiveProject();
    Create(scene);
    mainscene->initScene();
    return 0;
}
int GameSceneMain::Update()
{
    mainscene->updateScene();
    return 0;
}
int GameSceneMain::Draw()
{
    mainscene->drawScene();
    return 0;
}
