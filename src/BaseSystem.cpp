#include <stdio.h>
#include <SDL.h>

#include "GameMain.h"
#include "BaseSystem.h"
#include "RenderSystem.h"

int main( int argc, char* args[] )
{
    //The window we'll be rendering to
    SDL_Window* window = NULL;
    
    SDL_Renderer* renderer;
    
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        window = SDL_CreateWindow( "3D Graphics Basic", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            renderer = SDL_CreateRenderer(window, -1, 0);
            RenderSystem::Instance().SetRenderer(renderer);
            
            bool quit = false;
            SDL_Event e;
            
            GameSetup();
            
            unsigned int lastTime = 0;
            
            while (!quit) {
                while (SDL_PollEvent(&e)) {
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                }
                
                GameMain();
                RenderSystem::Instance().Present();
                
                // max 60fps
                unsigned int dTime = SDL_GetTicks() - lastTime;
                if(dTime<FRAME_INTERVAL_MSEC)
                {
                    SDL_Delay(FRAME_INTERVAL_MSEC-dTime);
                }
                lastTime = SDL_GetTicks();
            }
        }
    }
    
    //Destroy window
    SDL_DestroyWindow( window );
    
    //Quit SDL subsystems
    SDL_Quit();
    
    return 0;
}

