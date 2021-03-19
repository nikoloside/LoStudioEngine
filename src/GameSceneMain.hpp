#pragma once

#include "GameEngine/Scene/GameScene.hpp"

class GameSceneMain
{
private:
    GameScene *mainscene;
public:
    static GameSceneMain& Instance()
    {
        static GameSceneMain instance;
        return instance;
    }
    int Init();
    int Update();
    int Draw();
protected:
    void Create( GameScene *scene )
    {
        mainscene = scene;
    }
};
