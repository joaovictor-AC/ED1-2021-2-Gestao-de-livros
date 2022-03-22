#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClientList.h"

typedef struct e {
	Client *c;
	struct e *prox;
} Node;

struct cl  {
	int index;
	Node *head;
};

ClientList* cl_open() {
	ClientList *cl = (ClientList*) malloc(sizeof(ClientList));
	if (cl == NULL) {
		printf("Erro -- Unable to allocate memory");
		return NULL;
	}
	cl->head = NULL;
	cl->index = 0;
	
	return cl;
}

void cl_close(ClientList *cl) {
	if (cl != NULL) {
		Node *node_aux;
		while (cl->head == NULL) {
			node_aux = cl->head;
			cl->head = cl->head->prox;
			free(node_aux);
		}
		free(cl);
	}
}

int addClient(ClientList *cl, Client *c) {
	if (cl == NULL) return 0;
	Node *node_aux = cl->head;
	Node *node = (Node*) malloc(sizeof(Node));
	node->c = c;
	node->prox = NULL;
	
	while (node_aux != NULL)
		node_aux = node_aux->prox;
		
	node_aux->prox = node;
	
	return 1;
}

int removeClient(ClientList *cl, char *client_cpf) {
	if (cl == NULL || cl->head == NULL) return 0;
	Node *node_ant, *node_aux = cl->head;
	
	while (node_aux != NULL || strcmp(getClientCpf(node_aux->c), client_cpf) != 0) {
		node_ant = node_aux;	
		node_aux = node_aux->prox;
	}
		
	if (node_aux == NULL){
		printf("Erro -- Cliente nao encontrado.\n");
		return 0;
	}
	
	if (node_aux == cl->head)
		cl->head = node_aux->prox;
	else
		node_ant->prox = node_aux->prox;
	
	free(node_aux->c);
	free(node_aux);
	
	return 1;
}

void printAllClients(ClientList *cl) {
	Node *node_aux = cl->head;
	Client *c = node_aux->c;
	while (node_aux != NULL) {
		printf("%s - %d anos - %c - %s - %s\n", getClientName(c), getClientAge(c), getClienSex(c), getClientCpf(c), getClientDate(c));
		node_aux = node_aux->prox;
	}
}


