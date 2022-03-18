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

/*Possível alteração:
- Colocar uma estruta de dados para os livros que um cliente reservou
*/
