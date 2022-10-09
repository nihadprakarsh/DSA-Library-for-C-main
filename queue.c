#include <stdlib.h>
#include "queue.h"

#ifdef ALLOC_TESTING
#include "alloc-testing.h"
#endif

/* A double-ended queue */

typedef struct _QueueEntry QueueEntry;

struct _QueueEntry
{
	QueueValue data;
	QueueEntry *prev;
	QueueEntry *next;
};

struct _Queue
{
	QueueEntry *head;
	QueueEntry *tail;
};

Queue *queue_new(void)
{
	Queue *queue;
	queue = (Queue *) malloc(sizeof(Queue));

	// To check if malloc was successful
	if (queue == NULL)
		return NULL;

	queue->head = NULL;
	queue->tail = NULL;

	return queue;
}

void queue_free(Queue *queue)
{
	// Empty each element of the queue
	while (!queue_is_empty(queue))
		queue_pop_head(queue);

	// Free back the queue
	free(queue);
}

// returns 1 if the push was successful, otherwise returns 0
int queue_push_head(Queue *queue, QueueValue data)
{
	QueueEntry *new_entry;

	// Create the new entry and fill in the fields in the structure
	new_entry = malloc(sizeof(QueueEntry));

	// Checks if the malloc was successful
	if (new_entry == NULL)
		return 0;

	new_entry->data = data;
	new_entry->prev = NULL;
	new_entry->next = queue->head;

	// Insert into the queue
	if (queue->head == NULL) 
	{
		// If the queue was previously empty
		queue->head = new_entry;
		queue->tail = new_entry;
	} 
	else 
	{
		// Previous head's prev should point to the new element
		queue->head->prev = new_entry;

		// The head should point at the new entry
		queue->head = new_entry;
	}

	return 1;
}

QueueValue queue_pop_head(Queue *queue)
{
	QueueEntry *entry;
	QueueValue result;

	// Check the queue is not empty
	if (queue_is_empty(queue))
		return QUEUE_NULL;

	// Unlink the first entry from the head of the queue
	entry = queue->head;
	queue->head = entry->next;
	result = entry->data;

	// If the updated queue is empty
	if (queue->head == NULL)
		queue->tail = NULL;
	else 
		queue->head->prev = NULL;

	// Free back the queue entry structure
	free(entry);

	return result;
}

QueueValue queue_peek_head(Queue *queue)
{
	if (queue_is_empty(queue))
		return QUEUE_NULL;
	else
		return queue->head->data;
}

// returns 1 if the push was successful, otherwise returns 0
int queue_push_tail(Queue *queue, QueueValue data)
{
	QueueEntry *new_entry;

	// Create the new entry and fill in the fields in the structure
	new_entry = malloc(sizeof(QueueEntry));

	// Checks if the malloc was successful
	if (new_entry == NULL)
		return 0;

	new_entry->data = data;
	new_entry->prev = queue->tail;
	new_entry->next = NULL;

	// Insert into the queue tail
	if (queue->tail == NULL) 
	{
		// If the queue was previously empty
		queue->head = new_entry;
		queue->tail = new_entry;
	} 
	else 
	{
		queue->tail->next = new_entry;
		queue->tail = new_entry;
	}

	return 1;
}

QueueValue queue_pop_tail(Queue *queue)
{
	QueueEntry *entry;
	QueueValue result;

	// Check the queue is not empty
	if (queue_is_empty(queue))
		return QUEUE_NULL;

	// Unlink the first entry from the tail of the queue
	entry = queue->tail;
	queue->tail = entry->prev;
	result = entry->data;

	// If the updated queue is empty
	if (queue->tail == NULL)
		queue->head = NULL;
	else
		queue->tail->next = NULL;

	// Free back the queue entry structure
	free(entry);

	return result;
}

QueueValue queue_peek_tail(Queue *queue)
{
	if (queue_is_empty(queue))
		return QUEUE_NULL;
	else
		return queue->tail->data;
}

int queue_is_empty(Queue *queue)
{
	return (queue->head == NULL);
}