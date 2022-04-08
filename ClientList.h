#include "Client.h"
#include "ReservationList.h"

typedef struct cl ClientList;

ClientList* cl_open();
void cl_close(ClientList *cl);

int addClient(ClientList *cl, Client *c);
int removeClient(ClientList *cl, char *client_cpf, ReservationList *rl);
int samecpf(ClientList *cl, char *client_cpf);

Client* getClient(ClientList *cl,  char *client_cpf);
void printAllClients(ClientList *cl);
