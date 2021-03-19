//
//  GameObjectBase.cpp
//  LoStudioEngine
//
//  Created by Yuhang Huang on 2019/07/11.
//  Copyright © 2019 Masaki Iwasaki. All rights reserved.
//

#include "GameObjectBase.hpp"

GameObjectBase * GameObjectBase::moveMat(float x, float y, float z)
{
    float mat[16] = {1,0,0,0, 0,1,0,0, 0,0,1,0, x,y,z,1};
    locationMat = glm::make_mat4(mat) * locationMat;
    return this;
}
GameObjectBase * GameObjectBase::scalingMat(float x, float y, float z)
{
    float mat[16] = {x,0,0,0, 0,y,0,0, 0,0,z,0, 0,0,0,1};
    scaleMat = glm::make_mat4(mat) * scaleMat;
    return this;
}
GameObjectBase * GameObjectBase::rotateMat(float x, float y, float z)
{
    float cos_x = glm::cos(x);
    float sin_x = glm::sin(x);
    float cos_y = glm::cos(y);
    float sin_y = glm::sin(y);
    float cos_z = glm::cos(z);
    float sin_z = glm::sin(z);
    
    float mat_x[16] = {1,0,0,0, 0,cos_x,sin_x,0, 0,-sin_x,cos_x,0, 0,0,0,1};
    rotationMat = glm::make_mat4(mat_x) * rotationMat;
    
    float mat_y[16] = {cos_y,0,-sin_y,0, 0,1,0,0, sin_y,0,cos_y,0, 0,0,0,1};
    rotationMat = glm::make_mat4(mat_y) * rotationMat;
    
    float mat_z[16] = {cos_z,sin_z,0,0, -sin_z,cos_z,0,0, 0,0,1,0, 0,0,0,1};
    rotationMat = glm::make_mat4(mat_z) * rotationMat;
    return this;
}
glm::vec3 GameObjectBase::globalTransform(glm::vec3 vec)
{
    glm::vec4 temp_vec(vec.x, vec.y, vec.z, 1);
    glm::vec4 result = scaleMat * temp_vec;
    result = rotationMat * result;
    result = locationMat * result;
    glm::vec3 vec_result(result/result.w);
    return vec_result;
}

glm::vec3 GameObjectBase::locationTransform(glm::vec3 vec)
{
    glm::vec4 temp_vec(vec.x, vec.y, vec.z, 1);
    glm::vec4 result = locationMat * temp_vec;
    glm::vec3 vec_result(result/result.w);
    return vec_result;
}

glm::vec3 GameObjectBase::rotationTransform(glm::vec3 vec)
{
    glm::vec4 temp_vec(vec.x, vec.y, vec.z, 1);
    glm::vec4 result = rotationMat * temp_vec;
    glm::vec3 vec_result(result/result.w);
    return vec_result;
}
