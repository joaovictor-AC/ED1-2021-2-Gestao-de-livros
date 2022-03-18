#include "Client.h"
#include "Book.h"
typedef struct r Reservation;

Reservation* newReservation(char *reserve_date, Client *client, Book *book);

char* getReservationDate(Reservation *r);
void setReservationDate(Reservation *r, char *reserve_date);

Client* getReservationClient(Reservation *r);
void setReservationClient(Reservation *r, Client *client);

Book* getReservationBook(Reservation *r);
void setReservationBook(Reservation *r, Book *book);
