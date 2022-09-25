#include "Application.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core/Scene.h"
#include "Core/System/Rendering/RenderingSystem.h"

int GraphicsCourseEngine::Application::width = 1024;
int GraphicsCourseEngine::Application::height = 720;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    GraphicsCourseEngine::Application::width = width;
    GraphicsCourseEngine::Application::height = height;
}

GraphicsCourseEngine::Application::Application()
{
    // Initialize the library
    if (!glfwInit())
        return;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(width, height, "Course Game", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Make the window's context current
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
    std::cout << "Application Initiated\n";
}

int GraphicsCourseEngine::Application::Run()
{
    std::cout << "Application Started\n";

    Scene* mainScene = new Scene("Main"); 

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);

        mainScene->UpdateScene();

        RenderingSystem::RenderScene(mainScene);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    std::cout << "Application Quit\n";

    return 0;
}

int GraphicsCourseEngine::Application::Quit()
{
    return 0;
}