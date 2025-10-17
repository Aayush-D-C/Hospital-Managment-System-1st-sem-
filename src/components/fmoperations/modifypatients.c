void modify_record() {
    int modify_id;
    printf("\nEnter the patient id to modify: ");
    scanf("%d", &modify_id);

    FILE *fptr;
    fptr = fopen("patient_record.txt", "r+");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int found = 0;
    while (fread(&p, sizeof(p), 1, fptr) == 1) {
        if (p.id == modify_id) {
            printf("\nPlease enter the updated details.\n");
            printf("Enter patient id: ");
            scanf("%d", &p.id);
            printf("Enter name: ");
            scanf("%s", p.name);
            printf("Enter age: ");
            scanf("%d", &p.age);
            printf("Enter phone number: ");
            scanf("%d", &p.phone);
            printf("Enter address: ");
            scanf("%s", p.address);

            fseek(fptr, -sizeof(p), SEEK_CUR);
            fwrite(&p, sizeof(p), 1, fptr);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
    }

    fclose(fptr);
}