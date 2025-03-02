#ifndef CIRCULARLSIT_H
#define CIRCULARLIST_H

#include <stddef.h>

// Node Structure
typedef struct Node {
    void* data;
    Node* prev;
    Node* next;
} Node;

// CList structure
typedef struct CList {
    Node* head;
    Node* tail;
    size_t size;
} CList;

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

//Initialization
void failure(void);
Node* createNode(void *data, Node* next);
void freeNode(Node *node);

// Basic Operations
void insertFront(CList *list, void *data);
void insertBack(CList *list, void *data);
void insertAt(CList *list, void *data, size_t index);

// Deletion Operations
void removeFront(CList *list);
void removeBack(CList *list);
void removeAt(CList *list, size_t index);
void removeValue(CList *list, void *data);

// Access Operations
void* getFront(CList *list);
void* getBack(CList *list);
void* getAt(CList *list, size_t index);

// Search Operations
int contains(CList *list, void *data);
int indexOf(CList *list, void *data);

// Utility Methods
int getSize(CList *list);
int isEmpty(CList *list);
void clear(CList *list);

// Traversal & Processing
void map(CList *list, void* (*func)(void*));
void reverse(CList *list);

#endif // CIRCULARLIST_H