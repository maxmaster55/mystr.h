#include <stdio.h>
#include <mystr.h>

int main()
{
    char src[50] = "This is source";
    char dest[50] = "This is destination";

    strcat(dest, src);

    printf("Final destination string : |%s|", dest);
    return (0);
}