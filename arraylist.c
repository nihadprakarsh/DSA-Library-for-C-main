#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"
#ifdef ALLOC_TESTING
#include "alloc-testing.h"
#endif
ArrayList *NewAL(unsigned int length)
{
	ArrayList *new_arraylist;
	if (length <= 0) 
	{
		length = 16;
	}
	new_arraylist = (ArrayList *) malloc(sizeof(ArrayList));
	if (new_arraylist == NULL) 
	{
		return NULL;
	}
	new_arraylist->_alloced = length;
	new_arraylist->length = 0;
	new_arraylist->data = malloc(length * sizeof(ArrayListValue));

	if (new_arraylist->data == NULL) {
		free(new_arraylist);
		return NULL;
	}
	return new_arraylist;
}
void _free(ArrayList *arraylist)
{
	if (arraylist != NULL) 
	{
		free(arraylist->data);
		free(arraylist);
	}
}

static int arraylist_enlarge(ArrayList *arraylist)
{
	ArrayListValue *data;
	unsigned int newsize;
	newsize = arraylist->_alloced * 2;
	data = realloc(arraylist->data, sizeof(ArrayListValue) * newsize);

	if (data == NULL)
	{
		return 0;
	} 
	else 
	{
		arraylist->data = data;
		arraylist->_alloced = newsize;
		return 1;
	}
}

int arraylist_insert(ArrayList *arraylist, unsigned int index,
                     ArrayListValue data)
{
	if (index > arraylist->length) 
	{
		return 0;
	}
	if (arraylist->length + 1 > arraylist->_alloced) 
	{
		if (!arraylist_enlarge(arraylist)) 
		{
			return 0;
		}
	}
	memmove(&arraylist->data[index + 1],
	        &arraylist->data[index],
	        (arraylist->length - index) * sizeof(ArrayListValue));
	arraylist->data[index] = data;
	++arraylist->length;
	return 1;
}

int arraylist_append(ArrayList *arraylist, ArrayListValue data)
{
	return arraylist_insert(arraylist, arraylist->length, data);
}

int arraylist_prepend(ArrayList *arraylist, ArrayListValue data)
{
	return arraylist_insert(arraylist, 0, data);
}

void _remove_range(ArrayList *arraylist, unsigned int index,
                            unsigned int length)
{

	if (index > arraylist->length || index + length > arraylist->length) 
	{
		return;
	}
	memmove(&arraylist->data[index],
	        &arraylist->data[index + length],
	        (arraylist->length - (index + length))
	            * sizeof(ArrayListValue));
	arraylist->length -= length;
}

void _remove(ArrayList *arraylist, unsigned int index)
{
	_remove_range(arraylist, index, 1);
}

int index_of(ArrayList *arraylist,
                       ArrayListEqualFunc callback,
                       ArrayListValue data)
{
	unsigned int i;

	for (i=0; i<arraylist->length; ++i) {
		if (callback(arraylist->data[i], data) != 0)
			return (int) i;
	}

	return -1;
}

void arraylist_clear(ArrayList *arraylist)
{
	arraylist->length = 0;
}

