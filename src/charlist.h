#ifndef CHARLIST_H
#define CHARLIST_H

typedef struct nodeElement {
	struct nodeElement *next;
	char c;
} NodeElement;

typedef struct charList {
	struct charList *head;
	int size;
} CharList;

CharList * cl_newList(void);
NodeElement * cl_getLastElement(CharList * list);
char cl_getElem(CharList * list, int pos);
NodeElement * cl_getNext(NodeElement * curr);
void cl_updateLength(CharList * list);
void cl_add(CharList * list, char newVar);
void cl_deleteList(CharList * list);
#endif