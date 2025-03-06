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
   return newNode;
}

void freeNode(Node *node) {
    if (node) {
        free(node);
    } else {
        failure();
    }
}

void push(Stack *stack, void* data) {
    if (stack->top == NULL) {
        Node* newNode = createNode(data, NULL);
        stack->top = newNode;
        return;
    }

    Node* newNode = createNode(data, stack->top);
    stack->top = newNode;
    stack->size++;
    return;
}

void* pop(Stack *stack) {
    if (stack->top == NULL) {
        return NULL;
    }
    Node* ref = stack->top->bellow;
    void* ref_top = stack->top->data;

    freeNode(stack->top);
    stack->top = ref;
    stack->size--;
    return ref_top;
}

void* top(Stack *stack) {
    return stack->top ? stack->top->data : NULL;
}

bool isEmpty(Stack *stack) {
    return stack->top ? false : true;
}
void clear(Stack *stack) {
    while (stack->top != NULL)
    {
        pop(stack);
    }
    return;
}
int size(Stack *stack) {
    return (int)stack->size;
}
bool contains(Stack *stack, void* data) {
    Node* p = stack->top;
    while (p != NULL)
    {
        if (p->data == data) {
            return true;
        }
        p = p->bellow;
    }
    return false;
}