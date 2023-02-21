#include <stdio.h>
#include "std_types.h"

#ifndef _STACKPP_H_
#define _STACKPP_H_

typedef struct
{
    void **stack;
    uint32_t size;
    uint32_t top_indx;
} stackpp_t;

typedef enum
{
    STACK_OK,
    STACK_NOK,
    STACK_EMPTY,
    STACK_FULL,
    STACK_NULL_PTR

} stack_ret_status;

stack_ret_status stack_init(stackpp_t *mystack);
stack_ret_status stack_destroy(stackpp_t *mystack);
stack_ret_status stack_push(stackpp_t *mystack, void *val);
stack_ret_status stack_pop(stackpp_t *mystack, void *ret_loc);
stack_ret_status stack_top(stackpp_t *mystack);

#endif