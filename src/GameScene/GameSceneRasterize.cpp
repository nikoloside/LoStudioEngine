#include <iostream>
#include "RenderApi.h"

int SampleSceneRun(void)
{
    glm::vec3 white(1, 1, 1);
    //glm::vec3 lightGray(0.75, 0.75, 0.75);
    //glm::vec3 gray(0.5, 0.5, 0.5);
    glm::vec3 red(1, 0, 0);
    glm::vec3 green(0, 1, 0);
    glm::vec3 blue(0, 0, 1);
    
    RenderAPI::ClearScreen(white);
    
    glm::vec2 offset(100.f, 10.f);
    glm::vec2 triangle1[] = {
        glm::vec2(10.f, 10.f) +offset,
        glm::vec2(100.f, 20.f)+offset,
        glm::vec2(20.f, 100.f)+offset
    };
    RenderAPI::SetColor(red);
    RenderAPI::DrawLine(triangle1[0], triangle1[1], glm::vec2(3,3));
    RenderAPI::DrawLine(triangle1[1], triangle1[2], glm::vec2(3,3));
    RenderAPI::DrawLine(triangle1[2], triangle1[0], glm::vec2(3,3));
    
    offset = glm::vec2(100.f, 200.f);
    glm::vec2 triangle2[] = {
        glm::vec2(10.f, 10.f) +offset,
        glm::vec2(10.f, 100.f)+offset,
        glm::vec2(100.f, 50.f)+offset
    };
    RenderAPI::SetColor(green);
    RenderAPI::DrawLine(triangle2[0], triangle2[1], glm::vec2(3,3));
    RenderAPI::DrawLine(triangle2[1], triangle2[2], glm::vec2(3,3));
    RenderAPI::DrawLine(triangle2[2], triangle2[0], glm::vec2(3,3));
    
    offset = glm::vec2(100.f, 400.f);
    glm::vec2 triangle3[] = {
        glm::vec2(10.f, 10.f) +offset,
        glm::vec2(100.f, 10.f)+offset,
        glm::vec2(50.f, 100.f)+offset
    };
    RenderAPI::SetColor(blue);
    RenderAPI::DrawLine(triangle3[0], triangle3[1], glm::vec2(3,3));
    RenderAPI::DrawLine(triangle3[1], triangle3[2], glm::vec2(3,3));
    RenderAPI::DrawLine(triangle3[2], triangle3[0], glm::vec2(3,3));
    
    offset = glm::vec2(300.f, 10.f);
    glm::vec2 triangle4[] = {
        glm::vec2(10.f, 10.f) +offset,
        glm::vec2(100.f, 20.f)+offset,
        glm::vec2(20.f, 100.f)+offset
    };
    RenderAPI::SetColor(red);
    RenderAPI::DrawTriangle(triangle4[0], triangle4[1], triangle4[2], glm::vec3(3,3,3));
    
    offset = glm::vec2(300.f, 200.f);
    glm::vec2 triangle5[] = {
        glm::vec2(10.f, 10.f) +offset,
        glm::vec2(10.f, 100.f)+offset,
        glm::vec2(100.f, 50.f)+offset
    };
    RenderAPI::SetColor(green);
    RenderAPI::DrawTriangle(triangle5[0], triangle5[1], triangle5[2] , glm::vec3(3,3,3));
    
    offset = glm::vec2(300.f, 400.f);
    glm::vec2 triangle6[] = {
        glm::vec2(10.f, 10.f) +offset,
        glm::vec2(100.f, 10.f)+offset,
        glm::vec2(50.f, 100.f)+offset
    };
    RenderAPI::SetColor(blue);
    RenderAPI::DrawTriangle(triangle6[0], triangle6[1], triangle6[2], glm::vec3(3,3,3));
    
    return 0;
    
}

