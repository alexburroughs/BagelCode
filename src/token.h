#ifndef TOKEN_H
#define TOKEN_H

typedef enum Type {
    num,
    str,
    chr,
    pnt
} type;

typedef struct Token {
	int id;
    type varType;
} token;

#endif