//
//  GameCamera.cpp
//  LoStudioEngine
//
//  Created by Yuhang Huang on 2019/07/11.
//  Copyright © 2019 Masaki Iwasaki. All rights reserved.
//

#include "GameCamera.hpp"
#include "../../BaseSystem.h"
#include "../../RenderApi.h"

void GameCamera::drawObjects(std::vector< GameObject * > meshes_group)
{
    for (auto * object : meshes_group) {
        auto * meshes = object->getMeshes_vec();
        glm::vec3 color = object->Color();
        std::vector < glm::vec3 > triangle;
        triangle.clear();
        for(auto verticle : (* meshes))
        {
            triangle.push_back(verticle);
            if(triangle.size() == 3) {
                drawMeshes(color, triangle);
                triangle.clear();
            }
        }
    }
}

void GameCamera::drawMeshes(glm::vec3 color, std::vector < glm::vec3 > triangle)
{
    RenderAPI::SetColor(color);
    glm::vec3 lookat_now = rotationTransform(lookat);
    glm::vec3 up_now = rotationTransform(up);
    glm::vec3 left_now = glm::cross(up_now, lookat_now);
    glm::vec3 n_la = glm::normalize(lookat_now);
    glm::vec3 n_up = glm::normalize(up_now);
    glm::vec3 n_le = glm::normalize(left_now);
    float x, y;
    float width = SCREEN_WIDTH / SCREEN_RATE / 2;
    float height = SCREEN_HEIGHT / SCREEN_RATE / 2;
    glm::vec2 triangle_2d[3];
    glm::vec3 depth(0,0,0);
    
    int inner = 0;
    
    for (int ind = 0; ind < 3; ind++)
    {
        glm::vec3 point = triangle[ind];
        glm::vec3 tar = point - location;
        glm::vec3 tar_la = glm::dot(n_la, tar) * n_la;
        glm::vec3 tar_2d = tar - tar_la;
        x = glm::dot(tar_2d, n_le);
        y = glm::dot(tar_2d, n_up);
        
        if(glm::abs(x) >= width || glm::abs(y) >= height)
        {
            inner++;
        }
        x = (x + width) * SCREEN_RATE;
        y = (y + height) * SCREEN_RATE;
        triangle_2d[ind] = glm::vec2(x, y);
    }
    if (inner < 3)
    {
        depth = glm::vec3(glm::dot(n_la, triangle[0]), glm::dot(n_la, triangle[1]), glm::dot(n_la, triangle[2]));
        RenderAPI::DrawTriangle(triangle_2d[0], triangle_2d[1], triangle_2d[2], depth);
        
        glm::vec3 color_n(0,0,0);
        RenderAPI::SetColor(color_n);
        
        RenderAPI::DrawLine(triangle_2d[0], triangle_2d[1], glm::vec2(depth.x, depth.y));
        RenderAPI::DrawLine(triangle_2d[1], triangle_2d[2], glm::vec2(depth.y, depth.z));
        RenderAPI::DrawLine(triangle_2d[2], triangle_2d[0], glm::vec2(depth.z, depth.x));
        
        RenderAPI::SetColor(color);
    }
}

void GameCamera::updateCamera()
{
    glm::vec3 loc = glm::vec3(0, 0, 0);
    location = locationTransform(loc);
}
