
void search_record() {

    //Box
    int check_id;
    printf("\nEnter the patient id: ");
    scanf("%d", &check_id);

    FILE *fptr;
    fptr = fopen("patient_record.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int found = 0;
    while (fread(&p, sizeof(p), 1, fptr) == 1) {
        if (p.id == check_id) {
            printf("Record found !!!\n");
            printf("Patient id: %d\n", p.id);
            printf("Name: %s\n", p.name);
            printf("Age: %d\n", p.age);
            printf("Phone: %d\n", p.phone);
            printf("Address: %s\n", p.address);
            printf("Bed No: %d\n", p.bed_no);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No such record found.\n");
    }

    fclose(fptr);
}