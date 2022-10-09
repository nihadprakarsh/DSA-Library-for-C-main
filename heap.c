#include<stdio.h>
#include <stdlib.h>
#include "heap.h"
#ifdef ALLOC_TESTING
#include "alloc-testing.h"
#endif

struct _Heap 
{
	BinaryHeapType heap_type;
	datatype *values;
	unsigned int num_values;
	unsigned int alloced_size;
};

static int binary_heap_cmp(Heap *heap, datatype data1,
                           datatype data2)
{
	if (heap->heap_type == BINARY_HEAP_TYPE_MIN) 
	{
		if(data1<data2)
			return -1;
		else
			return 1;
	} 
	else 
	{
		if(data1>data2)
			return -1;
		else
			return 1;	
	}
}

Heap *heap_new(BinaryHeapType heap_type)
{
	Heap *heap;

	heap = malloc(sizeof(Heap));

	if (heap == NULL) 
	{
		return NULL;
	}

	heap->heap_type = heap_type;
	heap->num_values = 0;
	//heap->compare_func = compare_func;

	heap->alloced_size = 16;
	heap->values = malloc(sizeof(datatype) * heap->alloced_size);

	if (heap->values == NULL) 
	{
		free(heap);
		return NULL;
	}

	return heap;
}

void Heap_free(Heap *heap)
{
	free(heap->values);
	free(heap);
}

int insert(Heap *heap, datatype value)
{
	datatype *new_values;
	unsigned int index;
	unsigned int new_size;
	unsigned int parent;

	if (heap->num_values >= heap->alloced_size) 
	{

		new_size = heap->alloced_size * 2;
		new_values = realloc(heap->values,
		                     sizeof(datatype) * new_size);

		if (new_values == NULL) 
		{
			return 0;
		}

		heap->alloced_size = new_size;
		heap->values = new_values;
	}

	index = heap->num_values;
	++heap->num_values;
 
    //update up function as mentioned in pseudo code 
	while (index > 0)
	{
		parent = (index - 1) / 2;

		if (binary_heap_cmp(heap, heap->values[parent], value) < 0) 
		{
			break;
		} 
		else 
		{
			heap->values[index] = heap->values[parent];
			index = parent;
		}
	}

	heap->values[index] = value;
	return 1;
}

datatype Heap_remove(Heap *heap)
{
	datatype result;
	datatype new_value;
	unsigned int index;
	unsigned int next_index;
	unsigned int child1, child2;
	if (heap->num_values == 0) 
	{
		return BINARY_HEAP_NULL;
	}
	result = heap->values[0];
	new_value = heap->values[heap->num_values - 1];
	--heap->num_values;
	index = 0;

	// heapify function as mentioned in pseudo code
	for (;;) 
	{

		child1 = index * 2 + 1;
		child2 = index * 2 + 2;
		if (child1 < heap->num_values
		 && binary_heap_cmp(heap,
		                    new_value,
		                    heap->values[child1]) > 0) 
		{

			if (child2 < heap->num_values
			 && binary_heap_cmp(heap,
			                    heap->values[child1],
			                    heap->values[child2]) > 0) 
			{
				next_index = child2;
			} 
			else 
			{
				next_index = child1;
			}

		}
		else if (child2 < heap->num_values
		        && binary_heap_cmp(heap,
		                           new_value,
		                           heap->values[child2]) > 0) 
		{

			next_index = child2;

		} 
		else 
		{
			heap->values[index] = new_value;
			break;
		}
		heap->values[index] = heap->values[next_index];
		index = next_index;
	}
	return result;
}

unsigned int num_entries(Heap *heap)
{
	return heap->num_values;
}
