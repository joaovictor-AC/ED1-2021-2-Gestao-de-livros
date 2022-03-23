#include <stdlib.h>
#include <stdio.h>
#include "Client.h"

struct c {
	int id;
	char *name;
	int age;
	char sex;
	char *cpf;
	char *birth_date;
	ClientBookList *bookList;
	
};

Client* newClient(char *name, int age, char sex, char *cpf, char *birth_date) {
	Client *c = (Client*) malloc(sizeof(Client));
	if (c == NULL) {
		printf("Erro -- Unable to allocate memory");
		return NULL;
	}
	c->name = name;
	c->age = age;
	c->sex = sex;
	c->cpf = cpf;
	c->birth_date = birth_date;
	c->bookList = cbl_open();
	
	return c;
}

char* getClientName(Client *c) {
	return c->name;
}
void setClientName(Client *c, char *name) {
	c->name = name;
}

int getClientAge(Client *c) {
	return c->age;
}
void setClientAge(Client *c, int age) {
	c->age = age;
}

char getClienSex(Client *c){
	return c->sex;
}
void setClientSex(Client *c, char sex) {
	c->sex = sex;
}

char* getClientCpf(Client *c) {
	return c->cpf;
}
void setClientCpf(Client *c, char* cpf) {
	c->cpf = cpf;
}

char* getClientDate(Client *c) {
	return c->birth_date;
}

int getClientId(Client *c) {
	return c->id;
}

void setClientId(Client *c, int id) {
	c->id = id;
}

void setClientDate(Client *c, char* birth_date) {
	c->birth_date = birth_date;
}

ClientBookList* getClientBookList(Client *c) {
	return c->bookList;
}
void setClientBookList(Client *c, ClientBookList *cbl) {
	c->bookList = cbl;
}

void printClient(Client *c) {
	printf("Nome: %s\n", getClientName(c));
	printf("CPF: %s\n", getClientCpf(c));
	printf("Idade: %d anos\n", getClientAge(c));
	printf("Sexo: %s\n", (getClienSex(c) == 'M') ? "Masculino" : "Feminino");
	printf("Data de nascimento: %s\n", getClientDate(c));
	// Colocar depois a lisra de livros reservados
}

