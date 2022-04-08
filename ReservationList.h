#include "Reservation.h"
#include "ClientBookList.h"

typedef struct rl ReservationList;

ReservationList* rl_open();
void rl_close(ReservationList *rl);

int addReservation(ReservationList *rl, Reservation *r);
int removeReservation(ReservationList *rl, Client *c, int pos);

Reservation *getReservation(ReservationList *rl, Book *b);

void printAllReservations(ReservationList *rl);
