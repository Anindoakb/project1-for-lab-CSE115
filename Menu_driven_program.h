#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

int main_menu() {
    system("clear"); // Clear the terminal screen in Ubuntu/Linux

    int option;
  printf("\n\n");
    printf("********************************************\n");
    printf("*        Library Management System         *\n");
    printf("********************************************\n");
    printf("\nLibrary Management System Menu:\n");
    printf("1. Add Book\n");
    printf("2. Add Patron\n");
    printf("3. Check Out Book\n");
    printf("4. Return Book\n");
    printf("5. List Books\n");
    printf("6. List Patrons\n");
    printf("7. Save Data to File\n");
    printf("8. Search Book\n");
    printf("9. Update Book Info\n");
    printf("10. Delete Book\n");
    printf("11. List Checked Out Books\n");
    printf("12. Exit\n");
    printf("Select an option: ");
    scanf("%d", &option);



    return option;
}

#endif // MENU_H_INCLUDED