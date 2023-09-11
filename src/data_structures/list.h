#ifndef _list_h_
#define _list_h_

#include <stdlib.h>

struct list_node_t;
typedef struct list_node_t {
    struct list_node_t *next;
    struct list_node_t *prev;
    void *value;
} list_node_t;

typedef struct list_t {
    int count;
    list_node_t *first;
    list_node_t *last;
} list_t;

list_t *List_create();
/** 
 * Destroy List
 */
void List_destroy(list_t *list);
/**
 * Clears the values in the list, not the nodes
 */
void List_clear(list_t *list);
void List_clear_destroy(list_t *list);

#define List_count(A) ((A)->count)
#define List_first(A) ((A)->first != NULL ? (A)->first->value: NULL)
#define List_last(A) ((A)->last != NULL ? (A)->last->value: NULL)
/**
 * Push node to the end of the list
 */
void List_push(list_t *list, void *value);
/**
 * Take the last element off and return List
 */
void *List_pop(list_t *list);
/**
 * Add node to the front of the list 
 */
void List_unshift(list_t *list, void *value);
/**
 * Remove the first node element and return List
 */
void *List_shift(list_t *list);
/**
 * Remove elements from the list 
 */
void *List_remove(list_t *list, list_node_t *node);

#endif
