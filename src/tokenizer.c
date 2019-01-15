/*
* tokenizer
* Reads in source code as list of chars and returns a list of tokens
* looks for keywords (token.h)
*/

#define DEFAULT_ASSIGN(x) t_tmp->id = id; t_tmp->line = line; id++; t_tmp->text = cl_fromLink(head, x); advance(head, x);
#define IS_LETTER(x) ((x >= 'a' && x <= 'z') || x >= 'A' && x <= 'Z')
#define IS_NUMBER(x) (x >= '0' && x <= '9')
#define IS_ID_SYM(x) (x == '-' || x == '_')
#define IS_WHITESPACE(x) (x == ' ' || x == '\n')

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
						DEFAULT_ASSIGN(2)
						break;

					default:
						t_tmp->identifier = ASSIGN;
						DEFAULT_ASSIGN(1)
						break;
				}
				break;
			case '>':
				switch (peek(head, 1)) {
					case '=':
						t_tmp->identifier = GREATER_EQ;
						DEFAULT_ASSIGN(2)
						break;

					default:
						t_tmp->identifier = GREATER;
						DEFAULT_ASSIGN(1)
						break;
					}
					break;
			case '<':
				switch (peek(head, 1)) {
					case '=':
						t_tmp->identifier = LESS_EQ;
						DEFAULT_ASSIGN(2)
						break;

					default:
						t_tmp->identifier = LESS;
						DEFAULT_ASSIGN(1)
						break;
					}
					break;
			case '|':
				switch (peek(head, 1)) {
				case '|':
					t_tmp->identifier = OR;
					DEFAULT_ASSIGN(2)
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
					DEFAULT_ASSIGN(2)
					break;

				default:
					t_tmp->identifier = ADDR;
					DEFAULT_ASSIGN(1)
					break;
				}
				break;
			case '!':
				switch (peek(head, 1)) {
				case '=':
					t_tmp->identifier = NOT_EQ;
					DEFAULT_ASSIGN(2)
					break;

				default:
					t_tmp->identifier = NOT;
					DEFAULT_ASSIGN(1)
					break;
				}
				break;
			case '*':
				switch (peek(head, 1)) {
				case '=':
					t_tmp->identifier = STAR_EQ;
					DEFAULT_ASSIGN(2)
					break;

				default:
					t_tmp->identifier = STAR;
					DEFAULT_ASSIGN(1)
					break;
				}
				break;
			case '+':
				switch (peek(head, 1)) {
				case '=':
					t_tmp->identifier = ADD_EQ;
					DEFAULT_ASSIGN(2)
					break;

				default:
					t_tmp->identifier = ADD;
					DEFAULT_ASSIGN(1)
					break;
				}
				break;
			case '-':
				switch (peek(head, 1)) {
				case '=':
					t_tmp->identifier = SUB_EQ;
					DEFAULT_ASSIGN(2)
					break;
				case '>':
					t_tmp->identifier = ARROW;
					DEFAULT_ASSIGN(2)
					break;
				default:
					t_tmp->identifier = SUB;
					DEFAULT_ASSIGN(1)
					break;
				}
				break;
			case '/':
				switch (peek(head, 1)) {
				case '=':
					t_tmp->identifier = DIV_EQ;
					DEFAULT_ASSIGN(2)
					break;
				case '/':
					free(t_tmp);
					advance(head, cl_findNext(head, '\n') + 1);
					break;

				default:
					t_tmp->identifier = DIV;
					DEFAULT_ASSIGN(1)
					break;
				}
				break;
			case '%':
				switch (peek(head, 1)) {
				case '=':
					t_tmp->identifier = MOD_EQ;
					DEFAULT_ASSIGN(2)
					break;

				default:
					t_tmp->identifier = MOD;
					DEFAULT_ASSIGN(1)
					break;
				}
				break;
			case '{':
				t_tmp->identifier = LEFT_BLOCK;
				DEFAULT_ASSIGN(1)
				break;
			case '}':
				t_tmp->identifier = RIGHT_BLOCK;
				DEFAULT_ASSIGN(1)
				break;
			case '(':
				t_tmp->identifier = LEFT_BRACKET;
				DEFAULT_ASSIGN(1)
				break;
			case ')':
				t_tmp->identifier = RIGHT_BRACKET;
				DEFAULT_ASSIGN(1)
				break;
			case ';':
				t_tmp->identifier = SEMICOLON;
				DEFAULT_ASSIGN(1)
				break;
			case '.':
				t_tmp->identifier = DOT;
				DEFAULT_ASSIGN(1)
				break;
			case ',':
				t_tmp->identifier = COMMA;
				DEFAULT_ASSIGN(1)
				break;
			case '"': 
			{
				c_NodeElement *tmp = head;
				int count = 1;
				while (tmp->c != '"') {

					++count;
					tmp = tmp->next;
				}

				++count;

				t_tmp->identifier = STRING;
				DEFAULT_ASSIGN(count)
			 }
			break;
			default:
				if (IS_WHITESPACE(head->c)) {
					advance(head, 1);
					free(t_tmp);
					continue;
				}

				if (IS_LETTER(head->c)) {
					
					// Check for if
					if (cl_match(head, "if", 2)) {
						t_tmp->identifier = IF;
						DEFAULT_ASSIGN(2)
					}

					else if (cl_match(head, "else", 4)) {
						t_tmp->identifier = ELSE;
						DEFAULT_ASSIGN(4)
					}

					else if (cl_match(head, "elif", 4)) {
						t_tmp->identifier = ELIF;
						DEFAULT_ASSIGN(4)
					}

					else if (cl_match(head, "for", 3)) {
						t_tmp->identifier = FOR;
						DEFAULT_ASSIGN(3)
					}

					else if (cl_match(head, "while", 5)) {
						t_tmp->identifier = WHILE;
						DEFAULT_ASSIGN(5)
					}

					else if (cl_match(head, "loop", 4)) {
						t_tmp->identifier = LOOP;
						DEFAULT_ASSIGN(4)
					}

					else if (cl_match(head, "continue", 8)) {
						t_tmp->identifier = CONTINUE;
						DEFAULT_ASSIGN(8)
					}

					else if (cl_match(head, "break", 5)) {
						t_tmp->identifier = BREAK;
						DEFAULT_ASSIGN(5)
					}

					else if (cl_match(head, "goto", 4)) {
						t_tmp->identifier = GOTO;
						DEFAULT_ASSIGN(4)
					}

					else if (cl_match(head, "struct", 6)) {
						t_tmp->identifier = STRUCT;
						DEFAULT_ASSIGN(6)
					}

					else if (cl_match(head, "enum", 4)) {
						t_tmp->identifier = ENUM;
						DEFAULT_ASSIGN(4)
					}

					else if (cl_match(head, "return", 6)) {
						t_tmp->identifier = RET;
						DEFAULT_ASSIGN(6)
					}

					else if (cl_match(head, "fn", 2)) {
						t_tmp->identifier = FN;
						DEFAULT_ASSIGN(2)
					}

					else if (cl_match(head, "num", 3)) {
						t_tmp->identifier = NUM;
						DEFAULT_ASSIGN(3)
					}

					else if (cl_match(head, "str", 3)) {
						t_tmp->identifier = STR;
						DEFAULT_ASSIGN(3)
					}

					else if (cl_match(head, "chr", 3)) {
						t_tmp->identifier = CHR;
						DEFAULT_ASSIGN(3)
					}

					else if (cl_match(head, "pnt", 3)) {
						t_tmp->identifier = PNT;
						DEFAULT_ASSIGN(3)
					}

					else {

						c_NodeElement *tmp = head;
						int count = 1;
						while (IS_LETTER(tmp->c) || IS_NUMBER(tmp->c) || IS_ID_SYM(tmp->c)) {

							++count;
							tmp = tmp->next;
						}

						t_tmp->identifier = NAME;
						DEFAULT_ASSIGN(count)
					}

				}

				else if (IS_NUMBER(head->c)) {
					
					int count = 1;
					c_NodeElement *tmp = head->next;

					while (IS_NUMBER(tmp->c)) {
						++count;
						tmp = tmp->next;
					}

					t_tmp->identifier = NUMBER;
					DEFAULT_ASSIGN(count);
				}
				break;
		}
	}

	return t_list;
}