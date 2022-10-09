#include <stdlib.h>
#include "stack.h"

#ifdef ALLOC_TESTING
#include "alloc-testing.h"
#endif

/* Stack */

typedef struct _StackEntry StackEntry;

struct _StackEntry
{
	StackValue data;
	StackEntry *below;
};

struct _Stack
{
	StackEntry *top;
	int size;
};

Stack *stack_new(void)
{
	Stack *stack;
	stack = (Stack *) malloc(sizeof(Stack));

	// To check if malloc was successful
	if (stack == NULL)
		return NULL;

	stack->top = NULL;
	stack->size = 0;

	return stack;
}

void stack_free(Stack *stack)
{
	// Empty each element of the stack
	while (!stack_is_empty(stack))
		stack_pop(stack);

	// Free back the stack
	free(stack);
}

// returns 1 if the push was successful, otherwise returns 0
int stack_push(Stack *stack, StackValue data)
{
	StackEntry *new_entry;

	// Create the new entry and fill in the fields in the structure
	new_entry = malloc(sizeof(StackEntry));

	// Checks if the malloc was successful
	if (new_entry == NULL)
		return 0;

	new_entry->data = data;
	new_entry->below = stack->top;

	// Insert into the stack
	stack->top = new_entry;
	stack->size++;

	return 1;
}

StackValue stack_pop(Stack *stack)
{
	StackEntry *entry;
	StackValue result;

	// Check the stack is not empty
	if (stack_is_empty(stack))
		return STACK_NULL;

	// Unlink the first entry from the top of the stack
	entry = stack->top;
	stack->top = entry->below;
	result = entry->data;
	stack->size--;

	// Free back the stack entry structure
	free(entry);

	return result;
}

StackValue stack_peek(Stack *stack)
{
	if (stack_is_empty(stack))
		return STACK_NULL;
	else
		return stack->top->data;
}

int stack_size(Stack *stack)
{
	if (stack_is_empty(stack))
		return -1;
	return stack->size;
}

int stack_is_empty(Stack *stack)
{
	return (stack->top == NULL);
}