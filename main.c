#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include"login.h"
#include"Menu_driven_program.h"
#include"splash.h"
int main()
{
    Library.bookCount = 0;
    Library.patronCount = 0;
    load_data_from_file();
    splash_screen();

    bool islogged=login();
struct Book
{
    char title[100];
    char author[100];
    bool available;
};

struct Patron
{
    char name[100];
};

struct Library
{
    struct Book books[100];
    int bookCount;
    struct Patron patrons[100];
    int patronCount;
};

struct Library library;

char fileName[] = "Library.txt";
void add_new_book();
void add_new_patron();
void check_out_book();
void return_book();
void list_books();
void list_patrons();
void save_data_to_file();
void search_book();
void update_book_info();
void delete_book();
void list_checked_out_books();
void clear_screen();
void display_menu();
void wait_for_enter();
void recursive_search_by_title(int current, const char* search_title, int* found) ;
void load_data_from_file();

void wait_for_enter()
{
    printf("Press enter to continue...");
    while (getchar() != '\n');
    getchar();
}
void add_new_book()
{
    if (library.bookCount < 100)
    {
        struct Book book;
        printf("Enter Title: ");
        scanf(" %[^\n]", book.title);
        printf("Enter Author: ");
        scanf(" %[^\n]", book.author); // Read the entire line, including spaces
        book.available = true;
        library.books[library.bookCount] = book;
        library.bookCount++;
        printf("Book added successfully!\n");
    }
    else
    {
        printf("The library is full, cannot add more books.\n");
    }
}


void add_new_patron()
{
    if (library.patronCount < 100)
    {
        struct Patron patron;
        printf("Name: ");
        scanf(" %[^\n]", patron.name); // Read the entire line, including spaces

        library.patrons[library.patronCount] = patron;
        library.patronCount++;
        printf("Patron added successfully!\n");
    }
    else
    {
        printf("The patron list is full, cannot add more patrons.\n");
    }
}

void check_out_book()
{
    int bookID;
    printf("Enter Book ID for check out: ");
    scanf("%d", &bookID);

    if (bookID < 1 || bookID > library.bookCount)
    {  
        printf("Invalid book ID.\n");
    }
    else if (!library.books[bookID - 1].available)
    {
        printf("The book is already checked out.\n");
    }
    else
    {
        library.books[bookID - 1].available = false;
        printf("Book checked out successfully!\n");
    }
}

