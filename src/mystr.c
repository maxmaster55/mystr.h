#include "mystr.h"

size_t strlen(const char *str)
{
    size_t len = 0;
    while (*str != '\0') // make sure the null termintor is in ' '
    {
        len++;
        str++;
    }
    return len;
}

void *memchr(const void *str, int c, size_t n)
{
}