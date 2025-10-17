//Variable decleration
char e_id[30];

char e_pass[30];

//Hard Coded ID and Password
//Contains name for all our project members

char id[8][100] = {"Aayush", "Sahaj", "Abhiyan", "Anshu", "Aarus", "Kaushal", "Binod", "Aashutosh"};

char pass[8][20] = {"000", "001", "002", "003", "004", "005", "006", "007"};

void loginUI(){
    //top bar
    system("cls");  //Clear the screen
    gotoxy(42,10);  //Change the cursor position
    for(int i=0; i<74; i++){
     printf("%c",205);  //Print the top bar
    }

    //Side bars
    for(int i=0; i<15; i++){
        printf("\n");
        gotoxy(42,11+i);
        printf("%c",186);
        gotoxy(115,11+i);
        printf("%c",186);
    }

    //Bottom Bars
    printf("\n");
    gotoxy(42,26);
    for(int i=0; i<74; i++){
     printf("%c",205);
    }

    //Header_Under_bar
    gotoxy(76,11);
    printf("Login");

    //Sectional_Bottom_Bar
    gotoxy(42,13);
    for(int i=0; i<74; i++){
     printf("%c",196);
    }

    loginUser();
}

void underLine(){
    //Continue_under_bar
    printf("\n");
    gotoxy(58,17);
    printf("ID:");
    gotoxy(62,18);
    printf("-----------------------------");

    printf("\n");
    gotoxy(58,22);
    printf("Pass:");
    gotoxy(63,23);
    printf("-----------------------------");
}

    void loginUser(){
    underLine();

    gotoxy(63,17);
    scanf("%s",e_id);

    gotoxy(64,22);
    scanf("%s",e_pass);

     for (int i = 0; i < 8; i++) {
        //Compare the entered password and id with the hard coded password and id
        if (strcmp(e_pass, pass[i]) == 0 && strcmp(e_id, id[i]) == 0) {
            return;  //Return to the dashboard
        }
    }
    // Login failed
    gotoxy(58,25);
    printf("Login failed. Incorrect ID or password.\n");
    getch();

    //A concept of recursive function
    loginUI();
    }


