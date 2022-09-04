#pragma once

class GLFWwindow;

namespace GraphicsCourseEngine
{
    class Application
    {
    protected:
        GLFWwindow *window;

    public:
        Application();

        int Run();
        int Quit();
    };
}
