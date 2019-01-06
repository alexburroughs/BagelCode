#include <stdlib.h>
#include "charlist.h"


//#ifndef NULL
//#define NULL 0
//#endif // !NULL


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
void cl_updateLastElement(CharList * list) {

	c_NodeElement *head = list->head;

	for (int i = 0 ; head->next != NULL; i++) {
		head = head->next;
	}

	list->curr = head;
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
c_NodeElement * cl_getElem(CharList * list ,int pos) {

	c_NodeElement *head = list->head;

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
c_NodeElement * cl_getNext(c_NodeElement * curr) {
	c_NodeElement * next = curr->next;

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

	c_NodeElement *head = list->head;

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
	
	c_NodeElement *newElem = (c_NodeElement *) malloc(sizeof(c_NodeElement));
	newElem->c = newVar;

	if (list->size > 0) {
		list->curr->next = newElem;
	}

	else {
		list->head = newElem;
		list->curr = newElem;
	}

	list->curr = newElem;

	list->size++;
}

/* cl_addArray
*
*  purpose: append an array to the end of a list
*
*  inputs: list: the list to append to
*		   arr: the array to append
*		   numElem: the amount of elements to append
*
*  returns: nothing
*/
void cl_addArray(CharList * list, char * arr, int numElem) {

	c_NodeElement *curr = list->curr;

	for (int i = 0; i < numElem; i++) {
		c_NodeElement *n = (c_NodeElement *) malloc(sizeof(c_NodeElement));
		n->c = arr[i];

		curr = n;
	}

	list->curr = curr;
	list->size += numElem;
}

/* cl_fromArray
*
*  purpose: convert array to a list
*
*  inputs: arr: the array to create from
*		   numElem: the amount of elements to add
*
*  returns: CharList
*/
CharList * cl_fromArray(char * arr, int numElem) {

	CharList * list = malloc(sizeof(CharList));

	if (numElem > 1) {
		c_NodeElement *n = malloc(sizeof(c_NodeElement));
		n->c = arr[0];
		list->head = n;
	}

	for (int i = 1; i < numElem; i++) {
		cl_add(list, arr[i]);
	}

	return list;
}

/* cl_fromLink
*
*  purpose: splice a list
*
*  inputs: arr: the list to splice
*		   numElem: the amount of elements to splice
*
*  returns: CharList
*/
CharList * cl_fromLink(c_NodeElement * elem, int numElem) {

	CharList * list = malloc(sizeof(CharList));
	c_NodeElement *n = malloc(sizeof(c_NodeElement));

	for (int i = 0; i < numElem; i++) {
		cl_add(list, n->c);
		n = n->next;
	}

	return list;
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

	c_NodeElement *head = list->head;
	c_NodeElement *curr = NULL;

	while (head != NULL) {
		if (head->next != NULL) {
			curr = head->next;
		}

		free(head);
		head = curr;
	}

	free(list);
}