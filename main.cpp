#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
	

	
	int ans_principal;

	while (1) {
		
		
		printf("1 - Lista de clientes\n");
		printf("2 - Lista de livros\n");
		printf("3 - Lista de reservas\n");
		printf("4 - Receber livro\n");
		printf("0 - Sair\n");
	
		scanf("%d", &ans_principal);
		system("cls");

		switch (ans_principal) {
			case 1:
				int ans1;
				while (ans1 != 0) {
				
				printf("1 - Listar todos os clientes\n");
				printf("2 - Consultar cliente\n");
				printf("3 - Criar Cliente\n");
				printf("4 - Remover Cliente\n");
				printf("0 - Voltar\n");
				
				scanf("%d", &ans1);
				
				switch (ans1) {
					case 1:
						printAllClients(cl);
						break;
					
					case 2:{						
						char cpf[11];
						printf("Digite o cpf do cliente a ser consultado: ");
						scanf("%s", &cpf);
						
						if (!getClient(cl, cpf))
							printf("Cliente nao foi encontrado");
						
						break;
					}
				
					case 3:{
						char nome[100], cpf[11], data[10];
						int idade;
						char sexo;
					
						getchar();
						
						printf("Digite as seguintes informacoes do cliente.\n");
						printf("Nome: ");
						scanf("%[^\n]s", &nome);
						printf("%s\n", nome);
						while (1) {
							printf("CPF: ");
							scanf("%s", &cpf);
							
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
							scanf("%s", &data);
							strncpy(day, data, 1);
							strncpy(month, data + 3, 5);
							strncpy(year, data + 6, 10);
							
							if (atoi(day) > 31 || atoi(day) <= 0 || atoi(month) > 12 || atoi(month) <= 0 || atoi(year) <= 0 || data[2] != '/' || data[5] != '/') {
								printf("Data invalida\n");
								continue;
							}
							
							break;
							
						}
						
						getchar();
						
						while (1) {
							printf("Sexo (Masculino-M // Feminino - F): ");
							scanf("%c", &sexo);
							
							printf("%c", toupper(sexo));
							
							if (toupper(sexo) != 'M' && toupper(sexo) != 'F') {
								printf("Comando invalido\n");
								continue;
							}
							
							break;
							
						}
						
						Client *c = newClient(nome, idade, sexo, cpf, data);
						
						if (addClient(cl, c))
							printf("Cliente adicionado com sucesso\n");
						else {
							printf("Erro ao adicionar o cliente\n");
							free(c);
						}
						
						break;
					}
		
					case 4:{
						char cpf[11];
						printf("Digite o cpf do cliente a ser removido: ");
						scanf("%s", &cpf);
						printf("%s\n", cpf);
						
						if (removeClient(cl, cpf))
							printf("Cliente removido com sucesso\n");
						else
							printf("Cliente nao foi encontrado\n");
						
						break;
					}
					
					case 0:
						printf("Voltando para menu principal!\n");
					break;
				
					default:
						printf("Comando invalido\n");
						break;
				}
				
				system("pause");
				system("cls");
			}
				break;
				
			case 2:
				int ans2;
				while (ans2 != 0) {
				
					printf("1 - Listar todos os livros\n");
					printf("2 - Consultar livro\n");
					printf("3 - Adicionar Livro\n");
					printf("4 - Remover Livro\n");
					printf("0 - Voltar\n");
					
					scanf("%d", &ans2);
				
					switch (ans2) {
						case 1:
							printAllClients(cl);
							break;
					
						case 2:{						
							char cpf[11];
							printf("Digite o cpf do cliente a ser consultado: ");
							scanf("%s", &cpf);
						
							if (!getClient(cl, cpf))
								printf("Cliente nao foi encontrado");
						
							break;
						}
				
						case 3:{
							char nome[100], cpf[11], data[10];
							int idade;
							char sexo;
					
							getchar();
						
							printf("Digite as seguintes informacoes do cliente.\n");
							printf("Nome: ");
							scanf("%[^\n]s", &nome);
							printf("%s\n", nome);
							printf("CPF: ");
							scanf("%s", &cpf);
							printf("Idade: ");
							scanf("%d", &idade);
							printf("Data de nascimento (dd/MM/YYYY): ");
							scanf("%s", &data);
							getchar();
							printf("Sexo (Masculino-M // Feminino - F): ");
							scanf("%c", &sexo);
						
							Client *c = newClient(nome, idade, sexo, cpf, data);
						
							if (addClient(cl, c))
								printf("Cliente adicionado com sucesso\n");
							else {
								printf("Erro ao adicionar o cliente\n");
								free(c);
							}
						
							break;
						}
		
						case 4:{
							char cpf[11];
							printf("Digite o cpf do cliente a ser removido: ");
							scanf("%s", &cpf);
							printf("%s\n", cpf);
						
							if (removeClient(cl, cpf))
								printf("Cliente removido com sucesso\n");
							else
								printf("Cliente nao foi encontrado\n");
						
							break;
						}
					
						case 0:
							printf("Voltando para menu principal!\n");
						break;
				
						default:
							printf("Comando invalido\n");
							break;
					}
				
					system("pause");
					system("cls");
					
				}
				break;
				
			case 3:
				break;
				
			case 4:
				break;
				
			case 0:
				printf("Programa finalizado");
				exit(0);
				break;
				
			default:
				break;
		}		
	}
}
