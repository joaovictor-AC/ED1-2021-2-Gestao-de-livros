#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Reservation.h"

struct r {
	char* reserve_date;
	Client *client;
	Book *book;
};

Reservation* newReservation(Client *client, Book *book) {
	
  	char *str = (char*) malloc(sizeof(char));
  	
	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	
  	int day = tm.tm_mday;
  	int month = tm.tm_mon + 1;
  	int year = tm.tm_year + 1900;
  	
  	sprintf(str, "%02d/%02d/%d", day, month, year);
			
	Reservation *r = (Reservation*) malloc(sizeof(Reservation));
	r->reserve_date = str;
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

void printReservation(Reservation *r) {
	printf("Data da reserva: %s\n", getReservationDate(r));
	printf("Cliente: %s\n", getClientName(getReservationClient(r)));
	printf("Livro Reservado: %s\n", getBookTitle(getReservationBook(r)));
	printf("\n");
}
