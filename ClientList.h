#include "Client.h"

typedef struct cl ClientList;

ClientList* cl_open();
void cl_close(ClientList *cl);

int addClient(ClientList *cl, Client *c);
int removeClient(ClientList *cl, char *client_cpf);

Client* getClient(ClientList *cl);
void printAllClients(ClientList *cl);
