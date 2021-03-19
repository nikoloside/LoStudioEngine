#pragma once

#include "glm/glm.hpp"
#include "BaseSystem.h"

struct SDL_Renderer;

class RenderSystem 
{
private:
    float zBuffer[SCREEN_WIDTH][SCREEN_HEIGHT];
public:
	static RenderSystem & Instance()
	{
		static RenderSystem instance;
		return instance;
	}

    void SetRenderer(SDL_Renderer* _renderer);
    void Present();
    
	void SetColor(glm::vec3 const & color);
    void Clear();
    void DrawPoint(glm::vec2 const & point);
    void ResetzBuffer();
    bool ProcesszBuffer(glm::vec2 const & point, float depth);
    
protected:
	RenderSystem():
		renderer(nullptr)
	{}
	RenderSystem(RenderSystem const & st) {}
    void operator=(RenderSystem const & st) {}

	virtual ~RenderSystem() {}

    SDL_Renderer* renderer;
};

