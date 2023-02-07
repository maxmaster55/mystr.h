#include <stdio.h>
#include <mystr.h>

int main()
{
    char str1[15];
    char str2[15];
    int ret;

    ret = memcmp("abc", "abc", 3);

    if (ret > 0)
    {
        printf("str2 is less than str1: %d", ret);
    }
    else if (ret < 0)
    {
        printf("str1 is less than str2: %d", ret);
    }
    else
    {
        printf("str1 is equal to str2");
    }

    return (0);
}