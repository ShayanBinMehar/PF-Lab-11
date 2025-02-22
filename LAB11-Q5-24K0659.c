#include <stdio.h>
#include <stdlib.h>

int main() {
    char source_file[100], destination_file[100];
    FILE *source, *destination;
    char ch;
    char buffer[1000]; 
    int buffer_index = 0;

    printf("Enter the source file name: ");
    scanf("%s", source_file);

    printf("Enter the destination file name: ");
    scanf("%s", destination_file);

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
        buffer[buffer_index++] = ch;
    }

   
    for (int i = buffer_index - 1; i >= 0; i--) {
        fputc(buffer[i], destination);
    }

    fclose(source);
    fclose(destination);

    printf("File reversed and saved successfully.\n");

    return 0;
}