#include <stdlib.h>
#include <stdio.h>
#include "Client.h"

struct c {
	char *name;
	int age;
	char sex;
	char *cpf;
	char *birth_date;
};

Client* newClient(char *name, int age, char sex, char *cpf, char *birth_date) {
	Client *c = (Client*) malloc(sizeof(Client));
	c->name = name;
	c->age = age;
	c->sex = sex;
	c->cpf = cpf;
	c->birth_date = birth_date;
	
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
void setClientDate(Client *c, char* birth_date) {
	c->birth_date = birth_date;
}
