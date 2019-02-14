/*
* BagelCode
*/

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "token.h"
#include "charlist.h"
#include "tokenlist.h"

CharList * readFile(char *filename) {

	char curr;
	FILE *fp;
	CharList *list;

	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	list = cl_newList();

	while ((curr = fgetc(fp)) != EOF) {
		cl_add(list, curr);
	}

	cl_add(list, EOF);

	fclose(fp);

	return list;
}

int main(int argc, char** argv) {
	
	printf("%s\n","aaaaaaa");
	if (argc != 2) {
		printf("Error: Incorrect amount of arguments");
	}
	CharList * list = readFile(argv[1]);
	printf("read file\n");

	c_NodeElement *n;

	for (int i = 1; i < list->size; i++){
		n = cl_getElem(list, i);
		printf("%c", n->c);
		
	}

	TokenList *tokenList = tokenize(list);
	printf("%s\n", "tokenized");
	tl_printList(tokenList);

	return 0;
}
