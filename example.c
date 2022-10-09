/* this is a demo program using some of the functions of each of the data structures made */

#include <stdio.h>
#include "std_cf.h"

int main()
{
	//declaration and initialization
    ArrayList *arr=NewAL(3);
    Queue *q = queue_new();
    Stack *st = stack_new();
    Heap *z=heap_new(BINARY_HEAP_TYPE_MIN);
    //this example is for min heap
    //type BINARY_HEAP_TYPE_MAX for a max heap
    SListEntry *l;
	l = malloc(sizeof(SListEntry));
	//l->next = NULL;
	l = NULL;
	ListEntry *l1;
	l1 = malloc(sizeof(ListEntry));
	//l->next = NULL;
	l1 = NULL;

    //Variable declaration
	int *a,*b,*c,*d,*e,*f,*g;
	a = (int*)5;
	b = (int*)6;
	c = (int*)7;
	d = (int*)1;
	e = (int*)0;
	f = (int*)2;
	g = (int*)15;

    /*  Demonstration of data structures  */
    printf("Demonstrations:\n");

	//ArrayList
    printf("\n\tarray list:\n\n");
	arraylist_append(arr,a);//5
	arraylist_append(arr,b);//5 6
	arraylist_append(arr,c);//5 6 7
	arraylist_append(arr,d);//5 6 7 1
	arraylist_append(arr,e);//5 6 7 1 0
	arraylist_prepend(arr,f);//2 5 6 7 1 0
	arraylist_prepend(arr,g);//15 2 5 6 7 1 0
	for(int i=0;i<arr->length;i++)
	{
		printf("%d ",arr->data[i]);
	}
	printf("\nnew size is ");
	printf("%d\n",arr->_alloced);// size is enlarged two times to 12

	_remove(arr,3);//15 2 5 7 1 0
	_remove(arr,4);//15 2 5 7 0
	_remove(arr,1);//15 5 7 0
	printf("elements after removing:\n");
	for(int i=0;i<arr->length;i++)
	{
		printf("%d ",arr->data[i]);
	}
	printf("\n");

	// Singly linked list
	printf("\n\tsingly linked list:\n\n");
	slist_prepend(&l,a);
	slist_prepend(&l,b);
	slist_append(&l,c);
	//printf("%d",slist_append(&l,c)->data);

	int len = slist_length(l);
	int *ar = (int *)slist_to_array(l);
	for(int i=0;i<len;++i)
	{
		printf("%d ",slist_data(l));
		l=slist_next(l);
	}
	printf("\n");

	// Doubly linked list
	printf("\n\tdoubly linked list:\n\n");
	list_prepend(&l1,a);
	list_prepend(&l1,b);
	list_append(&l1,c);
	//printf("%d",list_append(&l,c)->data);

	int len1 = list_length(l1);
	int *arr1 = (int *)list_to_array(l1);
	for(int j=0;j<len1;++j)
	{
		printf("%d ",list_data(l1));
		l1=list_next(l1);
	}
	printf("\n");

	// queue
	printf("\n\tqueue:\n\n");
	queue_push_head(q,a);
	queue_push_head(q,b);
	printf("Poped element:\t");
	printf("%d\n",queue_pop_tail(q));
	queue_push_tail(q,c);
	printf("Peeked element:\t");
	printf("%d\n",queue_peek_tail(q));
	printf("Remaining queue:\n");
	QueueEntry *cur = q->head;
	while (cur!=NULL)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");

	// stack
	printf("\n\tstack:\n\n");
	stack_push(st,a);
	stack_push(st,b);
	printf("Poped element:\t");
	printf("%d\n",stack_pop(st));
	stack_push(st,c);
	printf("Peeked element:\t");
	printf("%d\n",stack_peek(st));
	printf("Remaining stack:\n");
	StackEntry *cur2 = st->top;
	while (cur2!=NULL)
	{
		printf("%d ",cur2->data);
		cur2 = cur2->below;
	}
	printf("\n");

	// heap
	printf("\n\theap:\n\n");
    insert(z,a);
	insert(z,b);
	insert(z,c);
	insert(z,d);
	insert(z,e);
	insert(z,f);
	insert(z,g);
	for(int i=0;i<z->num_values;i++)
	{
		printf("%d ",z->values[i]);
	}

	Heap_remove(z);
	printf("\n");
	printf("After removal:\n");
	for(int i=0;i<z->num_values;i++)
	{
		printf("%d ",z->values[i]);
	}
	printf("\n");
	return 0;
}
