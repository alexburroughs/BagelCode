/*
* tokenizer
* Reads in string and returns tokens
*/

#define DEFAULT_ASSIGN() t_tmp->id = id; t_tmp->line = line; id++;

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

/* peek
* 
*/
char peek(c_NodeElement *n, int num) {

	for (int i = 0; i < num; i++) {
		n = n->next;
	}

	return n->c;
}

void error(int line, char *message) {

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
						t_tmp->identifier = EQUAL;
						DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 2);
						advance(head, 2);
						break;

					default:
						t_tmp->identifier = ASSIGN;
						DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 1);
						advance(head, 1);
						break;
				}
				break;
			case '>':
				switch (peek(head, 1)) {
					case '=':
						t_tmp->identifier = GREATER_EQ;
						DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 2);
						advance(head, 2);
						break;

					default:
						t_tmp->identifier = GREATER;
						DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 1);
						advance(head, 1);
						break;
					}
					break;
			case '<':
				switch (peek(head, 1)) {
					case '=':
						t_tmp->identifier = LESS_EQ;
						DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 2);
						advance(head, 2);
						break;

					default:
						t_tmp->identifier = LESS;
						DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 1);
						advance(head, 1);
						break;
					}
					break;
			case '|':
				switch (peek(head, 1)) {
				case '|':
					t_tmp->identifier = OR;
					DEFAULT_ASSIGN()
					t_tmp->text = cl_fromLink(head, 2);
					advance(head, 2);
					break;

				default:
					printf("error on line: %d, unexpected symbol %s\n", line, peek(head, 1));
					exit(1);
					break;
				}
				break;
			case '&':
				switch (peek(head, 1)) {
				case '&':
					t_tmp->identifier = AND;
					DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 2);
					advance(head, 2);
					break;

				default:
					t_tmp->identifier = ADDR;
					DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 1);
					advance(head, 1);
					break;
				}
				break;
			case '!':
				switch (peek(head, 1)) {
				case '=':
					t_tmp->identifier = NOT_EQ;
					DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 2);
					advance(head, 2);
					break;

				default:
					t_tmp->identifier = NOT;
					DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 1);
					advance(head, 1);
					break;
				}
				break;
			case '*':
				switch (peek(head, 1)) {
				case '=':
					t_tmp->identifier = STAR_EQ;
					DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 2);
					advance(head, 2);
					break;

				default:
					t_tmp->identifier = STAR;
					DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 1);
					advance(head, 1);
					break;
				}
				break;
			case '+':
				switch (peek(head, 1)) {
				case '=':
					t_tmp->identifier = ADD_EQ;
					DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 2);
					advance(head, 2);
					break;

				default:
					t_tmp->identifier = ADD;
					DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 1);
					advance(head, 1);
					break;
				}
				break;
			case '-':
				switch (peek(head, 1)) {
				case '=':
					t_tmp->identifier = SUB_EQ;
					DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 2);
					advance(head, 2);
					break;

				default:
					t_tmp->identifier = SUB;
					DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 1);
					advance(head, 1);
					break;
				}
				break;
			case '/':
				switch (peek(head, 1)) {
				case '=':
					t_tmp->identifier = DIV_EQ;
					DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 2);
					advance(head, 2);
					break;

				default:
					t_tmp->identifier = DIV;
					DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 1);
					advance(head, 1);
					break;
				}
				break;
			case '%':
				switch (peek(head, 1)) {
				case '=':
					t_tmp->identifier = MOD_EQ;
					DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 2);
					advance(head, 2);
					break;

				default:
					t_tmp->identifier = MOD;
					DEFAULT_ASSIGN()
						t_tmp->text = cl_fromLink(head, 1);
					advance(head, 1);
					break;
				}
				break;
			case '{':
				t_tmp->identifier = LEFT_BLOCK;
				DEFAULT_ASSIGN()
					t_tmp->text = cl_fromLink(head, 1);
				advance(head, 1);
				break;
			case '}':
				t_tmp->identifier = RIGHT_BLOCK;
				DEFAULT_ASSIGN()
					t_tmp->text = cl_fromLink(head, 1);
				advance(head, 1);
				break;
			case '(':
				t_tmp->identifier = LEFT_BRACKET;
				DEFAULT_ASSIGN()
					t_tmp->text = cl_fromLink(head, 1);
				advance(head, 1);
				break;
			case ')':
				t_tmp->identifier = RIGHT_BRACKET;
				DEFAULT_ASSIGN()
					t_tmp->text = cl_fromLink(head, 1);
				advance(head, 1);
				break;
			case ';':
				t_tmp->identifier = SEMICOLON;
				DEFAULT_ASSIGN()
					t_tmp->text = cl_fromLink(head, 1);
				advance(head, 1);
				break;
			case '.':
				t_tmp->identifier = DOT;
				DEFAULT_ASSIGN()
					t_tmp->text = cl_fromLink(head, 1);
				advance(head, 1);
				break;
			case ',':
				t_tmp->identifier = COMMA;
				DEFAULT_ASSIGN()
					t_tmp->text = cl_fromLink(head, 1);
				advance(head, 1);
				break;
			default:
				break;
		}
	}
}