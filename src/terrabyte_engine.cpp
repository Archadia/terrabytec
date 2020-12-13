// #include <time.h>
#include "terrabyte.h"

namespace pkr
{
    void SetEngineVSync(bool b)
    {
        glfwSwapInterval(b ? 1 : 0);
    }

    void SetWindowTitle(TERRABYTE_ENGINE& engine, const char* title)
    {
        glfwSetWindowTitle(engine.window, title);
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

    TERRABYTE_ENGINE* CreateEngine(uint32_t width, uint32_t height, const char* title)
    {
        uint32_t rInit = glfwInit();
        if(rInit)
        {
            glfwDefaultWindowHints();
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);

            TERRABYTE_ENGINE* engine = (TERRABYTE_ENGINE*) TERRABYTE_MALLOC(sizeof(TERRABYTE_ENGINE));
            GLFWwindow* rWindow = glfwCreateWindow(width, height, title, NULL, NULL);
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

        clock_t start_t = clock();

        double accumulator = 0.0;
        double fpsAccumulator = 0;

        uint32_t fpsCount;
        engine.fps = 0;

        while(!glfwWindowShouldClose(engine.window))
        {
            clock_t end_t = clock();
            double frame_t = (double) (end_t - start_t) / CLOCKS_PER_SEC;
            start_t = end_t;
            accumulator += frame_t;

            while(accumulator >= dt)
            {
                update(dt);
                accumulator -= dt;
            }

            glClear(GL_COLOR_BUFFER_BIT);
            draw();
            glfwSwapBuffers(engine.window);
            glfwPollEvents();

            fpsCount++;
            fpsAccumulator += frame_t;
            if(fpsAccumulator >= 1.0)
            {
                engine.fps = fpsCount;
                fpsCount = 0;
                fpsAccumulator -= 1;
            }
        }
        EngineLog("Engine terminated.");
        glfwTerminate();
        TERRABYTE_FREE(&engine);
    }
}