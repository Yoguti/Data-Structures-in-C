#include <stdio.h>
#include <stdlib.h>
#include <DoubleLinkedList.h>


void failure(void) {
	exit(EXIT_FAILURE);
}

Node* createNode(void *data, Node *prev, Node *next) {
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
	if (next) {
		newNode->next = next;
	} else {
		newNode->next = NULL;
	}
	return newNode;
}

void freeNode(Node* node) {
    if (node) {
        free(node);
    }
}

void insertFront(DList *list, void *data) {
	if (list->head == NULL) {
		Node* newHead = createNode(data, NULL, NULL);
		list->head = newHead;
		list->tail = list->head;
		return;
	}

	Node* newHead = createNode(data, NULL, list->head);
	list->head->prev = newHead;
	list->head = newHead;
	return;
}

void insertBack(DList *list, void *data) {
    if (list->head == NULL) { 
        insertFront(list, data);
        return;
    }

    Node* p_temp = list->head;
    while (p_temp->next != NULL) {
        p_temp = p_temp->next;
    }

    Node* temp = createNode(data, p_temp, NULL);
    p_temp->next = temp;
    list->tail = temp;
}

void insertAt(DList *list, void *data, size_t index) {
	if (list->head == NULL) { 
		return;
	}

	if (index == 0) {
        insertFront(list, data);
        return;
    }

	Node* n_temp = list->head->next;
	Node* p_temp = list->head;

	while(index > 1 && n_temp != NULL) {
		index--;
		p_temp = n_temp;
		n_temp = n_temp->next;
	}

	Node* p_at = createNode(data, p_temp, n_temp);

	if (n_temp != NULL) {
		n_temp->prev = p_at;
	} else {
		list->tail = p_at;
	}
	p_temp->next = p_at;
	return;
}

void removeFront(DList *list) {
	if (list->head == NULL) { 
		return;
	}
	Node* temp_head = list->head;
	if (temp_head->next) {
		list->head = temp_head->next;
		temp_head->next->prev = NULL;
	} else { list->head = NULL; }
	freeNode(temp_head);
}


void removeBack(DList *list) {
	if (list->head == NULL) { 
		return;
	}
	if (list->head->next == NULL) {
		Node* temp = list->head;
		list->head = NULL;
		list->tail = NULL;
		freeNode(temp);
		return;
	}
	Node* temp_tail = list->tail;
	list->tail = temp_tail->prev;
	freeNode(temp_tail);
	return;
}

void removeAt(DList *list, size_t index) {
	if (list->head == NULL) { 
		return;
	}
	if (index == 0) {
        removeFront(list);
        return;
    }

	Node* n_temp = list->head->next;
	Node* p_temp = list->head;

	while(index > 1 && n_temp != NULL) {
		index--;
		p_temp = n_temp;
		n_temp = n_temp->next;
	}
	
}


