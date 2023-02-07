#include "mystr.h"
#include <stdio.h>

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
    char *ptr = (char *)str;

    for (size_t i = 0; i < n; i++)
    {
        if (*ptr == c)
        {
            return ptr + i;
        }
    }
}

/**
 * @brief Comapres 2 strings for the first n characters
 *
 * @param str1 1st string
 * @param str2 2nd string
 * @param n number of compare characters
 * @return int
 * @if value < 0 then it indicates str1 is less than str2.
 * @if value > 0 then it indicates str2 is less than str1.
 * @if value = 0 then it indicates str1 is equal to str2.
 *
 */
int memcmp(const void *str1, const void *str2, size_t n)
{
    const unsigned char *p1 = (const unsigned char *)str1;
    const unsigned char *p2 = (const unsigned char *)str2;

    for (size_t i = 0; i < n; i++)
    {
        if (p1[i] < p2[i])
            return -1;
        else if (p1[i] > p2[i])
            return 1;
    }
    return 0;
}

/**
 * @brief copies from src to with the number of bytes n
 *
 * @param dest
 * @param src
 * @param n
 * @return void*
 */
void *memcpy(void *dest, const void *src, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        *(char *)(dest + i) = *(char *)(src + i);
    }
    return dest;
}

void *memmove(void *str1, const void *str2, size_t n)
{
    char *ptr1 = (char *)str1;
    const char *ptr2 = (char *)str2;
    for (size_t i = 0; i < n; i++)
    {
        ptr1[i] = ptr2[i];
    }
}

void *memset(void *str, int c, size_t n)
{
    char *ptr = (char *)str;
    for (size_t i = 0; i < n; i++)
    {
        ptr[i] = c;
    }
}
