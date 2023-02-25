#include "queue.h"

#include "stdlib.h"
#define DEBUG

queue_t *queue_create(uint32_t num_elem) {
    if (num_elem < 1) {
#ifdef DEBUG
        printf("[!] Error: the number of elements cant be less than 1. \n");
#endif
        return NULL;
    }

    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    queue->queue_ptr = (void **)calloc(num_elem, sizeof(void *));

    if ((queue == NULL) || (queue->queue_ptr == NULL)) {
#ifdef DEBUG
        printf("[!] Error: something happend with malloc. \n");
#endif
        return NULL;
    }
    queue->max_size = num_elem;
    queue->front_index = -1;
    queue->rear_index = -1;
    queue->size = 0;
#ifdef DEBUG

    printf("[] queue created succesfully. \n ");
#endif
    return queue;
}
queue_status_t queue_distroy(queue_t *queue);
queue_status_t queue_enqueue(queue_t *queue, void *item);
void *queue_dequeue(queue_t *queue, queue_status_t *status);
void *queue_rear(queue_t *queue, queue_status_t *status);
void *queue_front(queue_t *queue, queue_status_t *status);
uint32_t queue_get_count(queue_t *queue);