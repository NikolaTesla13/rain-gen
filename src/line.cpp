#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <shader.h>
#include <line.h>

Line::Line(int x, int y)
{
    m_Camera = glm::vec3(0,0,0);

    proj = glm::ortho(0.0f, 640.0f, 0.0f, 360.0f, -1.0f, 1.0f);
    view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
    model = glm::translate(glm::mat4(1.0f), m_Camera);

    mvp = view * proj * model;

    vertices[0] = x + 5.0f;
    vertices[1] = y + 10.0f;
    vertices[2] = 0.0f;
    vertices[3] = x + 5.0f;
    vertices[4] = y + 0.0f;
    vertices[5] = 0.0f;
    vertices[6] = x + 0.0f;
    vertices[7] = y + 0.0f;
    vertices[8] = 0.0f;
    vertices[9] = x + 0.0f;
    vertices[10] = y + 10.0f;
    vertices[11] = 0.0f;

    indices[0] = 0;
    indices[1] = 1;
    indices[2] = 3;
    indices[3] = 1;
    indices[4] = 2;
    indices[5] = 3;



    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0); 

    ourShader.use();
    ourShader.setVec3("aColor", 138/255.0f, 43/255.0f, 226/255.0f);
    ourShader.setMat4("u_MVP", mvp);
}

Line::~Line()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Line::fall()
{
    m_Camera.y -= 0.1;
    model = glm::translate(glm::mat4(1.0f), m_Camera);
    mvp = view * proj * model;
        
    ourShader.use();
    ourShader.setMat4("u_MVP", mvp);
}

void Line::show() const
{
    glBindVertexArray(VAO);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

}