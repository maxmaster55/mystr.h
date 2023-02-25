#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "std_types.h"
#include "stdio.h"
typedef struct
{
    void **queue_ptr;
    uint32_t max_size;
    uint32_t size;
    sint32_t rear_index;
    sint32_t front_index;
} queue_t;

typedef enum {
    R_OK,
    R_NOK,
    QUEUE_EMPTY,
    QUEUE_FULL,
} queue_status_t;

queue_t *queue_create(uint32_t num_elem);
queue_status_t queue_distroy(queue_t *queue);
queue_status_t queue_enqueue(queue_t *queue, void *item);
void *queue_dequeue(queue_t *queue, queue_status_t *status);
void *queue_front(queue_t *queue, queue_status_t *status);
void *queue_rear(queue_t *queue, queue_status_t *status);
uint32_t queue_get_count(queue_t *queue);

#endif