#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include"login.h"
#include"menu_driven_program.h"
#include"splash_screen.h"

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

void return_book()
{
    int bookID;
    printf("Enter Book ID for return: ");
    scanf("%d", &bookID);

    if (bookID < 1 || bookID > library.bookCount)
    {
        printf("Invalid book ID.\n");
    }
    else if (library.books[bookID - 1].available)
    {
        printf("The book is already available in the library.\n");
    }
    else
    {
        library.books[bookID - 1].available = true;
        printf("Book returned successfully!\n");
    }
}

void list_books()
{
    printf("List of Books:\n");
    for (int i = 0; i < library.bookCount; i++)
    {
        printf("ID: %d, Title: %s, Author: %s, Available: %s\n", i + 1, library.books[i].title, library.books[i].author,
               library.books[i].available ? "Yes" : "No");
    }
}

void list_patrons()
{
    printf("List of Patrons:\n");
    for (int i = 0; i < library.patronCount; i++)
    {
        printf("Name: %s\n", library.patrons[i].name);
    }
}

void save_data_to_file()
{
    FILE* file = fopen(fileName, "w");
    if (file != NULL)
    {
        // Save book data
        fprintf(file, "Books:\n");
        for (int i = 0; i < library.bookCount; i++)
        {
            fprintf(file, "Title: %s, Author: %s, Available: ", library.books[i].title, library.books[i].author);

            if (library.books[i].available)
            {
                fprintf(file, "Yes\n");
            }
            else
            {
                fprintf(file, "No\n");
            }
        }


        // Save patron data
        fprintf(file, "\nPatrons:\n");
        for (int i = 0; i < library.patronCount; i++)
        {
            fprintf(file, "Name: %s\n", library.patrons[i].name);
        }

        fclose(file);
        printf("Data saved to %s\n", fileName);
    }
    else
    {
        printf("Error: Unable to save data to file.\n");
    }
}

void search_book()
{
    printf("Enter the title to search: ");
    char search_title[100];
    gets(search_title);
    gets(search_title);

    int found = 0;  // Flag to track if a matching book is found

    printf("Search Results:\n");
    recursive_search_by_title(0, search_title, &found);

    if (!found)
    {
        printf("No books found with the specified title.\n");
    }
}

void recursive_search_by_title(int current, const char* search_title, int* found)
{
    if (current >= library.bookCount)
    {
        return;
    }

    if (strstr(library.books[current].title, search_title) != NULL)
    {
        printf("Title: %s, Author: %s, Available: %s\n", library.books[current].title, library.books[current].author,
               library.books[current].available ? "Yes" : "No");
        *found = 1;  // Set the flag to indicate a match was found
    }

    recursive_search_by_title(current + 1, search_title, found);
}

void update_book_info()
{
    int bookID;
    printf("Enter Book ID for updating information: ");
    scanf("%d", &bookID);

    if (bookID < 1 || bookID > library.bookCount)
    {
        printf("Invalid book ID.\n");
        return;
    }

    struct Book* book = &library.books[bookID - 1];

    printf("Current Book Information:\n");
    printf("Title: %s, Author: %s, Available: %s\n", book->title, book->author, book->available ? "Yes" : "No");

    printf("Enter New Title: ");
    gets(book->title);
    gets(book->title);
    printf("Enter New Author: ");
    gets(book->author);

    printf("Book information updated successfully!\n");
}

void delete_book()
{
    int bookID;
    printf("Enter Book ID for deletion: ");
    scanf("%d", &bookID);

    if (bookID < 1 || bookID > library.bookCount)
    {
        printf("Invalid book ID.\n");
        return;
    }

    printf("Deleted Book Information:\n");
    printf("Title: %s, Author: %s, Available: %s\n", library.books[bookID - 1].title,
           library.books[bookID - 1].author, library.books[bookID - 1].available ? "Yes" : "No");

    // Shift the books in the array to fill the gap
    for (int i = bookID; i < library.bookCount; i++)
    {
        library.books[i - 1] = library.books[i];
    }

    library.bookCount--;

    printf("Book deleted successfully!\n");
}

void list_checked_out_books()
{
    printf("List of Checked Out Books:\n");
    for (int i = 0; i < library.bookCount; i++)
    {
        if (!library.books[i].available)
        {
            printf("Title: %s, Author: %s, Available: No\n", library.books[i].title, library.books[i].author);
        }
    }
}

void load_data_from_file()
{
    FILE* file = fopen(fileName, "r");
    if (file != NULL)
    {
        char line[256];
        int inBooksSection = 0;  // Flag to track if we are in the "Books" section

        while (fgets(line, sizeof(line), file) != NULL)
        {
            if (strstr(line, "Books:") != NULL)
            {
                inBooksSection = 1;
            }
            else if (strstr(line, "Patrons:") != NULL)
            {
                inBooksSection = 0;  // Switch to the "Patrons" section
            }
            else
            {
                if (inBooksSection)
                {
                    // Read book data
                    struct Book book;
                    if (sscanf(line, "Title: %99[^,], Author: %99[^,], Available: %s", book.title, book.author, line) == 3)
                    {
                        book.available = (strcmp(line, "Yes") == 0);
                        library.books[library.bookCount] = book;
                        library.bookCount++;
                    }
                }
                else
                {
                    // Read patron data
                    if (sscanf(line, "Name: %99[^\n]", library.patrons[library.patronCount].name) == 1)
                    {
                        library.patronCount++;
                    }
                }
            }
        }

        fclose(file);
        printf("Data loaded from %s\n", fileName);
    }
    else
    {
        printf("No data file found. Starting with an empty library.\n");
    }
}
int main(void)
{
    library.bookCount = 0;
    library.patronCount = 0;
    load_data_from_file();
    splash_screen();

    bool islogged=login();


    while (islogged)
    {


        int option=main_menu();

        switch (option)
        {
        case 1:
            add_new_book();
            break;
        case 2:
            add_new_patron();
            break;
        case 3:
            check_out_book();
            break;
        case 4:
            return_book();
            break;
        case 5:
            list_books();
            break;
        case 6:
            list_patrons();
            break;
        case 7:
            save_data_to_file();
            break;
        case 8:
            search_book();
            break;
        case 9:
            update_book_info();
            break;
        case 10:
            delete_book();
            break;
        case 11:
            list_checked_out_books();
            break;
        case 12:
            printf("Exiting ............\n");
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }

        wait_for_enter();
    }

    return 0;
}
