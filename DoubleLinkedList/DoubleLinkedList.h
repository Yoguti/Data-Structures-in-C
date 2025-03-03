#ifndef LIST_H
#define LIST_H

#include <stddef.h>

// Node structure
typedef struct Node {
    void *data;
    struct  Node *prev;
    struct Node *next;
} Node;

// DList structure
typedef struct DList {
    Node *head;
    Node *tail;
    size_t size;
} DList;

//Initialization
void failure(void);
Node* createNode(void *data, Node *prev, Node *next);
void freeNode(Node *node);

// Basic Operations
void insertFront(DList *list, void *data);
void insertBack(DList *list, void *data);
void insertAt(DList *list, void *data, size_t index);

// Deletion Operations
void removeFront(DList *list);
void removeBack(DList *list);
void removeAt(DList *list, size_t index);
void removeValue(DList *list, void *data);

// Access Operations
void* getFront(DList *list);
void* getBack(DList *list);
void* getAt(DList *list, size_t index);

// Search Operations
bool contains(DList *list, void *data);
int indexOf(DList *list, void *data);

// Utility Methods
int getSize(DList *list);
bool isEmpty(DList *list);
void clear(DList *list);

// Traversal & Processing
void map(DList *list, void* (*func)(void*));
Node *reverse(Node *curr);
#endif // LIST_H
