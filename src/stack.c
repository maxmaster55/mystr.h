#include <stdio.h>
#include "stack.h"

/**
 * @brief check if the stack is full
 *
 * @param my_stack
 * @return stack_status_t
 */
static stack_status_t stack_full(stack_t *my_stack)
{
    if (my_stack->stack_pointer == STACK_MAX_SIZE - 1)
    {
        return STACK_FULL;
    }
    else
    {
        return STACK_NOT_FULL;
    }
}

/**
 * @brief check if the stack is empty
 *
 * @param my_stack
 * @return stack_status_t
 */
static stack_status_t stack_empty(stack_t *my_stack)
{
    if (my_stack->stack_pointer == -1)
    {
        return STACK_EMPTY;
    }
    else
    {
        return STACK_NOT_FULL;
    }
}

/**
 * @brief initialize the stack pointer
 *
 * @param my_stack  Pointer to the stack
 * @return ret_status_t s
 */
ret_status_t stack_init(stack_t *my_stack)
{
    if (my_stack == NULL)
        return R_NOK;

    my_stack->stack_pointer = -1;

    return R_OK;
}

ret_status_t stack_push(stack_t *my_stack, uint32_t value)
{
    if ((my_stack == NULL) || (stack_full(my_stack) == STACK_FULL))
    {

#ifdef STACK_DEBUG
        printf("Error with stack_push\n");
#endif
        return R_NOK;
    }
    my_stack->stack_pointer += 1;
    my_stack->data[my_stack->stack_pointer] = value;

#ifdef STACK_DEBUG
    printf("added %d to the stack\n", my_stack->data[my_stack->stack_pointer]);
#endif
    return R_OK;
}

ret_status_t stack_pop(stack_t *my_stack, uint32_t *ret_loc)
{
    if ((my_stack == NULL) ||
        (stack_empty(my_stack) == STACK_EMPTY) ||
        (ret_loc == NULL))
    {

#ifdef STACK_DEBUG
        printf("Error with stack_pop\n");
#endif
        return R_NOK;
    }

    *ret_loc = (my_stack->data[my_stack->stack_pointer]);
    my_stack->stack_pointer -= 1;

#ifdef STACK_DEBUG
    printf("poped value from stack\n");
#endif
    return R_OK;
}

ret_status_t stack_top(stack_t *my_stack, uint32_t *ret_loc)
{

    if ((my_stack == NULL) ||
        (stack_empty(my_stack) == STACK_EMPTY) ||
        (ret_loc == NULL))
    {
#ifdef STACK_DEBUG
        printf("Error with stack_top\n");
#endif
        return R_NOK;
    }
    *ret_loc = my_stack->data[my_stack->stack_pointer];
    return R_OK;
}

ret_status_t stack_size(stack_t *my_stack, uint32_t *size_loc)
{

    if ((my_stack == NULL) || (size_loc == NULL))
    {
#ifdef STACK_DEBUG
        printf("Error with stack_size\n");
#endif
        return R_NOK;
    }
    *size_loc = my_stack->stack_pointer + 1;
}

ret_status_t stack_display(stack_t *my_stack)
{

    if (my_stack == NULL)
    {
#ifdef STACK_DEBUG
        printf("Error with stack_display\n");
#endif
        return R_NOK;
    }

    for (size_t i = 0; i <= my_stack->stack_pointer; i++)
    {
        printf("%d\t", my_stack->data[i]);
    }
    printf("\n");
}