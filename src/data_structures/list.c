#include "list.h"
#include "../dbg.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

list_t *List_create() {
    return calloc(1, sizeof(list_t));
}

void List_destroy(list_t *list) {
    list_node_t *curr = list->first;

    while (curr != NULL) {
        list_node_t *next = curr->next;

        if(curr->prev) {
            free(curr->prev);
        }

        free(curr);
        curr = next;
    }

    free(list);
}

void List_clear(list_t *list) {
    list_node_t *curr = list->first;
    
    while (curr != NULL) {
        free(curr->value);

        // Move to the next node.
        curr = curr->next;
    }
}


void List_clear_destroy(list_t *list) {
    List_clear(list);
    List_destroy(list);
}

void List_push(list_t *list, void *value) {
    list_node_t *node = calloc(1, sizeof(list_node_t));
    check_mem(node);

    node->value = value;

    if (list->last == NULL) {
        list->first = node;
        list->last = node;
    } else {
    list->last->next = node;
    node->prev = list->last;
    list->last = node;
    }

    list->count++;

error: return;
}

void *List_pop(list_t *list) {
    list_node_t *node = list->last;

    return node != NULL ? List_remove(list, node) : NULL;
}

void List_unshift(list_t *list, void *value) {
    list_node_t *node = calloc(1, sizeof(list_node_t));
    check_mem(node);

    node->value = value;

    if(list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->first->prev = node;
        node->next = list->first;
        list->first = node;
    }

    list->count++;

error: return;
}

void *List_shift(list_t *list) {
    list_node_t *node = list->first;

    return node != NULL ? List_remove(list, node) : NULL;
}

void *List_remove(list_t *list, list_node_t *node) {
    void *result = NULL;
    check(list->first && list->last, "List is empty");
    check(node, "Node is empty");

    if (list->first == list->last) {
        list->first = NULL;
        list->last = NULL;
    } else if (list->first == node) {
        list->first = node-> next;
        list->first->prev = NULL;
        check(list->first != NULL, "First node is empty, invalid list");
    } else if (list->last == node) {
        list->last = node->prev;
        list->last->next = NULL;
        check(list->last != NULL, "Last node is empty, invalid list");
    } else {
        list_node_t *before = node->prev;
        list_node_t *after = node->next;
        before->next = after;
        after->prev = before;
    }

    list->count--;
    result = node->value;
    free(node);

error: return result;
}
