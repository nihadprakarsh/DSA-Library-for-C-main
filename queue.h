#ifndef QUEUE_H
#define QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

/* A double-ended queue */

// Structure storing info of queue
typedef struct _Queue Queue;

// Referring to the data type stored in the queue
typedef void *QueueValue;

// NULL value corresponding to the stored data type
#define QUEUE_NULL ((void *) 0)

/**
 * Creates a new double-ended queue.

 * returns a new queue, or NULL if allocating memory was not possible
 */
Queue *queue_new(void);

/**
 * Destroys a queue.

 * queue is the pointer to the queue to be destroyed.
 */
void queue_free(Queue *queue);

/**
 * Adds a value to the head of a queue.
 
 * queue is the pointer to the queue to be updated.
 * data is the value to add to the queue.
 * returns 1 if the push was successful, otherwise returns 0.
 */
int queue_push_head(Queue *queue, QueueValue data);

/**
 * Removes a value from the head of a queue.
 
 * queue is the pointer to the queue to be updated.
 * returns the value that was at the head of the queue (after removal), or QUEUE_NULL if the queue is empty.
 */
QueueValue queue_pop_head(Queue *queue);

/**
 * Reads value from the head of a queue, without removal

 * queue is the pointer to the given queue.
 * returns the value that was at the head of the queue, or QUEUE_NULL if the queue is empty.
 */
QueueValue queue_peek_head(Queue *queue);

/**
 * Adds a value to the tail of a queue.

 * queue is the pointer to the queue to be updated.
 * data is the value to add to the queue.
 * returns 1 if the push was successful, otherwise returns 0.
 */
int queue_push_tail(Queue *queue, QueueValue data);

/**
 * Removes a value from the tail of a queue.

 * queue is the pointer to the queue to be updated.
 * returns the value that was at the tail of the queue (after removal), or QUEUE_NULL if the queue is empty.
 */
QueueValue queue_pop_tail(Queue *queue);

/**
 * Reads value from the tail of a queue, without removal

 * queue is the pointer to the given queue.
 * returns the value that was at the tail of the queue, or QUEUE_NULL if the queue is empty.
 */
QueueValue queue_peek_tail(Queue *queue);

/**
 * Checks if any values are currently in the queue.

 * queue is the pointer to the given queue.
 * returns 1 if the queue is empty, otherwise returns 0
 */
int queue_is_empty(Queue *queue);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef ALGORITHM_QUEUE_H */