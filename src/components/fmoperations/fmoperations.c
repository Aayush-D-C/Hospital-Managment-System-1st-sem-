#include "addpatients.c"
#include "searchpatients.c"
#include "modifypatients.c"
#include "deletepatients.c"

char exit_choice[30];

char add_tickets[30];

struct patient_record {
    int id;
    char name[100],address[100];
    int bed_no, age, phone;
} p,q;


//Exit the program
void patient_records_exit() {
    system("cls"); // Clear the screen

    // Top bar
    gotoxy(42, 10);
    for (int i = 0; i < 74; i++) {
        printf("%c",220);
    }

    // Side bars
    for (int i = 0; i < 15; i++) {
        printf("\n");
        gotoxy(42, 11 + i);
        printf("%C",219);
        gotoxy(115, 11 + i);
        printf("%c",219);
    }

    // Bottom bar
    printf("\n");
    gotoxy(42, 26);
    for (int i = 0; i < 74; i++) {
        printf("%C",220);
    }

    // Header text for exit confirmation
    gotoxy(66, 14);
    printf("Are you sure you want to exit?");

    // Sectional bottom bar
    gotoxy(42, 17);
    for (int i = 0; i < 74; i++) {
        printf("%c",220);
    }

    // Collect the user's response
    printf("\n\n");
    gotoxy(67, 21);
    printf("Type 'yes' or 'no': ");
    scanf("%s", exit_choice); // Read user input

    // Check if the user wants to exit
    if ((strcmp(exit_choice, "yes") == 0) ||
        (strcmp(exit_choice, "YES") == 0) ||
        (strcmp(exit_choice, "Y") == 0) ||
        (strcmp(exit_choice, "y") == 0)) {
        exit(0); // Program exits
    } else {
        dashboard(); // Return to the dashboard if the user doesn't want to exit
    }
}
