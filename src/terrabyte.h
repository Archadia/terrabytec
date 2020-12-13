#include <stdint.h>
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include "terrabyte_math.h"

// #define TERRABYTE_MEMORY_VERBOSE

#define TERRABYTE_LOG "[TerrabyteEngine]"

/* Memory */

#ifndef TERRABYTE_MEMORY_DEF

void* MemoryAllocate(uint32_t size, const char* file, uint32_t line);
void* MemoryCAllocate(uint32_t count, uint32_t size, const char* file, uint32_t line);
void MemoryFree(void* pointer, const char* file, uint32_t line);

#define TERRABYTE_MALLOC(s) MemoryAllocate(s, __FILE__, __LINE__)
#define TERRABYTE_CALLOC(c, s) MemoryCAllocate(c, s, __FILE__, __LINE__)
#define TERRABYTE_FREE(p) MemoryFree(p, __FILE__, __LINE__)

#define TERRABYTE_MEMORY_DEF
#endif

/* Engine/Display */

#ifndef TERRABYTE_ENGINE_DEF
namespace pkr
{        
    struct TERRABYTE_ENGINE
    {
        GLFWwindow* window;
        uint32_t fps;
    };

    inline void EngineLog(const char* text)
    {
        printf("%s %s\n", TERRABYTE_LOG, text);
    }

    extern void SetEngineVSync(bool b);
    extern void SetWindowTitle(TERRABYTE_ENGINE& engine, const char* title);
    extern VEC2D GetMousePosition(TERRABYTE_ENGINE& engine);
    extern VEC2F GetWindowContentScale(TERRABYTE_ENGINE& engine);
    extern VEC2I GetFrameBufferSize(TERRABYTE_ENGINE& engine);
    extern VEC2I GetWindowSize(TERRABYTE_ENGINE& engine);
    extern float GetWindowAspectRatio(TERRABYTE_ENGINE& engine);
    extern TERRABYTE_ENGINE* CreateEngine(uint32_t width, uint32_t height, const char* title);
    extern void StartEngine(TERRABYTE_ENGINE& engine, void (*update)(double dt), void (*draw)());
}
#define TERRABYTE_ENGINE_DEF
#endif