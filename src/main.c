/*
* BagelCode
*/

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "token.h"
#include "charlist.h"

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

	fclose(fp);

	return list;
}

int main() {

	CharList * list = readFile("C:/Users/Alex/Documents/C/BagelCode/code/test.bc");
	c_NodeElement *n;

	for (int i = 1; i < list->size; i++){
		n = cl_getElem(list, i);
		printf("%c", n->c);
		
	}
	int c;
	c = getchar();

	return 0;
}