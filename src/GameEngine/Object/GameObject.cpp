//
//  GameObject.cpp
//  LoStudioEngine
//
//  Created by Yuhang Huang on 2019/07/11.
//  Copyright © 2019 Masaki Iwasaki. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "GameObject.hpp"

void GameObject::loadMeshes(const char *filename)
{
    std::ifstream in(filename, std::ios::in);
    if (!in)
    {
        std::cerr << "Cannot open " << filename << std::endl;
        exit(1);
        
    }
    std::string line;
    std::vector < glm::vec3 > vertices;
    std::vector < int > faceIndex;
    while (std::getline(in, line))
    {
        //check v for vertices
        if (line.substr(0,2)=="v "){
            std::istringstream v(line.substr(2));
            glm::vec3 vert;
            double x,y,z;
            v>>x;v>>y;v>>z;
            vert=glm::vec3(x,y,z);
            vertices.push_back(vert);
        }
        /* まだTexture実装しない
        //check for texture co-ordinate
        else if(line.substr(0,2)=="vt"){
            
            std::istringstream v(line.substr(3));
            glm::vec2 tex;
            int U,V;
            v>>U;v>>V;
            tex=glm::vec2(U,V);
            texture.push_back(tex);
            
        }
         */
        //check for faces
        else if(line.substr(0,2)=="f "){
            int a,b,c; //to store mesh index
            // int A,B,C; //to store texture index  まだTexture実装しない
            //std::istringstream v;
            //v.str(line.substr(2));
            const char* chh=line.c_str();
            //sscanf (chh, "f %i/%i %i/%i %i/%i",&a,&A,&b,&B,&c,&C); //here it read the line start with f and store the corresponding values in the variables
            sscanf (chh, "f %i %i %i",&a,&b,&c); // まだTexture実装しない
            
            //v>>a;v>>b;v>>c;
            a--;b--;c--;
            // A--;B--;C--; // まだTexture実装しない
            //std::cout<<a<<b<<c<<A<<B<<C;
            faceIndex.push_back(a);// textureIndex.push_back(A); // まだTexture実装しない
            faceIndex.push_back(b);// textureIndex.push_back(B); // まだTexture実装しない
            faceIndex.push_back(c);// textureIndex.push_back(C); // まだTexture実装しない
        }
        
    }
    //the mesh data is finally calculated here
    std::vector < glm::vec3 > meshVertices;
    meshVertices.clear();
    for(unsigned int i=0;i<faceIndex.size();i++)
    {
        glm::vec3 meshData;
        // glm::vec2 texData;  // まだTexture実装しない
        meshData=glm::vec3(vertices[faceIndex[i]].x,vertices[faceIndex[i]].y,vertices[faceIndex[i]].z);
        // texData=glm::vec2(texture[textureIndex[i]].x,texture[textureIndex[i]].y);  // まだTexture実装しない
        meshVertices.push_back(meshData);
        // texCoord.push_back(texData); // まだTexture実装しない
    }
    setMeshes(meshVertices);
    setVertices(vertices);
    setFacesIndex(faceIndex);
    setInfo((int)vertices.size(), (int)faceIndex.size());
}

void GameObject::updateMeshes()
{
    std::vector < glm::vec3 > vertices = vertices_vec;
    for(unsigned int i=0;i<vertices.size();i++) {
        vertices[i] = globalTransform(vertices[i]);
    }
    for(unsigned int i=0;i<facesIndex_vec.size();i++)
    {
        meshes_vec[i] = vertices[facesIndex_vec[i]];
    }
}
