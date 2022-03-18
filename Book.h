typedef struct b Book;

Book* newBook(int id, char title[], char publisher[], int pages, char author[], char date_release[]);

int getBookId(Book *b);
void setBookId(Book *b, int id);

char* getBookTitle(Book *b);
void setBookTitle(Book *b, char *title);

char* getBookPublisher(Book *b);
void setBookPublisher(Book *b, char *publisher);

int getBookPages(Book *b);
void setBookPages(Book *b, int pages);

char* getBookAuthor(Book *b);
void setBookAuthor(Book *b, char *author);

char* getBookDate(Book *b);
void setBookDate(Book *b, char *date_realease);

int isBookReserved(Book *b);
void setBookReserved(Book *b, int reserved);
