#ifndef ALGORITHM_SLIST_H
#define ALGORITHM_SLIST_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Represents an entry in a singly-linked list.  The empty list is
 * represented by a NULL pointer. To initialise a new singly linked
 * list, simply create a variable of this type
 * containing a pointer to NULL.
 */

typedef struct _SListEntry SListEntry;

/**
 * Structure used to iterate over a list.
 */

typedef struct _SListIterator SListIterator;

/**
 * Value stored in a list.
 */

typedef void *SListValue;

/**
 * Definition of a SListIterator.
 */

struct _SListIterator {
	SListEntry **prev_next;
	SListEntry *current;
};

/**
 * A null SListValue.
 */

#define SLIST_NULL ((void *) 0)

/**
 * Callback function used to compare values in a list when sorting..
 */

typedef int (*SListCompareFunc)(SListValue value1, SListValue value2);

/**
 * Callback function used to determine of two values in a list are
 * equal.
 */

typedef int (*SListEqualFunc)(SListValue value1, SListValue value2);

/**
 * Free an entire list.
 *
 * list is the pointer to the list to free.
 */

void slist_free(SListEntry *list);

/**
 * Prepend a value to the start of a list.
 *
 * list is pointer to the list to prepend to.
 * Data is the value to prepend.
 * The new entry in the list, or NULL if it was not possible to allocate a new entry.
 */

SListEntry *slist_prepend(SListEntry **list, SListValue data);

/**
 * Append a value to the end of a list.
 *
 * list is pointer to the list to append to.
 * data is the value to append.
 * The new entry in the list, or NULL if it was not possible to allocate a new entry.
 */

SListEntry *slist_append(SListEntry **list, SListValue data);

/**
 * Retrieve the next entry in a list.
 *
 * listentry is Pointer to the list entry.
 * The next entry in the list is returned.
 */

SListEntry *slist_next(SListEntry *listentry);

/**
 * Retrieve the value stored at a list entry.
 *
 * listentry is Pointer to the list entry.
 * The value at the list entry is returned.
 */

SListValue slist_data(SListEntry *listentry);

/**
 * Set the value at a list entry. The value provided will be written to the 
 * given listentry. If listentry is NULL nothing is done.
 *
 * listentry is Pointer to the list entry.
 * value is the value to set.
 */
void slist_set_data(SListEntry *listentry, SListValue value);

/**
 * Retrieve the entry at a specified index in a list.
 *
 * list is the list used.
 * n is the index into the list .
 * The entry at the specified index, or NULL if out of range is returned.
 */

SListEntry *slist_nth_entry(SListEntry *list, unsigned int n);

/**
 * Retrieve the value stored at a specified index in the list.
 *
 * list is the list used.
 * n is the index into the list.
 * The value stored at the specified index, or SLIST_NULL if unsuccessful is returned.
 */

SListValue slist_nth_data(SListEntry *list, unsigned int n);

/**
 * Find the length of a list.
 *
 * list is the list used.
 * The number of entries in the list is returned.
 */

unsigned int slist_length(SListEntry *list);

/**
 * Create a C array containing the contents of a list.
 *
 * list is the list used.
 * A newly-allocated C array containing all values in the list, or NULL if it was not possible to allocate the memory for the array is returned.  The length of the array is equal to the length of the list (see slist_length).
 */

SListValue *slist_to_array(SListEntry *list);

/**
 * Remove an entry from a list.
 *
 * list is the list used.
 * entry is the list entry to remove.
 * If the entry is not found in the list, returns zero, else returns non-zero.
 */

int slist_remove_entry(SListEntry **list, SListEntry *entry);

/**
 * Remove all occurrences of a particular value from a list.
 *
 * list is pointer to the list.
 * callback is the Callback function to invoke to compare values in the list with the value to remove.
 * data is the value to remove from the list.
 * The number of entries removed from the list is returned.
 */

unsigned int slist_remove_data(SListEntry **list,
                               SListEqualFunc callback,
                               SListValue data);

/**
 * Sort a list.
 *
 * list is pointer to the list to sort.
 * compare_func is the Function used to compare values in the list.
 */

void slist_sort(SListEntry **list, SListCompareFunc compare_func);

/**
 * Find the entry for a particular value in a list.
 *
 * list is the list to search.
 * callback is the Callback function to be invoked to determine if values in the list are equal to the value to be searched for.
 * data is the value to search for.
 * The list entry of the value being searched for is returned, or NULL if not found.
 */

SListEntry *slist_find_data(SListEntry *list,
                            SListEqualFunc callback,
                            SListValue data);

/**
 * Initialise a @ref SListIterator structure to iterate over a list.
 *
 * list is the pointer to the list to iterate over.
 * iter is the pointer to a SListIterator structure to initialise.
 */

void slist_iterate(SListEntry **list, SListIterator *iter);

/**
 * Determine if there are more values in the list to iterate over.
 *
 * iterator is the list iterator.
 * It returns Zero if there are no more values in the list to iterate over, non-zero if there are more values to read.
 */

int slist_iter_has_more(SListIterator *iterator);

/**
 * Using a list iterator, retrieve the next value from the list.
 *
 * iterator is the list iterator.
 * It returns the next value from the list, or SLIST_NULL if there are no more values in the list.
 */

SListValue slist_iter_next(SListIterator *iterator);

/**
 * Delete the current entry in the list (the value last returned from slist_iter_next)
 *
 * iterator is the list iterator.
 */

void slist_iter_remove(SListIterator *iterator);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef ALGORITHM_SLIST_H */

