//
//  GameObjectBase.hpp
//  LoStudioEngine
//
//  Created by Yuhang Huang on 2019/07/11.
//  Copyright © 2019 Masaki Iwasaki. All rights reserved.
//

#ifndef GameObjectBase_hpp
#define GameObjectBase_hpp

#include "../../glm/glm.hpp"
#include "../../glm/gtc/type_ptr.hpp"

class GameObjectBase
{
private:
    glm::mat4 rotationMat;
    glm::mat4 locationMat;
    glm::mat4 scaleMat;
    
public:
    GameObjectBase(){
        float ro[16] = {1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1};
        locationMat = glm::make_mat4(ro);
        rotationMat = glm::make_mat4(ro);
        scaleMat = glm::make_mat4(ro);
    }
    GameObjectBase * moveMat(float x, float y, float z); // locationMat だけ変更
    GameObjectBase * rotateMat(float x, float y, float z); // rotationMat だけ変更
    GameObjectBase * scalingMat(float x, float y, float z); // rotationMat だけ変更
    glm::vec3 globalTransform(glm::vec3 vec); // vec のglobal座標への変換
    glm::vec3 locationTransform(glm::vec3 vec); // vec のglobal座標への変換
    glm::vec3 rotationTransform(glm::vec3 vec); // vec のglobal座標への変換
    glm::vec3 getLocation()
    {
        glm::vec3 location(locationMat[3][0],locationMat[3][1],locationMat[3][2]);
        return location;
    }
    
protected:
    
};
#endif /* GameObjectBase_hpp */
