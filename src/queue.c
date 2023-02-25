#include "queue.h"

#include "stdlib.h"
#define DEBUG

static void debug_Print(char *str) {
#ifdef DEBUG
    printf("%s\n", str);
#endif
}

queue_t *queue_create(uint32_t num_elem) {
    if (num_elem < 1) {
        debug_Print("[!] Error: the number of elements cant be less than 1.");
        return NULL;
    }

    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    queue->queue_ptr = (void **)calloc(num_elem, sizeof(void *));

    if ((queue == NULL) || (queue->queue_ptr == NULL)) {
        debug_Print("[!] Error: something happend with malloc.");
        return NULL;
    }
    queue->max_size = num_elem;
    queue->front_index = -1;
    queue->rear_index = -1;
    queue->size = 0;
    debug_Print("[] queue created succesfully. \n ");
    return queue;
}

queue_status_t queue_distroy(queue_t *queue) {
    if (!queue || !(queue->queue_ptr)) {
#ifdef DEBUG
        printf("[!] Could not distroy the queue. \n");
#endif
        return R_NOK;
    }

    free(queue->queue_ptr);
    free(queue);
    return R_NOK;
}

queue_status_t queue_enqueue(queue_t *queue, void *item) {
    if (!queue) {
        debug_Print("[!] Error can't enque in null queue. ");
        return R_NOK;
    }
    if (queue->size == queue->max_size) {
        debug_Print("[!] Error queue is full.");
        return R_NOK;
    }

    queue->rear_index += 1;
    if (queue->size == queue->max_size) {
        queue->rear_index = 0;
    }
    (queue->queue_ptr)[queue->rear_index] = item;
    if (queue->size == 0) {
        queue->front_index = 0;
        queue->size = 1;
    } else {
        queue->size += 1;
    }

    return R_OK;
}

void *queue_dequeue(queue_t *queue, queue_status_t *status);
void *queue_rear(queue_t *queue, queue_status_t *status);
void *queue_front(queue_t *queue, queue_status_t *status);
uint32_t queue_get_count(queue_t *queue);