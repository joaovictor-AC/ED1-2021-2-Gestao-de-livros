#include "Book.h"

typedef struct cbl ClientBookList;

ClientBookList* cbl_open();
void cbl_close(ClientBookList *cbl);

int addBookClientBookList(ClientBookList *cbl, Book *book);
int removeBookClientBookList(ClientBookList *cbl, int pos);

int cbl_len(ClientBookList *cbl);
Book* getBookClientBookList(ClientBookList *cbl, int pos);

int printClientBookList(ClientBookList *cbl);
