#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>

struct ListNode;
typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    void *value;
} ListNode;

typedef struct List {
    int count;
    ListNode *first;
    ListNode *last;
} List;

List *List_create();
/** 
 * Destroy List
 */
void List_destroy(List *list);
/**
 * Clears the values in the list, not the nodes
 */
void List_clear(List *list);
void List_clear_destroy(List *list);

#define List_count(A) ((A)->count)
#define List_first(A) ((A)->first != NULL ? (A)->first->value: NULL)
#define List_last(A) ((A)->last != NULL ? (A)->last->value: NULL)
/**
 * Push node to the end of the list
 */
void List_push(List *list, void *value);
/**
 * Take the last element off and return List
 */
void *List_pop(List *list);
/**
 * Add node to the front of the list 
 */
void List_unshift(List *list, void *value);
/**
 * Remove the first node element and return List
 */
void *List_shift(List *list);
/**
 * Remove elements from the list 
 */
void *List_remove(List *list, ListNode *node);

#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
                                                   ListNode *V = NULL;\
for(V = _node = L->S; _node !=NULL; V = _node = _node->M)

#endif
