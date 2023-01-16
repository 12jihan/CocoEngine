#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec3 TexCoords;
};

struct Texture {
    unsigned int id;
    std::string type;
};

class Meshy {
    public:
        // mesh data
        std::vector<Vertex>  vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;
    
        Meshy(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
        void Draw(Shader &shader);
    private:
        // render data
        unsigned int VAO, VBO, EBO;

        void setupMesh();
};