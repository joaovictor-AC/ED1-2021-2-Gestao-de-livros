#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BookList.h"

typedef struct e {
	Book *b;
	struct e *prox;
} Node;

struct bl  {
	int index;
	Node *head;
};

BookList* bl_open() {
	BookList *bl = (BookList*) malloc(sizeof(BookList));
	if (bl == NULL) {
		printf("Erro -- Unable to allocate memory");
		return NULL;
	}
	bl->head = NULL;
	bl->index = 0;
	
	return bl;
}

void bl_close(BookList *bl) {
	
	if (bl != NULL) {
		Node *node_aux;
		while (bl->head == NULL) {
			node_aux = bl->head;
			bl->head = bl->head->prox;
			free(node_aux);
		}
		free(bl);
	}
}

int addBook(BookList *bl, Book *b) {
	if (bl == NULL) return 0;
	Node *node_aux = bl->head;
	
	Node *node = (Node*) malloc(sizeof(Node));
	node->b = b;
	node->prox = NULL;
	
	if (node_aux == NULL) {
		node_aux = node;
		bl->head = node_aux;
	} else {
		while (node_aux->prox != NULL) {
			if (strcmp(getBookTitle(node_aux->b),getBookTitle(b)) == 0) {
				printf("Esse livro ja foi cadastrado\n");
				return 0;
			}
			node_aux = node_aux->prox;
		}
		node_aux->prox = node;
	}
	
	bl->index++;
	return 1;

}

int removeBook(BookList *bl, char *book_title) {
	if (bl == NULL || bl->head == NULL) return 0;
	Node *node_ant, *node_aux = bl->head;
	
	while (node_aux != NULL && strcmp(getBookTitle(node_aux->b), book_title) != 0) {
		node_ant = node_aux;	
		node_aux = node_aux->prox;
	}
	
	if (node_aux == NULL)
		return 0;
	
	if (node_aux == bl->head)
		bl->head = node_aux->prox;
	else
		node_ant->prox = node_aux->prox;
	
	free(node_aux->b);
	free(node_aux);
	
	bl->index--;
	return 1;
}


int getBook(BookList *bl, char *book_title) {
	Node *node = bl->head;
			
	while (node != NULL && strcmp(book_title, getBookTitle(node->b)) != 0)
		node = node->prox;
				
	if (node == NULL)
		return 0;
	else
		printBook(node->b);
	
	return 1;
	
}

void printAllBooks(BookList *bl) {
	Node *node_aux = bl->head;
	int i = 1;
	while (node_aux != NULL) {
		printf("#%d\n", i);
		printBook(node_aux->b);
		printf("\n");
		node_aux = node_aux->prox;
		i++;
	}
}











