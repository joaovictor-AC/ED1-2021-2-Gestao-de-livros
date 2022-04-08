#include "ReservationList.h"
#include "Book.h"

typedef struct bl BookList;

BookList* bl_open();
void bl_close(BookList *bl);

int addBook(BookList *bl, Book *b);
int removeBook(BookList *bl, char *book_title, ReservationList *rl);

Book* getBook(BookList *bl, char *book_title);
void printAllBooks(BookList *bl);
