# DSA-Library-for-C
Data Structure and Standard Algorithms Library for  the C programming Language.
How to use the Standard Collection Framework in your program:

Download all the files in the “Code” folder and keep them in the same folder as the program you are going to use them in. Use #include “std_cf.h” at the head of the C program.

Disclaimer: This is not a standard input output program, it is a library which helps in using some common data structures easily and effectively (like stl in C++ and Collection Framework in Java).

A demonstration program of this library in use is this.

Now, you can use the given data structures like this-

ArrayList:

ArrayList *arr = NewAL(initial length);
//declaring and initializing the list
int append(ArrayList *arraylist, ArrayListValue data);
// add at the back of list
int prepend(ArrayList *arraylist, ArrayListValue data);
//add at front of list
void _remove(ArrayList *arraylist, unsigned int index);
// remove from the list at a particular index
void _remove_range(ArrayList *arraylist, unsigned int index,
                            unsigned int length);
//remove a range of values
int index_of(ArrayList *arraylist, ArrayList Equals Func callback, ArrayListValue data);
//find the index of data
void _free(ArrayList *arraylist);
//free the memory of arraylist
void arraylist_clear(ArrayList *arraylist);
//clear the arraylist

Double-ended Queue:

//declaration and initialization
Queue *q = queue_new();

//functions for operations at head
int queue_push_head(Queue *queue, QueueValue data);
QueueValue queue_pop_head(Queue *queue);
QueueValue queue_peek_head(Queue *queue);

//functions for operations at tail
int queue_push_tail(Queue *queue, QueueValue data);
QueueValue queue_pop_tail(Queue *queue);
QueueValue queue_peek_tail(Queue *queue);

//miscellaneous functions
void queue_free(Queue *queue);
int queue_is_empty(Queue *queue);

Stack:

//declaration and initialization
Stack *st = stack_new();

//basic functions
int stack_push(Stack *stack, StackValue data);
StackValue stack_pop(Stack *stack);
StackValue stack_peek(Stack *stack);

//miscellaneous functions
void stack_free(Stack *stack);
int stack_size(Stack *stack);
int stack_is_empty(Stack *stack);

Heap:

Heap *hp = heap_new(Heap_type,comapre_func);
//declaring and initializing the list
void _free(Heap *heap);
//removing the heap from memory
int insert(Heap *heap, datatype value);
//inserting the new element in heap
datatype _remove(Heap *heap);
//removing the element from heap
unsigned int num_entries(Heap *heap);
//total number of values in heap
Singly Linked List:

SListEntry *l;
l = malloc(sizeof(SListEntry));
l = NULL;
//declaring and initializing the list
SListEntry *slist_prepend(SListEntry **list, SListValue data);
//prepend Elements to the beginning of the list
SListEntry *slist_append(SListEntry **list, SListValue data);
Append elements to the end of the list
unsigned int slist_length(SListEntry *list);
//compute length(number of elements) of the list
SListValue *slist_to_array(SListEntry *list);
//convert the list to an array
SListEntry *slist_nth_entry(SListEntry *list, unsigned int n);
//find nth element of the list
int slist_remove_entry(SListEntry **list, SListEntry *entry);
//remove particular entry(element) from the list

Doubly Linked List:

ListEntry *l;
l = malloc(sizeof(ListEntry));
l = NULL;
//declaring and initializing the list
ListEntry *list_prepend(ListEntry **list, ListValue data);
//prepend Elements to the beginning of the list
ListEntry *list_append(ListEntry **list, ListValue data);
Append elements to the end of the list
unsigned int list_length(ListEntry *list);
//compute length(number of elements) of the list
ListValue *list_to_array(ListEntry *list);
//convert the list to an array
ListEntry *list_nth_entry(ListEntry *list, unsigned int n);
//find nth element of the list
int list_remove_entry(ListEntry **list, ListEntry *entry);
//remove particular entry(element) from the list
