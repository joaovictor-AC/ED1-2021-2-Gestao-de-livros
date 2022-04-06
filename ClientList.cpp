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
	
	if (node_aux == NULL) {	
		node_aux = node;
		cl->head = node_aux;
	} else {
	while (node_aux->prox != NULL) {
		if (strcmp(getClientCpf(node_aux->c),getClientCpf(c)) == 0) {
			printf("CPF ja cadastrado!\n");
			return 0;
		}
		node_aux = node_aux->prox;
	}
	node_aux->prox = node;
	}
	
	cl->index++;
	return 1;
}

int removeClient(ClientList *cl, char *client_cpf) {
	if (cl == NULL || cl->head == NULL) return 0;
	Node *node_ant, *node_aux = cl->head;
	
	while (node_aux != NULL && strcmp(getClientCpf(node_aux->c), client_cpf) != 0) {
		node_ant = node_aux;	
		node_aux = node_aux->prox;
	}
		
	if (node_aux == NULL)
		return 0;
	
	if (node_aux == cl->head)
		cl->head = node_aux->prox;
	else
		node_ant->prox = node_aux->prox;
	
	free(node_aux->c);
	free(node_aux);
	
	cl->index--;
	return 1;
}


Client* getClient(ClientList *cl,  char *client_cpf) {
	Node *node = cl->head;
			
	while (node != NULL && strcmp(client_cpf, getClientCpf(node->c)) != 0)
		node = node->prox;
	
	return (node == NULL) ? NULL : node->c;
	
}

void printAllClients(ClientList *cl) {
	Node *node_aux = cl->head;
	int i = 1;
	while (node_aux != NULL) {
		printf("#%d\n", i);
		printClient(node_aux->c);
		printf("\n");
		node_aux = node_aux->prox;
		i++;
	}
}











