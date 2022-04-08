#include "Reservation.h"
#include "BookList.h"
#include "ClientBookList.h"

typedef struct rl ReservationList;

ReservationList* rl_open();
void rl_close(ReservationList *rl);

int addReservation(ReservationList *rl, Reservation *r);
int removeReservation(ReservationList *rl, Client *c);

Reservation *getReservation(ReservationList *rl, Client *c, Book *b);

void printAllReservations(ReservationList *rl);
