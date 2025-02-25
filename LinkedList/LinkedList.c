#include <stdio.h>
#include <stdlib.h>
#include <LinkedList.h>


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
