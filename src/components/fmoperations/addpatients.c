//For tickets -------->  Add patients
void add_ticket(){
    FILE *fptr;
   fptr = fopen("patient_record.txt", "a+");


   //Box for Add function

   // Top bar
   gotoxy(42, 10);
   for (int i = 0; i < 74; i++) {
       printf("%c",205);
   }

   // Side bars
   for (int i = 0; i < 28; i++) {
       printf("\n");
       gotoxy(42, 11 + i);
       printf("%c",186);
       gotoxy(115, 11 + i);
       printf("%c",186);
   }

   // Bottom bar
   printf("\n");
   gotoxy(42, 38);
   for (int i = 0; i < 74; i++) {
       printf("%C",205);
   }

   // Header text for exit confirmation
   gotoxy(71, 11);
   printf("Token No:%d",general_random_number%10000+1);

   // Sectional bottom bar
   gotoxy(42, 13);
   for (int i = 0; i < 74; i++) {
       printf("%c",196);
   }

   if (fptr == NULL) {
       printf("Error opening file.\n");
       exit(0);
   }
   printf ("\n");
   int id_exists = 0;
   do {
       gotoxy(48,15);
       printf("Patient ID: ");
       scanf("%d", &p.id);
       rewind(fptr);
       id_exists = 0;
       while (fread(&q, sizeof(q), 1, fptr) == 1) {
           if (p.id == q.id) {
               gotoxy(49,16);
               printf("[Similar ID found.Enter any other ID for new patient]");
               id_exists = 1;
               getch();
               system("cls");
               add_ticket();  //Recursive function to add another ticket
               break;
           }
       }
       gotoxy(43,16);
       for (int i = 0; i < 72; i++) {
           printf("-");
       }
   } while (id_exists);
   //Form display
   gotoxy(72,18);
   printf("Form Fill Up");
   //Name of patient
   gotoxy(49,21);
   printf("Enter the name: ");
   gotoxy(72,22);
   for (int i = 0; i < 40; i++) {
       printf("%c",196);
   }
   //Address
   gotoxy(49,25);
   printf("Enter the address: ");
   gotoxy(72,26);
   for (int i = 0; i < 40; i++) {
       printf("%c",196);
   }
   gotoxy(49,29);
   printf("Enter the phone number: ");

   gotoxy(73,29);
     //Number format
     printf("[+977]");

   gotoxy(72,30);
   for (int i = 0; i < 40; i++) {
       printf("%c",196);
   }
   gotoxy(49,32);
   printf("Enter the age: ");
   gotoxy(72,33);
   for (int i = 0; i < 40; i++) {
       printf("%c",196);
   }

   //Taking input in the ticket system
    gotoxy(73,21);
   scanf("%s", p.name);
    gotoxy(73,25);
   scanf("%s", p.address);
    gotoxy(80,29);
   scanf("%d", &p.phone);
    gotoxy(73,32);
   scanf("%d", &p.age);

   int bed_exists = 0;
   do {
       gotoxy(49,35);
       printf("Enter the bed number: ");
       scanf("%d", &p.bed_no);

       rewind(fptr);
       bed_exists = 0;
       while (fread(&q, sizeof(q), 1, fptr) == 1) {
           if (p.bed_no == q.bed_no) {
               gotoxy(49,33);
               printf("The bed is occupied. Allocate another bed to this patient.\n");
               bed_exists = 1;
               break;
           }
       }
   } while (bed_exists);

   fwrite(&p, sizeof(p), 1, fptr);
   fclose(fptr);
}

void patientAdd() {
   //Ticket Adding system
   add_ticket();

   //Continue adding tickets....
   printf("\n");
   gotoxy(49,51);
   printf("Do you wish to add more patients?");
   scanf("%s",add_tickets);

   //clear screen
   system("cls");

   if((strcmp(add_tickets,"Yes"))==0 || (strcmp(add_tickets,"yes"))==0 || (strcmp(add_tickets,'Y'))==0 || (strcmp(add_tickets,'y'))==0){
       system("cls");
       add_ticket();
   }
   else{
       return;
   }
}