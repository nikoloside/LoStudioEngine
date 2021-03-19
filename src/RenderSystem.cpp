
#include <SDL.h>

#include "RenderSystem.h"

void RenderSystem::SetRenderer(SDL_Renderer* _renderer)
{
    renderer = _renderer;
}

void RenderSystem::Present()
{
    SDL_RenderPresent(renderer);
}

void RenderSystem::SetColor(glm::vec3 const & color)
{
	unsigned char r = (unsigned char)glm::clamp((int)(color.r * 255), 0, 255);
	unsigned char g = (unsigned char)glm::clamp((int)(color.g * 255), 0, 255);
	unsigned char b = (unsigned char)glm::clamp((int)(color.b * 255), 0, 255);

    const unsigned char a = 255;
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void RenderSystem::Clear(){
    SDL_RenderClear(renderer);
}

void RenderSystem::DrawPoint(glm::vec2 const & point){
    SDL_RenderDrawPoint(renderer, (int)point.x, (int)point.y);
}

void RenderSystem::ResetzBuffer(){
    for (unsigned int i = 0; i < SCREEN_WIDTH; i++){
        for (unsigned int j = 0; j < SCREEN_HEIGHT; j++){
            zBuffer[i][j] = (float)DEPTH_INFINITE;
        }
    }
}

bool RenderSystem::ProcesszBuffer(glm::vec2 const & point, float depth){
    if ((int)point.x < 0 || (int)point.y < 0 || (int)point.x >= SCREEN_WIDTH || (int) point.y >= SCREEN_HEIGHT )
        return false;
    if (depth < zBuffer[(int)point.x][(int)point.y])
    {
        zBuffer[(int)point.x][(int)point.y] = depth;
        return true;
    } else
        return false;
}
