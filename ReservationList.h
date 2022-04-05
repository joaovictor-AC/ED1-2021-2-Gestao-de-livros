#include "Reservation.h"
#include "BookList.h"

typedef struct rl ReservationList;

ReservationList* rl_open();
void rl_close(ReservationList *rl);

int addReservation(ReservationList *rl, Reservation *r);
int removeReservation(ReservationList *rl, Reservation *r. BookList *bl);

