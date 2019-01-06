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
	DEREF,
	ADDR,
	FN,
	ARROW,
	LEFT_BLOCK,
	RIGHT_BLOCK,
	LEFT_BRACKET,
	RIGHT_BRACKET,
	STRUCT,
	ENUM,
	DOT,
	COMMA,
	IF,
	ELSE,
	ELIF,
	FOR,
	WHILE,
	CONTINUE,
	GOTO,
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	ASSIGN,
	EQUAL,
	GREATER,
	LESS,
	GREATER_EQ,
	LESS_EQ,
	AND,
	OR,
	NOT,
	NOT_EQ,
	FUNCTION,
	NAME,
	NUMBER,
	STRING,
	SEMICOLON

} Identifier;

typedef struct Token {
	int id;
	int line;
    Identifier identifier;
	CharList *text;
} token;

#endif