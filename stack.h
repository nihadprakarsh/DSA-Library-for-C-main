#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Stack */

// Structure storing info of stack
typedef struct _Stack Stack;

// Referring to the data type stored in the stack
typedef void *StackValue;

// NULL value corresponding to the stored data type
#define STACK_NULL ((void *) 0)

/**
 * Creates a new stack.

 * returns the pointer to a new stack, or NULL if allocating memory was not possible
 */
Stack *stack_new(void);

/**
 * Destroys a stack.

 * stack is the pointer to the stack to be destroyed.
 */
void stack_free(Stack *stack);

/**
 * Adds a value to the top of a stack.
 
 * stack is the pointer to the stack to be updated.
 * data is the value to add to the stack.
 * returns 1 if the push was successful, otherwise returns 0.
 */
int stack_push(Stack *stack, StackValue data);

/**
 * Removes a value from the top of a stack.
 
 * stack is the pointer to the stack to be updated.
 * returns the value that was at the top of the stack (after removal), or STACK_NULL if the stack is empty.
 */
StackValue stack_pop(Stack *stack);

/**
 * Reads value from the top of a stack, without removal

 * stack is the pointer to the given stack.
 * returns the value that was at the top of the stack, or STACK_NULL if the stack is empty.
 */
StackValue stack_peek(Stack *stack);

/**
 * Gives the number of elements contained in the stack

 * stack is the pointer to the given stack.
 * returns the size of the stack or -1 if the stack has not been created or has been destroyed
 */
int stack_size(Stack *stack);

/**
 * Checks if any values are currently in the stack.

 * stack is the pointer to the given stack.
 * returns 1 if the stack is empty, otherwise returns 0
 */
int stack_is_empty(Stack *stack);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef ALGORITHM_STACK_H */