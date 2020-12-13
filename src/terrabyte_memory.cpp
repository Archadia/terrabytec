#include <stdio.h>
#include "terrabyte.h"

void* MemoryAllocate(uint32_t size, const char* file, uint32_t line)
{
    printf("TERRABYTE_MALLOC(%u): %s, line-%u\n", size, file, line);
    return malloc(size);
}

void* MemoryCAllocate(uint32_t count, uint32_t size, const char* file, uint32_t line)
{
    printf("TERRABYTE_CALLOC(%u): %s, line-%u\n", size, file, line);
    return calloc(count, size);
}

void MemoryFree(void* pointer, const char* file, uint32_t line)
{
    printf("TERRABYTE_FREE(%p): %s, line-%u\n", pointer, file, line);
    free(pointer);
}

