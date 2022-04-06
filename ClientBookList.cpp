#include <stdlib.h>
#include <stdio.h>
#include "ClientBookList.h"
#define MAX 5

struct cbl {
	int index;
	Book *books[MAX];
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

int addBookClientBookList(ClientBookList *cbl, Book *book) {
	if (cbl == NULL || cbl->index == MAX) return 0;
	setBookReserved(book, 1);
	cbl->books[cbl->index] = book;
	cbl->index++;
	
	return 1;
}
int removeBookClientBookList(ClientBookList *cbl, int pos) {
	if (cbl == NULL || pos <= 0 || pos > 5 || cbl->index <= 0) return 0;
	int i = pos-1;
	while (i < 5) {
		cbl->books[i] = cbl->books[i+1];
		i++;
	}
	
	cbl->index--;
	return 1;
}

int cbl_len(ClientBookList *cbl) {
	return cbl->index;
}

Book* getBookClientBookList(ClientBookList *cbl, int pos) {
	return cbl->books[pos-1];
}

int printClientBookList(ClientBookList *cbl) {
	if (cbl->index != 0) {
		for (int i = 0; i < cbl->index; i++) {
			Book *b = cbl->books[i];
			if (i == 0)
				printf("- %s\n", getBookTitle(b));
			else
				printf("\t\t - %s\n", getBookTitle(b));
				
		}
		printf("\n");
		return 1;
	} else {
		return 0;
	}
}




