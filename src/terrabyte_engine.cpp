#include "terrabyte.h"

namespace pkr
{
    void SetEngineVSync(bool b)
    {
        glfwSwapInterval(b ? 1 : 0);
    }

    void SetWindowTitle(TERRABYTE_ENGINE& engine, std::string title)
    {
        glfwSetWindowTitle(engine.window, title.c_str());
    }

    VEC2D GetMousePosition(TERRABYTE_ENGINE& engine)
    {
        VEC2D vec;
        glfwGetCursorPos(engine.window, &vec.x, &vec.y);
        return vec;
    }

    VEC2F GetWindowContentScale(TERRABYTE_ENGINE& engine)
    {
        VEC2F vec;
        glfwGetWindowContentScale(engine.window, &vec.x, &vec.y);
        return vec;
    }

    VEC2I GetFrameBufferSize(TERRABYTE_ENGINE& engine)
    {
        VEC2I vec;
        glfwGetFramebufferSize(engine.window, &vec.x, &vec.y);
        return vec;
    }

    VEC2I GetWindowSize(TERRABYTE_ENGINE& engine)
    {
        VEC2I vec;
        glfwGetWindowSize(engine.window, &vec.x, &vec.y);
        return vec;
    }

    float GetWindowAspectRatio(TERRABYTE_ENGINE& engine)
    {
        VEC2I size = GetWindowSize(engine);
        return (float) (size.x / size.y);
    }

    TERRABYTE_ENGINE* CreateEngine(uint32_t width, uint32_t height, std::string title)
    {
        uint32_t rInit = glfwInit();
        if(rInit)
        {
            glfwDefaultWindowHints();
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);

            TERRABYTE_ENGINE* engine = (TERRABYTE_ENGINE*) TERRABYTE_MALLOC(sizeof(TERRABYTE_ENGINE));
            GLFWwindow* rWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
            if(rWindow)
            {
                engine->window = rWindow;

                glfwMakeContextCurrent(rWindow);
                uint32_t rGlad = gladLoadGL();
                if(rGlad)
                {
                    return engine;
                } else EngineLog("Unable to load GLAD.");
            }
            else EngineLog("Unable to create GLFW window.");
            TERRABYTE_FREE(engine);
        }
        else EngineLog("Unable to initialise GLFW.");
        glfwTerminate();
        return nullptr;
    }

    void StartEngine(TERRABYTE_ENGINE& engine, void (*update)(double dt), void (*draw)())
    {
        EngineLog("Starting TerrabyteEngine...");
        const double dt = 0.01;

        double startTime = std::chrono::high_resolution_clock::now().time_since_epoch().count() / 1000000000.0;
        double accumulator = 0.0;

        while(!glfwWindowShouldClose(engine.window))
        {
            double endTime = std::chrono::high_resolution_clock::now().time_since_epoch().count() / 1000000000.0;
            double frameTime = (endTime - startTime);
            startTime = endTime;
            accumulator += frameTime;

            while(accumulator >= dt)
            {
                update(dt);

                accumulator -= dt;
            }

            glClear(GL_COLOR_BUFFER_BIT);
            draw();
            glfwSwapBuffers(engine.window);
            glfwPollEvents();
        }
        EngineLog("Engine terminated.");
        glfwTerminate();
        TERRABYTE_FREE(&engine);
    }
}