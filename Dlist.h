#ifndef ALGORITHM_LIST_H
#define ALGORITHM_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Represents an entry in a doubly-linked list.  The empty list is
 * represented by a NULL pointer. To initialise a new doubly linked
 * list, simply create a variable of this type
 * containing a pointer to NULL.
 */

typedef struct _ListEntry ListEntry;

/**
 * Structure used to iterate over a list.
 */

typedef struct _ListIterator ListIterator;

/**
 * A value stored in a list.
 */

typedef void *ListValue;

/**
 * Definition of a ListIterator.
 */

struct _ListIterator {
	ListEntry **prev_next;
	ListEntry *current;
};

/**
 * A null ListValue.
 */

#define LIST_NULL ((void *) 0)

/**
 * Callback function used to compare values in a list when sorting.
 */

typedef int (*ListCompareFunc)(ListValue value1, ListValue value2);

/**
 * Callback function used to determine of two values in a list are
 * equal.
 */

typedef int (*ListEqualFunc)(ListValue value1, ListValue value2);

/**
 * Free an entire list.
 *
 * list is the list to free.
 */

void list_free(ListEntry *list);

/**
 * Prepend a value to the start of a list.
 *
 * list is pointer to the list to prepend to.
 * data is the value to prepend.
 * It return the new entry in the list, or NULL if it was not possible to allocate the memory for the new entry.
 */

ListEntry *list_prepend(ListEntry **list, ListValue data);

/**
 * Append a value to the end of a list.
 *
 * list is pointer to the list to append to.
 * data is the value to append.
 * It returns the new entry in the list, or NULL if it was not possible to allocate the memory for the new entry.
 */

ListEntry *list_append(ListEntry **list, ListValue data);

/**
 * Retrieve the previous entry in a list.
 *
 * listentry is pointer to the list entry.
 * It returns the previous entry in the list, or NULL if this was the first entry in the list.
 */

ListEntry *list_prev(ListEntry *listentry);

/**
 * Retrieve the next entry in a list.
 *
 * listentry is pointer to the list entry.
 * It returns the next entry in the list, or NULL if this was the last entry in the list.
 */

ListEntry *list_next(ListEntry *listentry);

/**
 * Retrieve the value at a list entry.
 *
 * listentry is pointer to the list entry.
 * It returns the value stored at the list entry.
 */

ListValue list_data(ListEntry *listentry);

/**
 * Set the value at a list entry. The value provided will be written to the 
 * given listentry. If listentry is NULL nothing is done.
 *
 * listentry is pointer to the list entry.
 * value is the value to set.
 */
void list_set_data(ListEntry *listentry, ListValue value);

/**
 * Retrieve the entry at a specified index in a list.
 *
 * list is the list to be used.
 * n is the index into the list .
 * It returns the entry at the specified index, or NULL if out of range.
 */

ListEntry *list_nth_entry(ListEntry *list, unsigned int n);

/**
 * Retrieve the value at a specified index in the list.
 *
 * list is the list used.
 * n is the index into the list.
 * It returns the value at the specified index, or LIST_NULL if unsuccessful.
 */

ListValue list_nth_data(ListEntry *list, unsigned int n);

/**
 * Find the length of a list.
 *
 * list is the list used.
 * It returns the number of entries in the list.
 */

unsigned int list_length(ListEntry *list);

/**
 * Create a C array containing the contents of a list.
 *
 * list is the list used.
 * It returns a newly-allocated C array containing all values in the list, or NULL if it was not possible to allocate the memory.  The length of the array is equal to the length of the list (see @ref list_length).
 */

ListValue *list_to_array(ListEntry *list);

/**
 * Remove an entry from a list.
 *
 * list is pointer to the list.
 * entry is the list entry to remove .
 * If the entry is not found in the list, returns zero, else returns non-zero.
 */

int list_remove_entry(ListEntry **list, ListEntry *entry);

/**
 * Remove all occurrences of a particular value from a list.
 *
 * list is pointer to the list.
 * callback is function to invoke to compare values in the list with the value to be removed.
 * data is the value to remove from the list.
 * It returns the number of entries removed from the list.
 */

unsigned int list_remove_data(ListEntry **list, ListEqualFunc callback,
                              ListValue data);

/**
 * Sort a list.
 *
 * list is pointer to the list to sort.
 * compare_func is the function used to compare values in the list.
 */

void list_sort(ListEntry **list, ListCompareFunc compare_func);

/**
 * Find the entry for a particular value in a list.
 *
 * list is the list to search.
 * callback is the function to invoke to compare values in the list with the value to be searched for.
 * data is the value to search for.
 * It returns the list entry of the item being searched for, or NULL if not found.
 */

ListEntry *list_find_data(ListEntry *list,
                          ListEqualFunc callback,
                          ListValue data);

/**
 * Initialise a @ref ListIterator structure to iterate over a list.
 *
 * list is a pointer to the list to iterate over.
 * iter is a pointer to an iterator structure to initialise.
 */

void list_iterate(ListEntry **list, ListIterator *iter);

/**
 * Determine if there are more values in the list to iterate over.
 *
 * iterator is the list iterator.
 * It returns Zero if there are no more values in the list to iterate over, non-zero if there are more values to read.
 */

int list_iter_has_more(ListIterator *iterator);

/**
 * Using a list iterator, retrieve the next value from the list.
 *
 * iterator is the list iterator.
 * It returns the next value from the list, or @ref LIST_NULL if there are no more values in the list.
 */

ListValue list_iter_next(ListIterator *iterator);

/**
 * Delete the current entry in the list (the value last returned from
 * list_iter_next)
 *
 * iterator is the list iterator.
 */

void list_iter_remove(ListIterator *iterator);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef ALGORITHM_LIST_H */
