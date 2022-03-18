#include <stdlib.h>
#include <stdio.h>
#include "ClientBookList.h"

struct cbl {
	int index;
	Book *books[5];
};

ClientBookList* cbl_open() {
	ClientBookList *cbl = (ClientBookList*) malloc(sizeof(ClientBookList));
	cbl->index = 0;
	
	return cbl;
}
void cbl_close(ClientBookList *cbl) {
	free(cbl);
}

int addBook(ClientBookList *cbl, Book *book) {
	cbl->books[cbl->index] = book;
	cbl->index++;
	
	return 1;
}
int removeBook(ClientBookList *cbl, int pos) {
	int i = pos;
	while (i < 5) {
		cbl->books[i] = cbl->books[i+1];
		i++;
	}
	
	return 1;
}

void print(ClientBookList *cbl) {
	for (int i = 0; i < 5; i++) {
		Book *b = cbl->books[i];
		printf("%s\n", getBookTitle(b));
	}
}
