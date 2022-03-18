#include "Book.h"
typedef struct cbl ClientBookList;

ClientBookList* cbl_open();
void cbl_close(ClientBookList *cbl);

int addBook(ClientBookList *cbl, Book *book);
int removeBook(ClientBookList *cbl, int pos);

void print(ClientBookList *cbl);
