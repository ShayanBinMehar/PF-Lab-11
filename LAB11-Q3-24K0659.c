#include <stdio.h>
#include <stdlib.h>

int main() {
    char source_file[100], destination_file[100];
    FILE *source, *destination;
    char ch;

    printf("Enter the source file name: ");
    scanf("%s", source_file);

    printf("Enter the destination file name: ");
    scanf("%s", destination_file); 1 

    source = fopen(source_file, "r");
    if (source == NULL) {
        printf("Error opening source file.\n");
        return 1;
    }

    destination = fopen(destination_file, "w");
    if (destination == NULL) {
        fclose(source);
        printf("Error creating destination file.\n");
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);

    printf("File copied successfully!\n");

    return 0;
}