#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    char ch;
    FILE *file;

    printf("Enter the filename to open or create: ");
    scanf("%s", filename);

    file = fopen(filename, "r+");
    if (file == NULL) {
        printf("File not found. So creating a new file.\n");
        file = fopen(filename, "w+");
        if (file == NULL) {
            printf("Failed to create a file.\n");
            return 1;
        }
    }

    printf("Text editor commands:\n"
       "1. Read the file\n"
       "2. Write to the file\n"
       "3. Exit\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Contents of the file:\n");
            while ((ch = fgetc(file)) != EOF) {
                putchar(ch);
            }
            break;
        case 2:
            printf("Enter text to write (Ctrl+D to save and exit):\n");
            while ((ch = getchar()) != EOF) {
                fputc(ch, file);
            }
            break;
        case 3:
            printf("Exiting.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    fclose(file);
}
