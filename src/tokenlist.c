#include <stdlib.h>
#include "tokenlist.h"
#include "token.h"


//#ifndef NULL
//#define NULL 0
//#endif // !NULL


/* tl_newList
*
*  purpose: create a new list
*
*  inputs: nothing
*
*  returns: a new list
*/
TokenList * tl_newList(void) {
	TokenList *new = (TokenList *)malloc(sizeof(TokenList));
	new->size = 0;
	return new;
}

/* tl_getLastElement
*
*  purpose: get the last element in the list
*
*  inputs: list: the list to get the element from
*
*  returns: the last element in the list
*/
void tl_updateLastElement(TokenList * list) {

	t_NodeElement *head = list->head;

	for (int i = 0; head->next != NULL; i++) {
		head = head->next;
	}

	list->curr = head;
}

/* tl_getElem
*
*  purpose: get an element in the list
*
*  inputs: list: the list to get the element from
*		   pos : the position of the element to retrieve from the list
*
*  returns: the element in the list at the position given
*/
t_NodeElement * tl_getElem(TokenList * list, int pos) {

	t_NodeElement *head = list->head;

	for (int i = 0; i < pos; i++) {
		head = head->next;
	}

	return head;
}

/* tl_getNext
*
*  purpose: get the next element in the list
*
*  inputs: curr: the current element of the list
*
*  returns: the next element in the list
*/
t_NodeElement * tl_getNext(t_NodeElement * curr) {
	t_NodeElement * next = curr->next;

	return next;
}

/* tl_updateLength
*
*  purpose: update the length of the list
*
*  inputs: list: the list to update the length of
*
*  returns: nothing
*/
void tl_updateLength(TokenList * list) {

	t_NodeElement *head = list->head;

	int i = 0;

	for (; head != NULL; i++) {
		head = head->next;
	}

	list->size = i;
}

/* tl_add
*
*  purpose: add an element to the list
*
*  inputs: list: the list to add to
*		   new: the element to be added
*
*  returns: nothing
*/
void tl_add(TokenList * list, token newVar) {

	t_NodeElement *newElem = (t_NodeElement *)malloc(sizeof(t_NodeElement));
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

/* tl_addArray
*
*  purpose: append an array to the end of a list
*
*  inputs: list: the list to append to
*		   arr: the array to append
*		   numElem: the amount of elements to append
*
*  returns: nothing
*/
void tl_addArray(TokenList * list, token * arr, int numElem) {

	t_NodeElement *curr = list->curr;

	for (int i = 0; i < numElem; i++) {
		t_NodeElement *n = (t_NodeElement *)malloc(sizeof(t_NodeElement));
		n->c = arr[i];

		curr = n;
	}

	list->curr = curr;
	list->size += numElem;
}

/* tl_fromArray
*
*  purpose: convert array to a list
*
*  inputs: arr: the array to create from
*		   numElem: the amount of elements to add
*
*  returns: nothing
*/
TokenList * tl_fromArray(token * arr, int numElem) {

	TokenList * list = malloc(sizeof(TokenList));

	if (numElem > 1) {
		t_NodeElement *n = malloc(sizeof(t_NodeElement));
		n->c = arr[0];
		list->head = n;
	}

	for (int i = 1; i < numElem; i++) {
		tl_add(list, arr[i]);
	}

	return list;
}

/* tl_deleteList
*
*  purpose: free all the memory in a list
*
*  inputs: list: the list to free
*
*  returns: nothing
*/
void tl_deleteList(TokenList * list) {

	t_NodeElement *head = list->head;
	t_NodeElement *curr = NULL;

	while (head != NULL) {
		if (head->next != NULL) {
			curr = head->next;
		}

		free(head);
		head = curr;
	}

	free(list);
}