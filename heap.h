#ifndef ALGORITHM_BINARY_HEAP_H
#define ALGORITHM_BINARY_HEAP_H
#ifdef __cplusplus
extern "C" 
{
	#endif

	typedef enum 
	{
		/** A minimum heap. */

		BINARY_HEAP_TYPE_MIN,

		/** A maximum heap. */

		BINARY_HEAP_TYPE_MAX
	} BinaryHeapType;

	typedef void *datatype;

	#define BINARY_HEAP_NULL ((void *) 0)




	typedef struct _Heap Heap;

	Heap *heap_new(BinaryHeapType heap_type);

	void Heap_free(Heap *heap);

	int insert(Heap *heap, datatype value);

	datatype Heap_remove(Heap *heap);

	unsigned int num_entries(Heap *heap);

	#ifdef __cplusplus
}
#endif

#endif /* #ifndef ALGORITHM_BINARY_HEAP_H */
