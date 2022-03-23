#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
#include "Client.h"
#include "Reservation.h"
#include "ClientBookList.h"
#include "ClientList.h"

int main() {
	
	Client *c1 = newClient("Joao", 19, 'M', "70249281155", "28/04/2002");
	Client *c2 = newClient("Matheus", 19, 'M', "70249281154", "28/04/2002");
	Client *c3 = newClient("Joana", 19, 'M', "70249281153", "28/04/2002");
	ClientList *cl = cl_open();
	addClient(cl, c1);
	addClient(cl, c2);
	addClient(cl, c3);
		
	
	int ans;

	printf("1 - Lista de clientes\n");
	printf("2 - Lista de livros\n");
	printf("3 - Lista de reservas\n");
	printf("4 - Receber livro\n");
	printf("0 - Sair\n");

	scanf("%d", &ans);
	
	switch (ans) {
		case 1:
			system("cls");
			printf("1 - Listar todos os clientes\n");
			printf("2 - Consultar cliente\n");
			printf("3 - Criar Cliente\n");
			printf("4 - Remover Cliente\n");
			printf("0 - Voltar\n");
			
			scanf("%d", &ans);
			
			switch (ans) {
				case 1:
					printAllClients(cl);
					break;
				
				case 2:
					getClient(cl);
					break;
			
				case 3:
					break;
			
				case 4:
					break;
			
				default:
					break;
			}
			
			break;
			
		case 2:
			break;
			
		case 3:
			break;
			
		case 4:
			break;
			
		case 0:
			break;
			
		default:
			break;
	}		
}
