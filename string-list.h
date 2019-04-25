#ifndef STRING_LIST_H
#define STRING_LIST_H

#endif //IDSAPROJECT_STRING_LIST_H_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"

typedef struct NodeTag {
    char *data;
    struct NodeTag *next;
} Node;

Node *Node_create();

void Node_destroy(Node *node);

typedef struct ListTag {
    struct NodeTag *first;
} List;

List *List_create();

void List_destroy(List *list);

void List_append(List *list, const char *str);

void List_insert(List *list, int index, const char *str);

char *List_get(List *list, int index);

int List_find(const List *list, const char *str);

void List_remove(List *list, int index);

char *List_pop(List *list, int index);

int List_length(List *list);

void List_print(List *list);

Node *Node_create() {
    Node *node = malloc(sizeof(Node *) * 1000);
    assert(node != NULL);

    node->data = "";
    node->next = NULL;

    return node;
}


void Node_destroy(Node *node) {
    assert(node != NULL);
    free(node);
}


List *List_create() {
    List *list = malloc(sizeof(List));
    assert(list != NULL);

    Node *node = Node_create();
    list->first = node;

    return list;
}


void List_destroy(List *list) {
    assert(list != NULL);

    Node *node = list->first;
    Node *next;
    while (node != NULL) {
        next = node->next;
        free(node);
        node = next;
    }

    free(list);
}


void List_append(List *list, const char *str) {
    char *string = malloc(sizeof(string));
    strcpy(string, str);
    if (List_find(list, string) != -1) //avoid duplicate
        return;
    assert(list != NULL);
    assert(str != NULL);

    Node *node = list->first;
    while (node->next != NULL) {
        node = node->next;
    }

    node->data = string;
    node->next = Node_create();
}


void List_insert(List *list, int index, const char *str) {
    assert(list != NULL);
    assert(str != NULL);
    assert(0 <= index);
    assert(index <= List_length(list));
    char *string = malloc(sizeof(string));
    strcpy(string, str);
    if (index == 0) {
        Node *after = list->first;
        list->first = Node_create();
        list->first->data = string;
        list->first->next = after;
    } else if (index == List_length(list)) {
        List_append(list, str);
    } else {
        Node *before = list->first;
        Node *after = list->first->next;
        while (index > 1) {
            index--;
            before = before->next;
            after = after->next;
        }
        before->next = Node_create();
        before->next->data = string;
        before->next->next = after;
    }
}


char *List_get(List *list, int index) {
    assert(list != NULL);
    assert(0 <= index);
    assert(index < List_length(list));

    Node *node = list->first;
    while (index > 0) {
        node = node->next;
        index--;
    }
    return node->data;
}


int List_find(const List *list, const char *str) {
    assert(list != NULL);
    assert(str != NULL);

    int index = 0;
    Node *node = list->first;
    while (node->next != NULL) {
        if (strcmp(str, node->data) == 0) {
            return index;
        }
        node = node->next;
        index++;
    }
    return -1;
}


void List_remove(List *list, int index) {
    assert(list != NULL);
    assert(0 <= index);
    assert(index < List_length(list));

    if (index == 0) {
        Node *node = list->first;
        list->first = list->first->next;
        Node_destroy(node);
    } else {
        Node *before = list->first;
        while (index > 1) {
            before = before->next;
            index--;
        }
        Node *node = before->next;
        before->next = before->next->next;
        Node_destroy(node);
    }
}


char *List_pop(List *list, int index) {
    assert(list != NULL);
    assert(0 <= index);
    assert(index < List_length(list));

    if (index == 0) {
        Node *node = list->first;
        list->first = list->first->next;
        char *data = node->data;
        Node_destroy(node);
        return data;
    } else {
        Node *before = list->first;
        while (index > 1) {
            before = before->next;
            index--;
        }
        Node *node = before->next;
        before->next = before->next->next;
        char *data = node->data;
        Node_destroy(node);
        return data;
    }
}


int List_length(List *list) {
    assert(list != NULL);

    Node *node = list->first;
    int length = 0;
    while (node->next != NULL) {
        length++;
        node = node->next;
    }

    return length;
}


void List_print(List *list) {
    assert(list != NULL);

    Node *node = list->first;
    while (node->next != NULL) {
        printf("%s", node->data);
        node = node->next;
        if (node->next != NULL) {
            printf("; \n");
        }
    }
}



