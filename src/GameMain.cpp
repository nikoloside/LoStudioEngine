#include <iostream>
#include "GameSceneMain.hpp"

static int loop_count = 0;

int GameSetup(void)
{
    GameSceneMain::Instance().Init();
    return 0;
}
int GameMain()
{
    GameSceneMain::Instance().Update();
    GameSceneMain::Instance().Draw();
	std::cout << "GameMain : " << loop_count << "\n";
	loop_count++;

	return 0;

}

