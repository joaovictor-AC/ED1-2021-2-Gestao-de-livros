#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
#include "Client.h"
#include "Reservation.h"
#include "ClientBookList.h"

int main() {
	
	Book *b = newBook(145, "Harry Potter", "Abril", 278, "J.K Rowling", 23/02/98);
	printf("%d\n", isBookReserved(b));
	setBookReserved(b, 1);
	printf("%d\n", isBookReserved(b));
	
	Client *c = newClient("Joao Victor", 19, 'M', "702.492.811.55", "28/04/2002");
	printf("%s\n", getClientName(c));
	
	Reservation *r = newReservation("18/03/2022", c, b);
	Client *c1 = getReservationClient(r);
	Book *b1 = getReservationBook(r);
	printf("%s-%s-%s\n", getClientName(c1), getBookTitle(b1), getReservationDate(r));
	
	ClientBookList *cbl = cbl_open();
	addBook(cbl, b);
	addBook(cbl, b);
	addBook(cbl, b);
	addBook(cbl, b);
	addBook(cbl, b);
	
	print(cbl);
	
		
}
