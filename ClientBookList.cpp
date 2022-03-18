#include <stdlib.h>
#include <stdio.h>
#include "ClientBookList.h"

struct cbl {
	int index;
	Book *books[5];
};

ClientBookList* cbl_open() {
	ClientBookList *cbl = (ClientBookList*) malloc(sizeof(ClientBookList));
	if (cbl == NULL) {
		printf("Erro -- Unable to allocate memory");
		return NULL;
	}
	cbl->index = 0;
	
	return cbl;
}
void cbl_close(ClientBookList *cbl) {
	free(cbl);
}

int addBook(ClientBookList *cbl, Book *book) {
	if (cbl == NULL || cbl->index == 5) return 0;
	cbl->books[cbl->index] = book;
	cbl->index++;
	
	return 1;
}
int removeBook(ClientBookList *cbl, int pos) {
	if (cbl == NULL || pos <= 0 || pos > 5 || cbl->index <= 0) return 0;
	int i = pos-1;
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
