class Line 
{
private:
    glm::vec3 m_Camera;
    Shader ourShader;

    glm::mat4 proj;
    glm::mat4 view;
    glm::mat4 model;

    glm::mat4 mvp;

    float vertices[12];
    unsigned int indices[6];
    unsigned int VBO, VAO, EBO;
public:
    Line(int x, int y);
    ~Line();
    void show() const;
    void fall();
};