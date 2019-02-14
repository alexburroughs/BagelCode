#include "token.h"
#ifndef TOKENLIST_H
#define TOKENLIST_H

typedef struct t_NodeElement {
	struct t_NodeElement *next;
	token *c;
} t_NodeElement;

typedef struct tokenList {
	t_NodeElement *head;
	int size;
	t_NodeElement *curr;
}TokenList;

TokenList * tl_newList(void);
void tl_updateLastElement(TokenList * list);
t_NodeElement * tl_getElem(TokenList * list, int pos);
t_NodeElement * tl_getNext(t_NodeElement * curr);
void tl_updateLength(TokenList * list);
void tl_add(TokenList * list, token *newVar);
void tl_deleteList(TokenList * list);
void tl_printList(TokenList * list);
#endif
