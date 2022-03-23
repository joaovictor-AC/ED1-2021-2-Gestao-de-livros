#include "ClientBookList.h"

typedef struct c Client;

Client* newClient(char *name, int age, char sex, char *cpf, char *birth_date);

char* getClientName(Client *c);
void setClientName(Client *c, char *name);

int getClientAge(Client *c);
void setClientAge(Client *c, int age);

char getClienSex(Client *c);
void setClientSex(Client *c, char sex);

char* getClientCpf(Client *c);
void setClientCpf(Client *c, char* cpf);

char* getClientDate(Client *c);
void setClientDate(Client *c, char* birth_date);

int getClientId(Client *c);
void setClientId(Client *c, int id);

ClientBookList* getClientBookList(Client *c);
void setClientBookList(Client *c, ClientBookList *cbl);

void printClient(Client *c);
