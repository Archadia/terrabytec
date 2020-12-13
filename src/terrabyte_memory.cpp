#include <stdlib.h>
#include "terrabyte.h"

void* MemoryAllocate(uint32_t size, const char* file, uint32_t line)
{
    #ifdef TERRABYTE_MEMORY_VERBOSE
    printf("TERRABYTE_MALLOC(%u): %s, line-%u\n", size, file, line);
    #endif
    return malloc(size);
}

void* MemoryCAllocate(uint32_t count, uint32_t size, const char* file, uint32_t line)
{
    #ifdef TERRABYTE_MEMORY_VERBOSE
    printf("TERRABYTE_CALLOC(%u): %s, line-%u\n", size, file, line);
    #endif
    return calloc(count, size);
}

void MemoryFree(void* pointer, const char* file, uint32_t line)
{
    #ifdef TERRABYTE_MEMORY_VERBOSE
    printf("TERRABYTE_FREE(%p): %s, line-%u\n", pointer, file, line);
    #endif
    free(pointer);
}

