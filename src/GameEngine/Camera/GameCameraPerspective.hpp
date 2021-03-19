//
//  GameCameraPerspective.hpp
//  LoStudioEngine
//
//  Created by Niko Huang on 2019/7/21.
//  Copyright © 2019 Masaki Iwasaki. All rights reserved.
//

#ifndef GameCameraPerspective_hpp
#include "GameCamera.hpp"
#define GameCameraPerspective_hpp

#include <stdio.h>

class GameCameraPerspective : public GameCamera
{
private:
    float d_focus = 5;
public:
    void setFocus(float d){
        d_focus = d;
    }
protected:
    void drawMeshes(glm::vec3 color, std::vector < glm::vec3 > triangle);
};
#endif /* GameCameraPerspective_hpp */
