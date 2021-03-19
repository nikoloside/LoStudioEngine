//
//  KeyBoardAPI.cpp
//  LoStudioEngine
//
//  Created by Niko Huang on 2019/7/21.
//  Copyright © 2019 Masaki Iwasaki. All rights reserved.
//

#include "KeyBoardAPI.hpp"
#include <SDL.h>

void KeyBoardAPI::Update(){
    
}
bool KeyBoardAPI::Left(){
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_A]) {
        return true;
    } else {
        return false;
    }
}
bool KeyBoardAPI::Right(){
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_D]) {
        return true;
    } else {
        return false;
    }
}
bool KeyBoardAPI::Up(){
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_Q]) {
        return true;
    } else {
        return false;
    }
}
bool KeyBoardAPI::Down(){
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_E]) {
        return true;
    } else {
        return false;
    }
}
bool KeyBoardAPI::Front(){
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_W]) {
        return true;
    } else {
        return false;
    }
}
bool KeyBoardAPI::Back(){
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_S]) {
        return true;
    } else {
        return false;
    }
}

bool KeyBoardAPI::Rotatexp(){
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_J]) {
        return true;
    } else {
        return false;
    }
}
bool KeyBoardAPI::Rotatexm(){
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_L]) {
        return true;
    } else {
        return false;
    }
}
bool KeyBoardAPI::Rotateyp(){
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_U]) {
        return true;
    } else {
        return false;
    }
}
bool KeyBoardAPI::Rotateym(){
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_O]) {
        return true;
    } else {
        return false;
    }
}
bool KeyBoardAPI::Rotatezp(){
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_I]) {
        return true;
    } else {
        return false;
    }
}
bool KeyBoardAPI::Rotatezm(){
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_K]) {
        return true;
    } else {
        return false;
    }
}
