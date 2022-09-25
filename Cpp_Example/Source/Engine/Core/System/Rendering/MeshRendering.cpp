#include "MeshRendering.h"

#define STB_IMAGE_IMPLEMENTATION
#include "Utils/Material.h"

#include "../../GameObject.h"
#include "../../Transform.h"
#include "Data/CommonShaders.h"
#include "Data/CommonModels.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace GraphicsCourseEngine;

MeshRendering::MeshRendering(GameObject* holdingGameObject) : Component(holdingGameObject)
{
    const char* diffuseTexturePath = "bricks.jpg";
    renderingMatrial = new Material(vertexShaderSource, fragmentShaderSource, diffuseTexturePath);

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(CubeVertices), CubeVertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
    glEnableVertexAttribArray(2);

    renderingMatrial->Render();
}

void MeshRendering::UpdateComponent()
{
    test += 0.1f;
    renderingMatrial->diffuseColor.r = abs(sin(test));
}

void MeshRendering::Render(glm::mat4 projection, glm::mat4 view)
{
    renderingMatrial->renderingShader.setMat4("projection", projection);
    renderingMatrial->renderingShader.setMat4("view", view);

    renderingMatrial->Render();

    // render boxes
    glBindVertexArray(VAO);

    renderingMatrial->renderingShader.setMat4("model", holdingGameObject->GetTransform()->CalculateGlobalTransformationMatrix());

    glDrawArrays(GL_TRIANGLES, 0, 36);    
}

MeshRendering::~MeshRendering()
{
    delete renderingMatrial;
}