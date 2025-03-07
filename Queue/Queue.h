#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include <stdbool.h>

typedef struct Node {
    void* data;
    Node* next;
} Node;

typedef struct Queue
{
    Node* top;
    Node* tail;
    size_t size;
} Queue;

// Initialization

void failure(void);
void freeNode(Node* node);
Node* createNode(void* data, Node* next);

// Basic operations

void enqueue(Queue *queue, void* data);
Node* dequeue(Queue *queue);
void* peek(Queue *queue);
void* rear(Queue *queue);
bool isEmpty(Queue *queue);
int size(Queue *queue);

#endif // QUEUE_H