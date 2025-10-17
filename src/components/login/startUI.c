//Function to change the cursor position in the console screen
void gotoxy(int col, int row){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c={col,row};
    SetConsoleCursorPosition(hStdout,c);
}

//Function to display a box of login screen

void startUI(){
    //top bar
    gotoxy(42,10);
    for(int i=0; i<74; i++){
     printf("%c",205);
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
    gotoxy(68,15);
    printf("Hospital Managment System");
    //Sectional_bottom_bar
    gotoxy(42,22);
    for(int i=0; i<74; i++){
     printf("%c",196);
    }

    //Continue_under_bar
    printf("\n");
    gotoxy(68,24);
    printf("Press any key to continue!");
    getch();
}
