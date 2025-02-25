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

void removeValue(List *list, void *data) {
	if (list->head == NULL) {
		return;
	}

	Node* p_temp = list->head;
	size_t count = 0;
	while (p_temp->next != NULL) {
		if (p_temp->data == data) {
			removeAt(list, count);	
			p_temp = p_temp->next;
		} else {
			count++;
			p_temp = p_temp->next;
		}
	}
	return;
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


void* getFront(List *list) {

	if (list->head == NULL) {
		return NULL;
	}
	return list->head->data;
}
void* getBack(List *list) {
	if (list->head == NULL) {
		return NULL;
	}

	Node* p_traverse = list->head;
	while (p_traverse->next != NULL) {
		p_traverse = p_traverse->next;
	}

	return p_traverse->data;
}
void* getAt(List *list, size_t index) {
	if (list->head == NULL) {
		return NULL;
	}

	Node* p_traverse = list->head;
	size_t compare = 0;
	while (p_traverse->next != NULL && compare != index) {
		p_traverse = p_traverse->next;
		compare++;
	}

	if (p_traverse == NULL) {
		return NULL;
	}

	return p_traverse->data;
}