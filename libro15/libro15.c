#include <stdio.h>
#include <stdlib.h>

typedef struct Book Book;
struct Book {
	int code;
	char title[30];
	char author[30];
	int pub_year;
	char editor[15];
	Book *next;
};

typedef struct {
	Book *first;
	Book *last;
} Library;

void myRead(char *str, int max);
Book* newBook();
void addBook(Library *library, Book *book);
void printBooks(Library library);
Book* getFromCode(Library *library, int book_code);
Book* getFromTitle(Library *library, char *title);
void ignore(unsigned long long n, int delim);


void main() {
	
	// First book (obligatory)
	Library library;
	library.first = library.last = newBook();
	
	// More books
	char again;
	printf("\nAdd another book? [y/n]: ");
	scanf(" %c", &again);
	while(again == 'y' || again == 'Y') {
		addBook(&library, newBook());
		printf("\nAdd another book? [y/n]: ");
		scanf(" %c", &again);
	}
	
	// Print all books
	printBooks(library);
	
	// Search book for ...
	Book *searchres;
	char str[30];
	int code;
	do {
		printf("\nCerca per:\n 1. Codice\n 2. Titolo\n");
		scanf("%d", &code);
		
		switch(code) {
			
			// ... Code
			case 1:
				printf("Inserire codice da cercare: ");
				scanf("%d", &code);
				puts("b\n");
				searchres = getFromCode(&library, code);
				puts("a\n");
				code = 0;
			break;
			
			// ... Title
			case 2:
				printf("Inserire titolo da cercare: ");
				ignore(100000, '\n');
				myRead(str, 30);
				searchres = getFromTitle(&library, str);
				code = 0;
			break;
			
			default:
				code = 1;
		}
		
	} while(code);
	
	// Search result
	if(searchres)
		printf("\nLibro trovato!\n  Codice: %d\n  Titolo: %s\n  Autore: %s\n  Anno pubblicazione: %d\n  Editore: %s\n", searchres->code, searchres->title, searchres->author, searchres->pub_year, searchres->editor);
	else
		printf("\nNessun libro trovato per il parametro indicato.\n");
}


void myRead(char *str, int max) {
	fgets(str, max, stdin);
	char *lim;
	for(lim=str+15; str<lim; str++)
		if(*str == '\n') {
			*str = '\0';
			break;
		}
}

Book* newBook() {
	Book *newbook = malloc(sizeof(Book));
	newbook->next = NULL;
	printf("Inserire codice: ");
	scanf("%d", &newbook->code);
	ignore(100000, '\n');
	printf("Inserire titolo: ");
	myRead(newbook->title, 30);
	printf("Inserire autore: ");
	myRead(newbook->author, 30);
	printf("Inserire anno pubblicazione: ");
	scanf("%d", &newbook->pub_year);
	ignore(100000, '\n');
	printf("Inserire editore: ");
	myRead(newbook->editor, 15);
	return newbook;
}

void addBook(Library *library, Book *book) {
	library->last->next = book;
	library->last = book;
}

void printBooks(Library library) {
	Book *book = library.first;
	while(book) {
		printf("\n[%d]\n  Titolo: %s\n  Autore: %s\n  Editore: %s\n  Pubblicazione: %d\n", book->code, book->title, book->author, book->editor, book->pub_year);
		book = book->next;
	}
}

Book* getFromCode(Library *library, int book_code) {
	Book *book = library->first;
	while(book) {
		printf("%d %d\n", book->code, book_code);
		if(book->code == book_code)
			return book;
		else
			book = book->next;
	}
	return NULL;
}

Book* getFromTitle(Library *library, char *title) {
	Book *book = library->first;
	while(book)
		if(!strcmp(book->title, title))
			return book;
		else
			book = book->next;
	return NULL;
}

void ignore(unsigned long long n, int delim) {
    while (n--) {
        const int c = getc(stdin);
        if(c == EOF)
           break;
        if(delim != EOF && delim == c)
           break;
    }
}
