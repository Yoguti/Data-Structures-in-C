#include <stdio.h>
#include <stdlib.h>
#include <LinkedList.h>


void failure(void) {
	exit(EXIT_FAILURE);
}

Node* createNode(void *data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode) {
		exit(EXIT_FAILURE);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void freeNode(Node* node) {
    if (node) {
        free(node);
    }
}


void insertFront(List *list, void *data) {

    Node* newNode = createNode(data);

	if (list->head == NULL) {
		list->head = newNode;
		return;
	}

    newNode->next = list->head;
    list->head = newNode;  
    return;
}

void insertAt(List *list, void *data, size_t index) {
	if (list->head == NULL) {
		return;
	}
    if (index == 0) {
        insertFront(list, data);
        return;
    }

    Node* p_before_at = list->head;
    Node* p_at = list->head->next;

    while (index > 1 && p_at != NULL) { 
        index--;
        p_before_at = p_at;
        p_at = p_at->next;
    }

    if (p_at == NULL && index > 1) {
        failure();
    }

    Node* temp = p_at;
	Node* insertedNode = createNode(data);
	p_before_at->next = insertedNode;
	insertedNode->next = temp;
}

void removeAt(List *list, size_t index) {
	if (list->head == NULL) {
		return;
	}    if (index == 0) {
        removeFront(list);
        return;
    }

    Node* p_before_at = list->head;
    Node* p_at = list->head->next;

    while (index > 1 && p_at != NULL) { 
        index--;
        p_before_at = p_at;
        p_at = p_at->next;
    }

    if (p_at == NULL && index > 0) {
        failure();
    }

    p_before_at->next = p_at->next;
    freeNode(p_at);
}



void removeFront(List *list) {
	if (list->head == NULL) {
		return;
	}

	Node* temp = list->head;
	list->head = list->head->next;
	freeNode(temp);

	return;
}


void insertBack(List *list, void *data) {

	Node* newNode = createNode(data);

	if (list->head == NULL) {
		list->head = newNode;
		return;
	}

	Node* p_last = list->head;

	while (p_last->next != NULL) {
		p_last = p_last->next;
	}

	p_last->next = newNode;

	return;
}

void removeBack(List *list) {

	if (list->head == NULL) {
		return;
	}

	if (list->head->next == NULL) {
        freeNode(list->head);
        list->head = NULL;
        return;
    }

	Node* p_seclast = list->head;
	Node* p_last = list->head->next;

	while (p_last->next != NULL) {
		p_last = p_last->next;
		p_seclast = p_seclast->next;
	}

	freeNode(p_last);
	p_seclast->next = NULL;

	return;
}
