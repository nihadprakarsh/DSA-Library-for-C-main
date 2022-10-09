#ifndef ALGORITHM_ARRAYLIST_H
#define ALGORITHM_ARRAYLIST_H
#ifdef __cplusplus
extern "C" {
#endif
typedef void *ArrayListValue;
typedef struct _ArrayList ArrayList;
struct _ArrayList 
{
	ArrayListValue *data;
	unsigned int length;
	unsigned int _alloced;
};
typedef int (*ArrayListEqualFunc)(ArrayListValue value1,
                                  ArrayListValue value2);

typedef int (*ArrayListCompareFunc)(ArrayListValue value1,
                                    ArrayListValue value2);
ArrayList *NewAL(unsigned int length);

void _free(ArrayList *arraylist);

int append(ArrayList *arraylist, ArrayListValue data);

int prepend(ArrayList *arraylist, ArrayListValue data);

void _remove(ArrayList *arraylist, unsigned int index);

void _remove_range(ArrayList *arraylist, unsigned int index,
                            unsigned int length);
int arraylist_insert(ArrayList *arraylist, unsigned int index,
                     ArrayListValue data);
int index_of(ArrayList *arraylist,
                       ArrayListEqualFunc callback,
                       ArrayListValue data);
void arraylist_clear(ArrayList *arraylist);

#ifdef __cplusplus
}
#endif

#endif