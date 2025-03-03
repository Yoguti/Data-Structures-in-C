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
void insertFront(CList *list, void *data) {
    Node* newNode = createNode(data, NULL);

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    Node* temp = list->head;
    list->head = newNode;
    newNode->next = temp;
    list->size++;
    return;
}

void insertBack(CList *list, void *data) {
    if (list->head == NULL) {
        insertFront(list,data);
        return;
    }

    Node* newNode = createNode(data, NULL);

    list->tail->next = newNode;
    list->tail = newNode;
    newNode->next = list->head;
 
    list->size++;
    return;

}

void insertAt(CList *list, void *data, size_t index) {
    if (index > list->size) {
        failure();
        return;
    }

    if (index == 0) {
        insertFront(list, data);
        return;
    }
    
    if (index == list->size) { 
        insertBack(list, data);
        return;
    }

    Node* p_before = list->head;
    for (size_t i = 1; i < index; i++) {  
        p_before = p_before->next;
    }

    Node* newNode = createNode(data, p_before->next);
    p_before->next = newNode;

    list->size++;
    return;
}

// Deletion Operations
void removeFront(CList *list) {
    if (list->head == list->tail) {
        freeNode(list->head);
        list->head = list->tail = NULL;
    } 
    else { 
        
        Node* next_temp = list->head->next;
        freeNode(list->head);
        list->head = next_temp;
        list->tail->next = list->head;
    }

    list->size--;
}

void removeBack(CList *list) {
    if (list->head == NULL) {
        return;
    }
    if (list->head == list->tail) {
        removeFront(list);
        return;
    }
    Node* p_at = list->head->next;
    Node* p_before = list->head;
    while (p_at != list->tail) {
        p_before = p_at;
        p_at = p_at->next;
    }

    freeNode(p_at);
    list->tail = p_before;
    p_before->next = list->head;
    
    list->size--;
}

void removeAt(CList *list, size_t index) {
    if (index >= list->size) {
        failure();
        return;
    }

    if (index == 0) {
        removeFront(list);
        return;
    }
    
    if (index == list->size - 1) { 
        removeBack(list);
        return;
    }

    Node* p_before = list->head;
    for (size_t i = 1; i < index; i++) {  
        p_before = p_before->next;
    }
    Node* temp = p_before->next;
    p_before->next = p_before->next->next;
    freeNode(temp);

    list->size--;
}

void removeValue(CList *list, void *data) {
    if (list->head == NULL) {
        return;
    }
    Node* p_at = list->head;
    size_t index = 0;
    if (list->head->data == data)
    {
        removeFront(list);
        return;
    }
    if (list->tail->data == data)
    {
        removeBack(list);
        return;
    }
    
   while (p_at != list->tail)
   {
    if (p_at->data == data) {
        removeAt(list,index);
        return;
    }
    p_at = p_at->next;
    index++;
    }

    return;
}

// Access Operations
void* getFront(CList *list) {
    return list->head ? list->head->data : NULL;
}
void* getBack(CList *list) {
    return list->tail ? list->tail->data : NULL;
}
void* getAt(CList *list, size_t index) {
    if (list->head == NULL || index >= list->size) {
        return NULL;
    }
    
    Node* p = list->head;
    size_t current_index = 0;

    do {
        if (current_index == index) {
            return p->data; 
        }
        p = p->next;
        current_index++;
    } while (p != list->head);
    return NULL; 
}


// Search Operations
bool contains(CList *list, void *data) {
    if (list->head == NULL)
    {
        return;
    }
    
    if (list->head->data == data) {
        return true;
    }
    Node* p = list->head;
    do
    {
        if (p->data == data) {
            return true; 
        }
        p = p->next;
    } while (p != list->head);

    return false;
    
}
int indexOf(CList *list, void *data) {
    if (list->head == NULL)
    {
        return;
    }
    if (list->head->data == data) {
        return 0;
    }
    Node* p = list->head;
    int index = 0;
    do
    {
        if (p->data == data) {
            return index; 
        }
        p = p->next;
        index++;
    } while (p != list->head);

    return -1;

}

// Utility Methods
int getSize(CList *list);
int isEmpty(CList *list);
void clear(CList *list);

// Traversal & Processing
void map(CList *list, void* (*func)(void*));
void reverse(CList *list);

