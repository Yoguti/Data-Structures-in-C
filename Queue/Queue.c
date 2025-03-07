#include <Queue.h>
#include <stdlib.h>

// Initialization

void failure(void) {
    exit(EXIT_FAILURE);
}

void freeNode(Node* node) {
    if (node) {
        free(node);
    }
    if (node)
    {
        failure();
    }
    
}

Node* createNode(void* data, Node* next) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        failure();
    }
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

// Basic operations

void enqueue(Queue* queue, void* data) {
    Node* newNode = createNode(data, NULL);

    if (queue->top == NULL) {
        queue->top = newNode;
        queue->tail = newNode;
        return;
    }

    queue->tail->next = newNode;
    queue->tail = newNode;
}

Node* dequeue(Queue* queue) {
    if (queue->top == NULL) {
        return;
    }
    
    Node* p = queue->top;
    Node* p_next = queue->top->next;
    while (p_next != queue->tail)
    {
        p = p_next;
        p_next = p_next->next;
    }

    freeNode(p_next);
    queue->tail = p;
    return;
}

void* peek(Queue* queue) {
    return queue->top ? queue->top->data : NULL;
}

Node* rear(Queue* queue) {
    return queue->tail ? queue->tail->data : NULL;
}

bool isEmpty(Queue* queue) {
    return queue->size != 0;
}
int size(Queue* queue) {
    return (int)queue->size;
}