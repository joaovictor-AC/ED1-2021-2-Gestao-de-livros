#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
#include "Client.h"
#include "Reservation.h"
#include "ClientBookList.h"

int main() {
	
	Book *b = newBook(145, "Harry Potter", "Abril", 278, "J.K Rowling", 23/02/98);
	setBookReserved(b, 1);
	
	Client *c = newClient("Joao Victor", 19, 'M', "702.492.811.55", "28/04/2002");
	
	Reservation *r = newReservation("18/03/2022", c, b);
	Client *c1 = getReservationClient(r);
	Book *b1 = getReservationBook(r);
	
	Book *b2 = newBook(145, "Senhor dos Aneis", "Abril", 278, "J.K Rowling", 23/02/98);

	addBook(getClientBookList(c), b);
	addBook(getClientBookList(c), b);
	addBook(getClientBookList(c), b);
	addBook(getClientBookList(c), b);
	addBook(getClientBookList(c), b2);
	removeBook(getClientBookList(c), 1);
	
	
	print(getClientBookList(c));
	
		
}
