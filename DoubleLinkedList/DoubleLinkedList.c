#include <stdio.h>
#include <stdbool.h>
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
    } else {
		failure();
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
	list->size++;
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
	list->size++;
	return;
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
	list->size++;
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
	list->size--;
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
	list->size--;
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
	Node* p_temp = list->head; //p_temp->next has the index

	while(index > 1 && n_temp != NULL) {
		index--;
		p_temp = n_temp;
		n_temp = n_temp->next;
	}

	if (n_temp == NULL) {return;}

	p_temp->next = n_temp->next;
	if (n_temp->next) {
		n_temp->next->prev = p_temp;
	} else {
		list->tail = p_temp;
	}
	list->size--;
	freeNode(n_temp);
}

void removeValue(DList *list, void *data) {
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

void* getFront(DList *list) {
	return list->head ? list->head->data : NULL;
}

void* getBack(DList *list) {
	return list->tail ? list->tail->data : NULL;
}

void* getAt(DList *list, size_t index) {
	if (list->head == NULL) {
		return NULL;
	}

	Node* p_traverse = list->head;
	size_t compare = 0;
	while (p_traverse != NULL && compare != index) {
		p_traverse = p_traverse->next;
		compare++;
	}
	return p_traverse ? p_traverse->data : NULL;
}

bool contains(DList *list, void *data) {
	if (list->head == NULL) {
		return NULL;
	}

	Node* p_traverse = list->head;
	while (p_traverse != NULL) {
		if (p_traverse->data == data) {return true;}
		p_traverse = p_traverse->next;
	}
	return false;
}

int indexOf(DList *list, void *data) {
	if (list->head == NULL) {
		return -2;
	}
	int index = 0;
	Node* p_traverse = list->head;
	while (p_traverse != NULL) {
		if (p_traverse->data == data) {return index;}
		index++;
		p_traverse = p_traverse->next;
	}
	return -1;
}
int getSize(DList *list) {
	return (int)list->size;
}

bool isEmpty(DList *list) {
	return list->head ? false : true;
}

void clear(DList *list) {
    if (list->head == NULL) {
        return;
    }

    Node* temp = list->head;
    while (temp != NULL) {
        Node* next = temp->next;
        freeNode(temp);
        temp = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void map(DList *list, void* (*func)(void*)) {
	if (list->head == NULL) {
		return;
	}
	Node* this_node = list->head;

	while(this_node != NULL) {
		this_node->data = func(this_node->data);
		this_node = this_node->next;
	}
}