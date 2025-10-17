
void delete_record() {
    int delete_id;
    printf("\nEnter the patient id to delete: ");
    scanf("%d", &delete_id);

    FILE *fptr, *temp;
    fptr = fopen("patient_record.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fptr == NULL || temp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int found = 0;
    while (fread(&p, sizeof(p), 1, fptr) == 1) {
        if (p.id == delete_id) {
            printf("\nRecord deleted successfully.\n");
            found = 1;
        } else {
            fwrite(&p, sizeof(p), 1, temp);
        }
    }

    fclose(fptr);
    fclose(temp);

    remove("patient_record.txt");
    rename("temp.txt", "patient_record.txt");

    if (!found) {
        printf("Record not found.\n");
    }
}