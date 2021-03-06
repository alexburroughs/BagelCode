#ifndef CHARLIST_H
#define CHARLIST_H

typedef struct c_NodeElement {
	struct c_NodeElement *next;
	char c;
} c_NodeElement;

typedef struct charList {
	c_NodeElement *head;
	int size;
	c_NodeElement *curr;
} CharList;

CharList * cl_newList(void);
c_NodeElement * cl_getLastElement(CharList * list);
c_NodeElement * cl_getElem(CharList * list, int pos);
c_NodeElement * cl_getNext(c_NodeElement * curr);
void cl_updateLength(CharList * list);
void cl_add(CharList * list, char newVar);
CharList * cl_fromArray(char * arr, int numElem);
CharList * cl_fromLink(c_NodeElement * elem, int numElem);
void cl_deleteList(CharList * list);
char * cl_toArray(CharList *list);
int cl_findNext(c_NodeElement *node, char elem);
int cl_match(c_NodeElement * node, char * arr, int count);
#endif
