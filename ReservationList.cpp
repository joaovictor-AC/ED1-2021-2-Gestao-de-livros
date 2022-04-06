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
	
	Node *node = (Node*) malloc(sizeof(Node));
	node->r = r;
	node->prox = NULL;
	
	if (isBookReserved(getReservationBook(r))) {
		printf("Livro ja foi reservado!\n");
		free(node);
		return 0;
	} else if (cbl_len(getClientBookList(getReservationClient(r))) == 5) {
		printf("O Cliente nao pode reserva mais livros! (maximo 5)\n");
		free(node);
		return 0;
	} else {
		setBookReserved(getReservationBook(r), 1);
		addBookClientBookList(getClientBookList(getReservationClient(r)), getReservationBook(r));
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

int removeReservation(ReservationList *rl, Client *c) {
	if (rl == NULL || rl->head == NULL || cbl_len(getClientBookList(c)) == 0) return 0;
	Node *node_ant, *node_aux = rl->head;
	
	int ans;
	printf("Qual livro vai ser devolvido: ");
	printClientBookList(getClientBookList(c));
	scanf("%d", &ans);

	
	while (node_aux != NULL && getReservationClient(node_aux->r) == c ) {
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
	
	
	setBookReserved(getBookClientBookList(getClientBookList(c), ans), 0);
	removeBookClientBookList(getClientBookList(c), ans);
	rl->index--;
	return 1;
}

void printAllReservations(ReservationList *rl) {
	Node *node = rl->head;
	int i = 1;
	while (node != NULL) {
		printf("#Reserva %d\n", i);
		printf("Data da reserva: %s\n", getReservationDate(node->r));
		printf("Cliente: %s\n", getClientName(getReservationClient(node->r)));
		printf("Livro Reservado: %s\n", getBookTitle(getReservationBook(node->r)));
		printf("\n");
		node = node->prox;
		i++;
	}
}





