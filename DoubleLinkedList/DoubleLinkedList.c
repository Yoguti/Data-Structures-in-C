#include <stdio.h>
#include <stdlib.h>
#include <DoubleLinkedList.h>


void failure(void) {
	exit(EXIT_FAILURE);
}

Node* createNode(void *data, Node *prev) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode) {
		failure();
	}
	newNode->data = data;
	if (prev) {
		newNode->prev = prev;
	} else {
		newNode->prev = NULL;
	}
	newNode->next = NULL;
	return newNode;
}

void freeNode(Node* node) {
    if (node) {
        free(node);
    }
}

void insertFront(DList *list, void *data) {
	if (list->head == NULL) {
		Node* newHead = createNode(data, NULL);
		list->head = newHead;
		return;
	}

	Node* newHead = createNode(data, list->head);
	newHead->next = list->head;
	list->head->prev = newHead;
	return;
}