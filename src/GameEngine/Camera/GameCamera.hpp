//
//  GameCamera.hpp
//  LoStudioEngine
//
//  Created by Yuhang Huang on 2019/07/11.
//  Copyright © 2019 Masaki Iwasaki. All rights reserved.
//

#ifndef GameCamera_hpp
#include <iostream>
#include <vector>
#include "../Object/GameObjectBase.hpp"
#include "../Object/GameObject.hpp"
#define GameCamera_hpp

#include "../../glm/glm.hpp"

class GameCamera : public GameObjectBase
{
private:
    
public:
    
    void drawObjects(std::vector< GameObject * >  meshes_group);
    
    void setCamera(float lookat_x, float lookat_y, float lookat_z, float up_x, float up_y, float up_z)
    {
        lookat = glm::vec3(lookat_x, lookat_y, lookat_z);
        up = glm::vec3(up_x, up_y, up_z);
    }
    
    void updateCamera();
protected:
    
    glm::vec3 lookat;
    glm::vec3 up;
    glm::vec3 location;
    virtual void drawMeshes(glm::vec3 color, std::vector < glm::vec3 > triangle);
};

#endif /* GameCamera_hpp */
