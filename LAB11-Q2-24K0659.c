#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[50], content[100];
    int choice;

    printf("Enter the filename: ");
    scanf("%s", filename);

    while (1) {
        printf("\nChoose an action:\n");
        printf("1. Write new content\n");
        printf("2. Append content\n");
        printf("3. Read content\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fp = fopen(filename, "w");
                if (fp == NULL) {
                    printf("Error opening file.\n");
                    exit(1);
                }
                printf("Enter content to write: ");
                scanf("%s", content);
                fprintf(fp, "%s\n", content);
                fclose(fp);
                break;

            case 2:
                fp = fopen(filename, "a");
                if (fp == NULL) {
                    printf("Error opening file.\n");
                    exit(1);
                }
                printf("Enter content to append: ");
                scanf("%s", content);
                fprintf(fp, "%s\n", content);
                fclose(fp);
                break;

            case 3:
                fp = fopen(filename, "r");
                if (fp == NULL) {
                    printf("Error opening file.\n");
                    exit(1);
                }
                printf("File content:\n");
                while (fgets(content, 100, fp) != NULL) {
                    printf("%s", content);
                }
                fclose(fp);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}