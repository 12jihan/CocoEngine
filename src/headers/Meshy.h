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
        vector<Vertex>  vertices;
        vector<unsigned int> indices;
        vector<Texture> textures;
    
        Meshy(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
        void Draw(Shader &shader);
    private:
        // render data
        unsigned int VAO, VBO, EBO;

        void setupMesh();
};