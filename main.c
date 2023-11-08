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
