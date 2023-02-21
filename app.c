#include <stdio.h>
#include <stdlib.h>

#include "stackpp.h"

stackpp_t stack1;

int main() {
    stack_init(&stack1);
    char x[] = "help";
    stack_push(&stack1, &x);
    printf("size = %d\n", stack1.size);
    printf("top is: %s\n", stack1.stack[stack1.top_indx]);

    char y[] = "help22";
    stack_push(&stack1, &y);
    printf("size = %d\n", stack1.size);
    printf("top is: %s\n", stack1.stack[stack1.top_indx]);
}