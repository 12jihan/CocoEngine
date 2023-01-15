#include "headers/Meshy.h"

Meshy(vector<Vertex> vertices, vector<unsigned int> indices, vecture<Texture> textures) {
    this -> vertices = vertices;
    this -> indices = indices;
    this -> textures = textures;

    setupMesh();
}

void setupMesh() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray()
}