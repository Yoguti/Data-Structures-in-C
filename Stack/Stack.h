#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>

typedef struct Node {
    void* data;
    Node* bellow;
} Node;

typedef struct Stack
{
    Node* top;
    size_t size;
} Stack;

//Initialization
void failure(void);
Node* createNode(void *data, Node* bellow);
void freeNode(Node *node);

// Operations

void push(Stack stack);
void* pop(Stack stack);
void* top(Stack stack);
bool isEmpty(Stack stack);
void clear(Stack stack);
int size(Stack stack);
bool contains(Stack stack);

#endif // STACK_H