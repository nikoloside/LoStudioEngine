#include <stdio.h>

#include "RenderSystem.h"
#include "RenderApi.h"

#include "BaseSystem.h"
#include <iostream>
#include <vector>

/*
レンダリングAPIの実装。

ここの関数群はGameMain()呼び出される前提。
*/

int RenderAPI::GetScreenWidth()
{
    return SCREEN_WIDTH;
}

int RenderAPI::GetScreenHeight()
{
    return SCREEN_HEIGHT;
}

void RenderAPI::ClearScreen(glm::vec3 const & color)
{
    RenderSystem::Instance().SetColor(color);
    RenderSystem::Instance().Clear();
}

void RenderAPI::SetColor(const glm::vec3 &color)
{
    RenderSystem::Instance().SetColor(color);
}

void RenderAPI::DrawPoint(glm::vec2 const & point1, float depth)
{
    if (RenderSystem::Instance().ProcesszBuffer(point1, depth)) {
        RenderSystem::Instance().DrawPoint(point1);
    }
}

void RenderAPI::DrawCircle(glm::vec2 const & point1, float scale, float depth)
{
    for (int i = -(int)scale; i < (int) scale; i++) {
        for (int j = -(int)scale; j < (int) scale; j++){
            glm::vec2 point = glm::vec2(point1.x + i, point1.y + j);
            if ((i*i+j*j < scale - 1) && RenderSystem::Instance().ProcesszBuffer(point, depth)) {
                RenderSystem::Instance().DrawPoint(point);
            }
        }
    }
}

void RenderAPI::DrawLine(glm::vec2 const & point1, glm::vec2 const & point2, glm::vec2 depth)
{
    glm::vec2 point = point2 - point1;
    float length = glm::length(point);
    glm::vec2 n = normalize(point);
    for(int len = 0; len < length; len++){
        point.x = point1.x + n.x * len;
        point.y = point1.y + n.y * len;
        
        float d = depth.x + (depth.y - depth.x) / length * len;
        if (RenderSystem::Instance().ProcesszBuffer(point, d)) {
            RenderSystem::Instance().DrawPoint(point);
        }
    }
}

std::vector < glm::vec2 > minLine(glm::vec2 const & point1, glm::vec2 const & point2, glm::vec2 const & point3, glm::vec3 depth)
{
    std::vector< glm::vec2 > result;
    glm::vec2 point_1 = point2 - point1;
    glm::vec2 point_2 = point3 - point2;
    glm::vec2 point_3 = point1 - point3;
    
    float len_1 = glm::length(point_1);
    float len_2 = glm::length(point_2);
    float len_3 = glm::length(point_3);
    
    if(len_1 < len_2 && len_1 < len_3)
    {
        result.push_back(point1);
        result.push_back(point_1);
        result.push_back(point3);
        result.push_back(glm::vec2(depth.y, depth.x));
        result.push_back(glm::vec2(depth.z, 0));
    } else if (len_2 < len_3)
    {
        result.push_back(point2);
        result.push_back(point_2);
        result.push_back(point1);
        result.push_back(glm::vec2(depth.z, depth.y));
        result.push_back(glm::vec2(depth.x, 0));
    } else
    {
        result.push_back(point3);
        result.push_back(point_3);
        result.push_back(point2);
        result.push_back(glm::vec2(depth.x, depth.z));
        result.push_back(glm::vec2(depth.y, 0));
    }
    return result;
}

void RenderAPI::DrawTriangle(glm::vec2 const & point1, glm::vec2 const & point2, glm::vec2 const & point3, glm::vec3 depth)
{
    std::vector < glm::vec2 > point = minLine(point1, point2, point3, depth);
    
    float length = glm::length(point[1]);
    glm::vec2 n = normalize(point[1]);
    for(int len = 0; len < length; len++){
        point[1].x = point[0].x + n.x * len;
        point[1].y = point[0].y + n.y * len;
        
        float d_line = point[3].y + (point[3].x - point[3].y) / length * len;
        RenderAPI::DrawLine(point[2], point[1], glm::vec2(point[4].x, d_line));
    }
}

void RenderAPI::ResetzBuffer(){
    RenderSystem::Instance().ResetzBuffer();
}

/*
bool pixelContainedIn2DTriangle(glm::vec2 const & point1, glm::vec2 const & point2, glm::vec2 const & point3, glm::vec2 const & point)
{
    glm::vec2 ab = point2 - point1;
    glm::vec2 bc = point3 - point2;
    glm::vec2 ca = point1 - point3;
    glm::vec2 bp = point - point2;
    glm::vec2 cp = point - point3;
    glm::vec2 ap = point - point1;
    
    float c1 = ab.x * bp.y - ab.y * bp.x;
    double c2 = bc.x * cp.y - bc.y * cp.x;
    double c3 = ca.x * ap.y - ca.y * ap.x;
    
    if( ( c1 > 0 && c2 > 0 && c3 > 0 ) || ( c1 < 0 && c2 < 0 && c3 < 0 ) ) {
        return true;
    }
    return false;
    
}

void RenderAPI::DrawTriangle(glm::vec2 const & point1, glm::vec2 const & point2, glm::vec2 const & point3)
{
    
    uint xmin = std::max(0, std::min(SCREEN_WIDTH - 1, (int)std::min(point1.x, std::min(point2.x, point3.x))));
    
    uint ymin = std::max(0, std::min(SCREEN_HEIGHT - 1, (int)std::min(point1.y, std::min(point2.x, point3.x))));
    
    uint xmax = std::max(0, std::min(SCREEN_WIDTH - 1, (int)std::max(point1.x, std::max(point2.x, point3.x))));
    
    uint ymax = std::max(0, std::min(SCREEN_HEIGHT - 1, (int)std::max(point1.y, std::max(point2.x, point3.x))));
    
    for (uint y = ymin; y <= ymax; ++y) {
        for (uint x = xmin; x <= xmax; ++x) {
            glm::vec2 point = glm::vec2(x,y);
            if (pixelContainedIn2DTriangle(point1, point2, point3, point)) {
                RenderAPI::DrawPoint(point);
            }
        }
    }
 
}*/
