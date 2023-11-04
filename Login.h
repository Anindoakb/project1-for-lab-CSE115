#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
bool isLoggedIn = false; // Flag to track login status

bool login() {
    char username[50];
    char password[50];



    // Open the file for reading
    FILE *file = fopen("adminCredentials.txt", "r");
    if (file == NULL) {
        printf("adminCredentials.txt not found. Setting up the password for the first time.\n");
      //  fclose(file); // Close any potentially open file stream
        // Prompt the user to set up a new password
        printf("Set up a new password: ");
        scanf("%s", password);
   printf("Set up a new username: ");
        scanf("%s", username);
       // scanf("%s", password);

        // Open the file for writing (create if it doesn't exist)
        file = fopen("adminCredentials.txt", "w");
        if (file == NULL) {
            printf("Error creating file.\n");
            return false;
        }

        // Write the new username and password to the file
        fprintf(file, "%s\n", username);
        fprintf(file, "%s\n", password);

        // Close the file
        fclose(file);

        printf("Password set successfully!\n");
        isLoggedIn = true; // Set login status to true
        sleep(1);
    } else {
    printf("\n\n\t\t\tLogin\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
        // Read the username and password from the file
        char fileUsername[50];
        char filePassword[50];
        fgets(fileUsername, sizeof(fileUsername), file);
        fgets(filePassword, sizeof(filePassword), file);

        // Remove the newline character at the end of the strings
        fileUsername[strcspn(fileUsername, "\n")] = '\0';
        filePassword[strcspn(filePassword, "\n")] = '\0';

        // Close the file
        fclose(file);

        // Compare the entered credentials with the file contents
        if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0) {
            printf("\nLogin successful!\n");
            isLoggedIn = true; // Set login status to true
            sleep(1);
        } else {
            printf("\nInvalid username or password. Please try again.\n");
            sleep(1);
        }
    }

    return isLoggedIn;
}

#endif // LOGIN_H_INCLUDED