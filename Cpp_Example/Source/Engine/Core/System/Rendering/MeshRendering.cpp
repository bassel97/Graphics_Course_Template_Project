#include "MeshRendering.h"
#include "../../GameObject.h"
#include "../../Transform.h"
#include "Utils/Shader.h"
#include "Utils/CommonShaders.h"
#include "Utils/CommonModels.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace GraphicsCourseEngine;

MeshRendering::MeshRendering(GameObject* holdingGameObject) : Component(holdingGameObject)
{
    // build and compile our shader zprogram
    // ------------------------------------
    ourShader = new Shader(vertexShaderSource, fragmentShaderSource);

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(CubeVertices), CubeVertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    ourShader->use();
}

MeshRendering::~MeshRendering()
{
    delete ourShader;
}

void MeshRendering::Render(glm::mat4 projection, glm::mat4 view)
{
    ourShader->setMat4("projection", projection);
    ourShader->setMat4("view", view);

    // render boxes
    glBindVertexArray(VAO);

    ourShader->setMat4("model", holdingGameObject->GetTransform()->CalculateGlobalTransformationMatrix());

    glDrawArrays(GL_TRIANGLES, 0, 36);    
}