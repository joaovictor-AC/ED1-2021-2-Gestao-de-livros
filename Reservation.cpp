#include <stdlib.h>
#include <stdio.h>
#include "Reservation.h"

struct r {
	char* reserve_date;
	Client *client;
	Book *book;
};

Reservation* newReservation(char *reserve_date, Client *client, Book *book) {
	Reservation *r = (Reservation*) malloc(sizeof(Reservation));
	r->reserve_date = reserve_date;
	r->client = client;
	r->book = book;
	
	return r;
}

char* getReservationDate(Reservation *r) {
	return r->reserve_date;
}
void setReservationDate(Reservation *r, char *reserve_date) {
	r->reserve_date = reserve_date;
}

Client* getReservationClient(Reservation *r) {
	return r->client;
}
void setReservationClient(Reservation *r, Client *client) {
	r->client = client;
}

Book* getReservationBook(Reservation *r) {
	return r->book;
}
void setReservationBook(Reservation *r, Book *book) {
	r->book = book;
}
