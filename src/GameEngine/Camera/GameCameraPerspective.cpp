//
//  GameCameraPerspective.cpp
//  LoStudioEngine
//
//  Created by Niko Huang on 2019/7/21.
//  Copyright © 2019 Masaki Iwasaki. All rights reserved.
//

#include "GameCameraPerspective.hpp"
#include "../../RenderApi.h"
#include "../../BaseSystem.h"

void GameCameraPerspective::drawMeshes(glm::vec3 color, std::vector < glm::vec3 > triangle)
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
        float rate = d_focus / glm::length(tar_la);
        glm::vec3 tar_2d = (tar - tar_la) * rate;
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
        float tar1 = glm::length(triangle[0] - location);
        float tar2 = glm::length(triangle[1] - location);
        float tar3 = glm::length(triangle[2] - location);
        float la1 = glm::dot(n_la, triangle[0] - location);
        float la2 = glm::dot(n_la, triangle[1] - location);
        float la3 = glm::dot(n_la, triangle[2] - location);
        float d1 = tar1 * (la1 > d_focus ? la1 - d_focus : 0) / la1;
        float d2 = tar2 * (la2 > d_focus ? la2 - d_focus : 0) / la2;
        float d3 = tar3 * (la3 > d_focus ? la3 - d_focus : 0) / la3;
        
        depth = glm::vec3(d1, d2, d3);
        RenderAPI::DrawTriangle(triangle_2d[0], triangle_2d[1], triangle_2d[2], depth);
        
        glm::vec3 color_n(color.x * .7, color.y * .7 ,color.z * .7);
        RenderAPI::SetColor(color_n);
        
        RenderAPI::DrawLine(triangle_2d[0], triangle_2d[1], glm::vec2(depth.x, depth.y));
        RenderAPI::DrawLine(triangle_2d[1], triangle_2d[2], glm::vec2(depth.y, depth.z));
        RenderAPI::DrawLine(triangle_2d[2], triangle_2d[0], glm::vec2(depth.z, depth.x));
        
        RenderAPI::SetColor(color);
    }
}
