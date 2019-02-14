#include "charlist.h"

#ifndef TOKEN_H
#define TOKEN_H

typedef enum Type {
    num,
    str,
    chr,
    pnt
} type;

typedef enum identifier {
	NUM, //done
	STR, //done
	CHR, //done
	PNT, //done
	STAR, //done
	ADDR, //done
	RET, //done
	FN, //done
	ARROW, //done
	LEFT_BLOCK, //done
	RIGHT_BLOCK, //done
	LEFT_BRACKET, //done
	RIGHT_BRACKET, //done
	STRUCT, //done
	ENUM, //done
	DOT, //done
	COMMA, //done
	IF, //done
	ELSE, //done
	ELIF, //done
	FOR, //done
	WHILE, //done
	LOOP, //done
	CONTINUE, //done
	BREAK, //done
	GOTO, //done
	ADD, //done
	ADD_EQ, //done
	SUB, //done
	SUB_EQ, //done
	STAR_EQ, //done
	DIV, //done
	DIV_EQ, //done
	MOD, //done
	MOD_EQ, //done
	ASSIGN, //done
	EQUAL, //done
	GREATER, //done
	LESS, //done
	GREATER_EQ, //done
	LESS_EQ, //done
	AND, //done
	OR, //done
	NOT, //done
	NOT_EQ, //done
	NAME,
	NUMBER, //done
	STRING, //done
	SEMICOLON //done

} Identifier;

typedef struct Token {
	int id;
	int line;
    Identifier identifier;
	CharList *text;
} token;

#endif
