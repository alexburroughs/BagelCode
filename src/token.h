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
	NUM,
	STR,
	CHR,
	PNT,
	STAR, //done
	ADDR, //done
	RET,
	FN,
	ARROW,
	LEFT_BLOCK, //done
	RIGHT_BLOCK, //done
	LEFT_BRACKET, //done
	RIGHT_BRACKET, //done
	STRUCT,
	ENUM,
	DOT,
	COMMA,
	IF,
	ELSE,
	ELIF,
	FOR,
	WHILE,
	LOOP,
	CONTINUE,
	BREAK,
	GOTO,
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
	NUMBER,
	STRING,
	SEMICOLON //done

} Identifier;

typedef struct Token {
	int id;
	int line;
    Identifier identifier;
	CharList *text;
} token;

#endif