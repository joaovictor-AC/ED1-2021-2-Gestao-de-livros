#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
#include "Client.h"
#include "Reservation.h"
#include "ClientBookList.h"
#include "ClientList.h"

int main() {
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
					
					break;
				
				case 2:
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
