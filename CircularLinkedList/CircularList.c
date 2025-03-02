#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <CircularList.h>


//Initialization
void failure(void) {
    exit(EXIT_FAILURE);
}

Node* createNode(void *data, Node *next) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        failure();
    }
    newNode->data = data;
    if (next) {
        newNode->next = next;
    } else {
        newNode->next = NULL;
    }
    return newNode;
    
}

void freeNode(Node *node) {
    if (node) {
        free(node);
    } else { failure(); }
}

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

