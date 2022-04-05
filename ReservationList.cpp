#include <stdlib.h>
#include <stdio.h>
#include "ReservationList.h"

typedef struct e {
	Reservation *r;
	struct e *prox;
} Node;

struct rl {
	int index;
	Node *head;
};

ReservationList* rl_open() {
	ReservationList *rl = (ReservationList*) malloc(sizeof(ReservationList));
	if (rl == NULL) {
		printf("Erro -- Unable to allocate memory");
		return NULL;
	}
	rl->head = NULL;
	rl->index = 0;
	
	return rl;
}

void rl_close(ReservationList *rl) {
		if (rl != NULL) {
		Node *node_aux;
		while (rl->head == NULL) {
			node_aux = rl->head;
			rl->head = rl->head->prox;
			free(node_aux);
		}
		free(rl);
	}
}

int addReservation(ReservationList *rl, Reservation *r) {
	if (rl == NULL) return 0;
	Node *node_aux = rl->head;
	
	Node *node = (Reservation*) malloc(sizeof(Reservation));
	node->r = r;
	node->prox = NULL;
	
	if (isBookReserved(r->book)) {
		printf("Livro ja foi reservado\!n");
		free(node);
	} else if (getClientBookList(r->client)->index == 5) {
		printf("O Cliente nao pode reserva mais livros! (maximo 5)\n");
	} else {
		setBookReserved(r->book, 1);
		addBookClientBookList(getClientBookList(r->client), r->book);
		if (node_aux == NULL) {
			node_aux = node;
			rl->head = node_aux;
		} else {
			while (node_aux->prox != NULL)
				node_aux = node_aux->prox;
				
			node_aux->prox = node;
		}
		
	}
	rl->index++;
	return 1;
}

int removeReservation(ReservationList *rl, Client *C) {
	if (rl == NULL || rl->head == NULL || getClientBookList(c)->index == 0) return 0;
	Node *node_ant, *node_aux = rl->head;
	
	int ans;
	printf("Qual livro vai ser devolvido: ");
	printClientBookList(getClientBookList(c));
	scanf("%d", &ans);
	e

	
	while (node_aux != NULL && node_aux->r->client == c ) {
		node_ant = node_aux;	
		node_aux = node_aux->prox;
	}
	
	if (node_aux == NULL)
		return 0;
	
	if (node_aux == rl->head)
		rl->head = node_aux->prox;
	else
		node_ant->prox = node_aux->prox;
	
	free(node_aux->r);
	free(node_aux);
	
	
	setBookReserved(getClientBookList(c)->books[ans-1], 0);
	removeBookClientBookList(getClientBookList(c), ans);
	rl->index--;
	return 1;
}





