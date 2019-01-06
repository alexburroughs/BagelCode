/*
* tokenizer
* Reads in string and returns tokens
*/

#include "token.h"
#include "tokenlist.h"
#include "charlist.h"
#include "stdlib.h"

c_NodeElement * advance(c_NodeElement *n, int num) {

	for (int i = 0; i < num; i++) {
		n = n->next;
	}

	return n;
}

char peek(c_NodeElement *n, int num) {

	for (int i = 0; i < num; i++) {
		n = n->next;
	}

	return n->c;
}

void error() {

}

TokenList * tokenize(CharList * list) {
	
	c_NodeElement *head = list->head;
	TokenList *t_list = tl_newList();

	int line = 0;
	int id = 0;

	for (int i = 0; i < list->size; i++) {

		token *t_tmp = malloc(sizeof(token));

		switch (head->c) {
			
			// equal
			case '=':
				switch (peek(head, 1)) {
					case '=':
						t_tmp->id = id;
						t_tmp->identifier = EQUAL;
						t_tmp->line = line;
						t_tmp->text = cl_fromLink(head, 2);
						id++;
						advance(head, 2);
						break;

					default:
						t_tmp->id = id;
						t_tmp->identifier = ASSIGN;
						t_tmp->line = line;
						t_tmp->text = cl_fromLink(head, 1);
						id++;
						advance(head, 1);
						break;
				}
				break;
			case '>':
				switch (peek(head, 1)) {
					case '=':
						t_tmp->id = id;
						t_tmp->identifier = GREATER_EQ;
						t_tmp->line = line;
						t_tmp->text = cl_fromLink(head, 2);
						id++;
						advance(head, 2);
						break;

					default:
						t_tmp->id = id;
						t_tmp->identifier = GREATER;
						t_tmp->line = line;
						t_tmp->text = cl_fromLink(head, 1);
						id++;
						advance(head, 1);
						break;
					}
					break;
			case '<':
				switch (peek(head, 1)) {
					case '=':
						t_tmp->id = id;
						t_tmp->identifier = LESS_EQ;
						t_tmp->line = line;
						t_tmp->text = cl_fromLink(head, 2);
						id++;
						advance(head, 2);
						break;

					default:
						t_tmp->id = id;
						t_tmp->identifier = LESS;
						t_tmp->line = line;
						t_tmp->text = cl_fromLink(head, 1);
						id++;
						advance(head, 1);
						break;
					}
					break;
			case '|':
				switch (peek(head, 1)) {
				case '|':
					t_tmp->id = id;
					t_tmp->identifier = LESS_EQ;
					t_tmp->line = line;
					t_tmp->text = cl_fromLink(head, 2);
					id++;
					advance(head, 2);
					break;

				default:
					printf("error on line: %d, unexpected symbol |\n", line);
					exit(1);
					break;
				}
				break;
			default:
				break;
		}

	}
}