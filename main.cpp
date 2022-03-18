#include <stdio.h>
#include <stdlib.h>
#include "Book.h"

int main() {
	
	Book *b = newBook(145, "Harry Potter", "Abril", 278, "J.K Rowling", 23/02/98);
	printf("%d\n", isBookReserved(b));
	setBookReserved(b, 1);
	printf("%d\n", isBookReserved(b));
	free(b);
	
}
