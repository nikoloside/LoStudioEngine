//
//  GameObject.hpp
//  LoStudioEngine
//
//  Created by Yuhang Huang on 2019/07/11.
//  Copyright © 2019 Masaki Iwasaki. All rights reserved.
//

#ifndef GameObject_hpp
#include "./GameObjectBase.hpp"
#include <vector>
#define GameObject_hpp

#include "../../glm/glm.hpp"

class GameObject : public GameObjectBase
{
private:
    
    std::vector < glm::vec3 > meshes_vec;
    std::vector < glm::vec3 > vertices_vec;
    std::vector < int > facesIndex_vec;
    int num_points;
    int num_faces;
    glm::vec3 color = glm::vec3(1, 1, 1);
    
public:
    
    void updateMeshes();
    void loadMeshes(const char *filename);
    std::vector < glm::vec3 > * getMeshes_vec()
    {
        return &meshes_vec;
    }
    void setColor(float r, float g, float b, float a)
    {
        color = glm::vec3(r,g,b);
    }
    glm::vec3 Color()
    {
        return color;
    }
    
protected:
    
    void setMeshes(std::vector < glm::vec3 > meshes)
    {
        meshes_vec = meshes;
    }
    void setVertices(std::vector < glm::vec3 > vertices)
    {
        vertices_vec = vertices;
    }
    void setFacesIndex(std::vector < int > faces)
    {
        facesIndex_vec = faces;
    }
    void setInfo(int points, int faces)
    {
        num_points = points;
        num_faces = faces;
    }
};

#endif /* GameObject_hpp */
