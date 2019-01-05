#include <stdlib.h>

#ifndef NULL
#define NULL 0
#endif // !NULL


typedef struct nodeElement {
	struct nodeElement *next;
	char c;
} NodeElement;

typedef struct charList {
	NodeElement *head;
	int size;
} CharList;

/* cl_newList
*
*  purpose: create a new list
*
*  inputs: nothing
*
*  returns: a new list
*/
CharList * cl_newList(void) {
	CharList *new = (CharList *) malloc(sizeof(CharList));
	new->size = 0;

	return new;
}

/* cl_getLastElement
*
*  purpose: get the last element in the list
*
*  inputs: list: the list to get the element from
*
*  returns: the last element in the list
*/
NodeElement * cl_getLastElement(CharList * list) {

	NodeElement *head = list->head;

	for (int i = 0 ; head->next != NULL; i++) {
		head = head->next;
	}

	return head;
}

/* cl_getElem
*
*  purpose: get an element in the list
*
*  inputs: list: the list to get the element from
*		   pos : the position of the element to retrieve from the list
*
*  returns: the element in the list at the position given
*/
NodeElement * cl_getElem(CharList * list ,int pos) {

	NodeElement *head = list->head;

	for (int i = 0; i < pos; i++) {
		head = head->next;
	 }

	return head;
}

/* cl_getNext
*
*  purpose: get the next element in the list
*
*  inputs: curr: the current element of the list
*
*  returns: the next element in the list
*/
NodeElement * cl_getNext(NodeElement * curr) {
	NodeElement * next = curr->next;

	return next;
}

/* cl_updateLength
*
*  purpose: update the length of the list
*
*  inputs: list: the list to update the length of
*
*  returns: nothing
*/
void cl_updateLength(CharList * list) {

	NodeElement *head = list->head;

	int i = 0;

	for (; head != NULL; i++) { 
		head = head->next;
	}

	list->size = i;
}

/* cl_add
*
*  purpose: add an element to the list
* 
*  inputs: list: the list to add to
*		   new: the element to be added
*
*  returns: nothing
*/
void cl_add(CharList * list, char newVar) {
	
	NodeElement *newElem = (NodeElement *) malloc(sizeof(NodeElement));
	newElem->c = newVar;

	if (list->size > 0) {
		NodeElement *last = cl_getLastElement(list);
		last->next = newElem;
	}

	else {
		list->head = newElem;
	}

	list->size++;
}

/* cl_deleteList
*
*  purpose: free all the memory in a list
*
*  inputs: list: the list to free
*
*  returns: nothing
*/
void cl_deleteList(CharList * list) {

	NodeElement *head = list->head;
	NodeElement *curr = NULL;

	while (head != NULL) {
		if (head->next != NULL) {
			curr = head->next;
		}

		free(head);
		head = curr;
	}

	free(list);
}