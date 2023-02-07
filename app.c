#include <stdio.h>
#include <mystr.h>

int main()
{
    char str[50] = "This is string.h library function";
    puts(str);

    memset(str + 5, '$', 7);
    puts(str);

    return (0);
}