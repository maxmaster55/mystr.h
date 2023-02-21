#include "stackpp.h"

#include "stdlib.h"

static int stack_empty(stackpp_t *mystack) {
    return (mystack->size == 0);
}

stack_ret_status stack_init(stackpp_t *mystack) {
    if (mystack == NULL) {
        return STACK_NULL_PTR;
    }

    mystack->stack = (void **)calloc(0, sizeof(void *));
    if (mystack->stack == NULL) {
        return STACK_NULL_PTR;
    }
    mystack->size = 0;
    mystack->top_indx = 0;
    return STACK_OK;
}
stack_ret_status stack_destroy(stackpp_t *mystack) {
    if (mystack->stack == NULL) {
        return STACK_NULL_PTR;
    }

    free(mystack->stack);
    free(mystack);
}
stack_ret_status stack_push(stackpp_t *mystack, void *val) {
    if (mystack->stack == NULL) {
        return STACK_NULL_PTR;
    }
    mystack->size += 1;
    mystack->top_indx = mystack->size - 1;
    mystack->stack = (void **)realloc(mystack->stack, mystack->size);
    mystack->stack[mystack->top_indx] = val;
    return STACK_OK;
}
stack_ret_status stack_pop(stackpp_t *mystack, void *ret_loc);
stack_ret_status stack_top(stackpp_t *mystack);