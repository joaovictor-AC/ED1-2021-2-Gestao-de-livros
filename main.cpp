#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Book.h"
#include "Client.h"
#include "Reservation.h"
#include "ClientBookList.h"
#include "ClientList.h"
#include "BookList.h"
#include "ReservationList.h"

// Validação de data
int validDate(int dd, int mm, int yy) {
	if(yy>=1900 && yy<=9999) {
        if(mm>=1 && mm<=12) {
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                return 1;
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                return 1;
            else if((dd>=1 && dd<=28) && (mm==2))
                return 1;
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                return 1;
            else {
                printf("Dia invalido.\n");
            	return 0;
			}
        }
        else {
            printf("Mes invalido.\n");
            return 0;
        }
    }
    else {
        printf("Ano invalido.\n");
        return 0;
    }
}

// Criar cliente
Client *createClient() {					
	getchar();
	char *nome = (char*) malloc(sizeof(char));
	char *cpf = (char*) malloc(sizeof(char));
	char *data = (char*) malloc(sizeof(char));
	int idade;
	char sexo;
	
	printf("Digite as seguintes informacoes do cliente.\n");
	printf("Nome: ");
	scanf("%[^\n]s", nome);
	while (1) {
		printf("CPF: ");
		scanf("%s", cpf);
							
		if (strlen(cpf) != 11) {
			printf("CPF invalido\n");
			continue;
		}
							
		break;					
	}
	
	printf("Idade: ");
	scanf("%d", &idade);
	while (1) {
		char day[10], month[2], year[4];
		printf("Data de nascimento (dd/MM/YYYY): ");
		scanf("%s", data);
		strncpy(day, data, 2);
		strncpy(month, data + 3, 5);
		strncpy(year, data + 6, 10);
		
		if (!validDate(atoi(day), atoi(month), atoi(year)) || data[2] != '/' || data[5] != '/') {
			printf("Data invalida\n");
			continue;
		}
					
		break;
							
	}
						
	getchar();
						
	while (1) {
		printf("Sexo (Masculino-M // Feminino - F): ");
		scanf("%c", &sexo);
														
		if (toupper(sexo) != 'M' && toupper(sexo) != 'F') {
			printf("Comando invalido\n");
			continue;
		}
							
		break;
							
	}
						
	Client *c = newClient(nome, idade, sexo, cpf, data);
				
	return c;
}

// Criar livro
Book *createBook() {
	
	int pages;
	char *title = (char*) malloc(sizeof(char));
	char *publisher = (char*) malloc(sizeof(char));
	char *author = (char*) malloc(sizeof(char));
	char *date = (char*) malloc(sizeof(char));
					
	getchar();
						
	printf("Digite as seguintes informacoes do livro.\n");
	printf("Titulo: ");
	scanf("%[^\n]s", title);
	getchar();
	printf("Editora: ");
	scanf("%[^\n]s", publisher);
	printf("Quantidade de paginas: ");
	scanf("%d", &pages);
							
	while (1) {
		char day[10], month[2], year[4];
		printf("Data de lancamento (dd/MM/YYYY): ");
		scanf("%s", date);
		strncpy(day, date, 2);
		strncpy(month, date + 3, 5);
		strncpy(year, date + 6, 10);
							
		if (!validDate(atoi(day), atoi(month), atoi(year)) || date[2] != '/' || date[5] != '/') {
			printf("Data invalida\n");
			continue;
		}
							
		break;
							
	}
							
							
	getchar();
	printf("Autor(a): ");
	scanf("%[^\n]s", author);
						
	Book *b = newBook(title, publisher, pages, author, date);
	
	return b;
	
}

// Criar reserva
Reservation *createReservation(ClientList *cl, BookList *bl) {
	Client *c;
	Book *b;
							
	char client_cpf[100], book_title[100];
							
	printf("Digite as seguintes informacoes da reserva.\n");
							
	while (1) {
		getchar();
		printf("CPF do cliente: ");
		scanf("%[^\n]s", &client_cpf);
		c = getClient(cl, client_cpf);
		if (c == NULL) {	
		printf("Cliente nao encontrado\n");
		continue;
		}
	
		break;
	}
							
							
	while (1) {
								
		getchar();
							
		printf("Nome do livro: ");
		scanf("%[^\n]s", &book_title);
		b = getBook(bl, book_title);
		if (b == NULL) {
			printf("Livro nao encontrado\n");
			continue;
		}
		
		break;
	}
	
	Reservation *r = newReservation(c, b);
	
	return r;
}

int main() {
	
	// Criando listas
	
	ClientList *cl = cl_open();
	BookList *bl = bl_open();
	ReservationList *rl = rl_open();
	
	
	// Cliente, livros e reservas já cadastradas
	
	Client *c1 = newClient("Joao", 19, 'M', "70249281155", "28/04/2002");
	Client *c2 = newClient("Matheus", 19, 'M', "70249281154", "28/04/2002");
	Client *c3 = newClient("Joana", 19, 'M', "70249281153", "28/04/2002");


	Book *b1 = newBook("Harry Potter", "ABC", 190, "JK Rowling", "28/02/1988");
	Book *b2 = newBook("Senhor dos Aneis", "ABC", 190, "JK Rowling", "28/02/1988");
	Book *b3 = newBook("Diario de um banana", "ABC", 190, "JK Rowling", "28/02/1988");
	Book *b4 = newBook("Sangue de tinta", "ABC", 190, "JK Rowling", "28/02/1988");
	Book *b5 = newBook("Primo rico e primo pobre", "ABC", 190, "JK Rowling", "28/02/1988");
	Book *b6 = newBook("Divina comedia", "ABC", 190, "JK Rowling", "28/02/1988");

	addBook(bl, b1);
	addBook(bl, b2);
	addBook(bl, b3);
	addBook(bl, b4);
	addBook(bl, b5);
	addBook(bl, b6);
	
	addClient(cl, c1);
	addClient(cl, c2);
	addClient(cl, c3);
		
 	Reservation *r1 = newReservation(c1, b1);
 	Reservation *r2 = newReservation(c1, b2);
 	Reservation *r3 = newReservation(c1, b3);
 	Reservation *r4 = newReservation(c1, b4);
 	Reservation *r5 = newReservation(c1, b5);
 	
 	addReservation(rl, r1);
 	addReservation(rl, r2);
 	addReservation(rl, r3);
 	addReservation(rl, r4);
 	addReservation(rl, r5);
 
	int ans_principal;

	while (1) {
		
		
		printf("1 - Lista de clientes\n");
		printf("2 - Lista de livros\n");
		printf("3 - Lista de reservas\n");
		printf("0 - Sair\n");
	
		scanf("%d", &ans_principal);
		system("cls");

		switch (ans_principal) {
			case 1:{
				int ans = -1;
				while (ans != 0) {
				
				printf("1 - Listar todos os clientes\n");
				printf("2 - Consultar cliente\n");
				printf("3 - Criar Cliente\n");
				printf("4 - Remover Cliente\n");
				printf("0 - Voltar\n");
				
				scanf("%d", &ans);
				
				switch (ans) {
					// Imprimir todos os clientes na lista
					case 1:
						printAllClients(cl);
						break;
					
					// Procurar um cliente na nossa lista
					case 2:{						
						char cpf[11];
						printf("Digite o cpf do cliente a ser consultado: ");
						scanf("%s", &cpf);
						
						Client *c = getClient(cl, cpf);
						
						if (c == NULL)
							printf("Cliente nao foi encontrado\n");
						else
							printClient(c);
						break;
					}
				
					// Adicionar um cliente na nossa lista
					case 3:{

						Client *c = createClient();
						
						if (!addClient(cl, c)) {
							printf("Erro ao adicionar o cliente\n");
							free(c);
						} else {
							printf("Cliente adicionado com sucesso\n");
						}
						
						break;
					}
		
					// Remover um cliente na nossa lista
					case 4:{
						char cpf[11];
						printf("Digite o cpf do cliente a ser removido: ");
						scanf("%s", &cpf);
						
						if (removeClient(cl, cpf, rl))
							printf("Cliente removido com sucesso\n");
						else
							printf("Cliente nao foi encontrado\n");
						
						break;
					}
					
					// Voltar para o menu principal
					case 0:
						printf("Voltando para menu principal!\n");
					break;
				
				
					// O usuário digitou um comando invalido
					default:
						printf("Comando invalido\n");
						break;
				}
				
				system("pause");
				system("cls");
			}
				break;
			}
				
			case 2:{
				int ans = -1;
				while (ans != 0) {
				
					printf("1 - Listar todos os livros\n");
					printf("2 - Consultar livro\n");
					printf("3 - Adicionar Livro\n");
					printf("4 - Remover Livro\n");
					printf("0 - Voltar\n");
					
					scanf("%d", &ans);
				
					switch (ans) {
						// Imprimir todos os livros da nossa lista
						case 1:
							printAllBooks(bl);
							break;
					
						// Procurar um livro da nossa lista
						case 2:{
							getchar();
							char title[100];
							printf("Digite o titulo do livro a ser consultado: ");
							scanf("%[^\n]s", &title);
						
							Book *b = getBook(bl, title);
						
							if (b == NULL)
								printf("Livro nao foi encontrado\n");
							else
								printBook(b);
							
							break;
						}
				
						// Adicionar um livro na nossa lista
						case 3:{
							
							Book *b = createBook();
							
							if (addBook(bl, b))
								printf("Livro adicionado com sucesso\n");
							else {
								printf("Erro ao adicionar o livro\n");
								free(b);
							}
						
							break;
						}
		
						// Remover um livro da nossa lista
						case 4:{
							getchar();
							char title[100];
							printf("Digite o titulo do livro a ser removido: ");
							scanf("%[^\n]s", &title);
						
							if (removeBook(bl, title, rl))
								printf("Livro removido com sucesso\n");
							else
								printf("Livro nao foi encontrado\n");
						
							break;
						}
					
						// Voltar para o menu principal
						case 0:
							printf("Voltando para menu principal!\n");
						break;
				
						//O usuário digitou um comando invalido
						default:
							printf("Comando invalido\n");
							break;
					}
				
					system("pause");
					system("cls");
					
				}
				break;
			}
				
			case 3:{
				int ans = -1;
				while (ans != 0) {
				
					printf("1 - Listar todas as reservas\n");
					printf("2 - Consultar reserva\n");
					printf("3 - Adicionar reserva\n");
					printf("4 - Remover reserva\n");
					printf("0 - Voltar\n");
					
					scanf("%d", &ans);
				
					switch (ans) {
						
						// Imprimir todas as reservas da nossa lista
						case 1:
							printAllReservations(rl);
							break;
					
						// Procurar uma reserva na nossa lista
						case 2:{
							getchar();
							
							char cpf[11];
							char title[100];
							
							printf("Digite o cpf do cliente: ");
							scanf("%s", cpf);
							
							getchar();
							
							printf("Digite o nome do livro: ");
							scanf("%[^\n]s", title);
							
							Client *c = getClient(cl, cpf);
							Book *b = getBook(bl, title);
							
							if (c == NULL) {
								printf("Cliente nao encontrado\n");
								break;
							} else if (b == NULL) {
								printf("Livro nao encontrado\n");
								break;
							}
							
							Reservation *r = getReservation(rl, b);
							
							if (r == NULL)
								printf("Reserva nao encontrada\n");
							else {
								printf("\n");	
								printReservation(r);
							}
							break;
						}
				
						// Adicionar uma reserva na nossa lista
						case 3:{
							
							Reservation *r = createReservation(cl, bl);
							 
							if (!addReservation(rl, r))
								printf("Erro ao adicionar a reserva\n");
							else
								printf("Reserva adicionado com sucesso\n");
							
							break;
							
						}
		
						// Remover uma reserva na nossa lista
						case 4:{
							getchar();
							
							char cpf[100];
							
							printf("Digite o cpf do cliente: ");
							scanf("%[^\n]s", cpf);
							
							Client *c = getClient(cl, cpf);
							
							if (c == NULL) {
								printf("Cliente nao encontrado\n");
								break;
							}
							
								
							int ans;
							printf("Qual livro vai ser devolvido: ");
							printf("\n");
							
							int i = 0;
							
							if (cbl_len(getClientBookList(c)) > 0) {
								
								while (i < cbl_len(getClientBookList(c))) {
									printf("%d - %s\n", i+1, getBookTitle(getBookClientBookList(getClientBookList(c), i+1)));
									i++;
								}
								
								scanf("%d", &ans);
							} else {
								printf("Lista vazia\n");
								break;
							}
							
							if(!removeReservation(rl, c, ans))
								printf("Erro ao remover reserva\n");
							else
								printf("Reserva removida com sucesso\n");
							
						}
						
						// Voltar para o menu principal
						case 0:
							printf("Voltando para menu principal!\n");
						break;
				
						// O usuário digitou um comando invalido
						default:
							printf("Comando invalido\n");
							break;
					}
				
					system("pause");
					system("cls");
					
				}
				break;
			}
			
			// Fechar o programa
			case 0:
				printf("Programa finalizado");
				cl_close(cl);
				rl_close(rl);
				bl_close(cl);
				
				exit(0);
				break;
				
			default:
				break;
		}		
	}

}
