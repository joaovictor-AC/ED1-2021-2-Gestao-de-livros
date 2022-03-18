#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
#include "Client.h"

int main() {
	
	Book *b = newBook(145, "Harry Potter", "Abril", 278, "J.K Rowling", 23/02/98);
	printf("%d\n", isBookReserved(b));
	setBookReserved(b, 1);
	printf("%d\n", isBookReserved(b));
	
	Client *c = newClient("Joao Victor", 19, 'M', "702.492.811.55", "28/04/2002");
	printf("%s\n", getClientName(c));
	
}
