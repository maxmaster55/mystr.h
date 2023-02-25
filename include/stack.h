#ifndef _STACk_H_
#define _STACK_H_

#include "std_types.h"

#define STACK_MAX_SIZE 5
#define STACK_DEBUG

typedef struct
{
    uint32_t stack_pointer;
    uint32_t data[STACK_MAX_SIZE];
} stack_t;

typedef enum {
    STACK_FULL,
    STACK_EMPTY,
    STACK_NOT_FULL,
} stack_status_t;

// control function
ret_status_t stack_init(stack_t *my_stack);
ret_status_t stack_push(stack_t *my_stack, uint32_t value);
ret_status_t stack_pop(stack_t *my_stack, uint32_t *ret_loc);
ret_status_t stack_top(stack_t *my_stack, uint32_t *ret_loc);
ret_status_t stack_size(stack_t *my_stack, uint32_t *size_loc);
ret_status_t stack_display(stack_t *my_stack);

#endif