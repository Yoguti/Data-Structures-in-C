#include <Stack.h>
#include <stdlib.h>

void failure(void) {
    exit(EXIT_FAILURE);
}

Node* createNode(void *data, Node* bellow) {
   Node* newNode = malloc (sizeof(Node));
   if (newNode) {
        newNode->data = data;
        newNode->bellow = bellow;
   } else {
    failure();
   }
}

void freeNode(Node *node) {
    if (node) {
        free(node);
    } else {
        failure();
    }
}