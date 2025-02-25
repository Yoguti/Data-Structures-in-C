#ifndef LIST_H
#define LIST_H

#include <stddef.h>

// Node structure
typedef struct Node {
    void *data;
    struct Node *next;
} Node;

// List structure
typedef struct List {
    Node *head;
    size_t size;
} List;

//Initialization
Node* createNode(void *data);
void freeNode(Node *node);

// Basic Operations
void insertFront(List *list, void *data);
void insertBack(List *list, void *data);
void insertAt(List *list, void *data, size_t index);

// Deletion Operations
void removeFront(List *list);
void removeBack(List *list);
void removeAt(List *list, size_t index);
void removeValue(List *list, void *data);

// Access Operations
void* getFront(List *list);
void* getBack(List *list);
void* getAt(List *list, size_t index);

// Search Operations
int contains(List *list, void *data);
size_t indexOf(List *list, void *data);

// Utility Methods
size_t getSize(List *list);
int isEmpty(List *list);
void clear(List *list);

// Traversal & Processing
void traverse(List *list, void (*func)(void*));
void reverse(List *list);
void sort(List *list);

#endif // LIST_H
