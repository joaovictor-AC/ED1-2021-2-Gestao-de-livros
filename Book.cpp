#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Book.h"

struct b {
	char *title;
	char *publisher;
	int pages;
	char *author;
	char *date_release;
	int reserved;
};

Book* newBook(char *title, char *publisher, int pages, char *author, char *date_release) {
	Book *b = (Book*) malloc(sizeof(Book));
	if (b == NULL) {
		printf("Erro -- Unable to allocate memory");
		return NULL;
	}
	b->title = title;
	b->publisher = publisher;
	b->pages = pages;
	b->author = author;
	b->date_release = date_release;
	b->reserved = 0;
	
	return b;
}

char* getBookTitle(Book *b) {
	return b->title;
}

void setBookTitle(Book *b, char *title) {
	b->title = title;
}

char* getBookPublisher(Book *b) {
	return b->publisher;
}

void setBookPublisher(Book *b, char *publisher) {
	b->publisher = publisher;
}

int getBookPages(Book *b) {
	return b->pages;
}
void setBookPages(Book *b, int pages) {
	b->pages = pages;
}

char* getBookAuthor(Book *b) {
	return b->author;
}
void setBookAuthor(Book *b, char *author) {
	b->author = author;
}

char* getBookDate(Book *b) {
	return b->date_release;
}
void setBookDate(Book *b, char *date_realease) {
	b->date_release = date_realease;
}

int isBookReserved(Book *b) {
	return b->reserved;
}

void setBookReserved(Book *b, int reserved) {
	b->reserved = reserved;
}

int printBook(Book *b) {
	printf("Titulo: %s\n", getBookTitle(b));
	printf("Editora: %s\n", getBookPublisher(b));
	printf("Paginas: %d paginas\n", getBookPages(b));
	printf("Autor(a): %s\n", getBookAuthor(b));
	printf("Data de lancamento: %s\n", getBookDate(b));
	printf("Situacao: %s\n", (isBookReserved(b)) ? "Rerservado" : "Nao reservado");
}



