#include <stdio.h>

int main() {
    FILE *fp;
    char filename[50], ch;
    int characters = 0, words = 0, lines = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        characters++;
        if (ch == ' ') {
            words++;
        }
        if (ch == '\n') {
            lines++;
            words++; 
        }
    }

    fclose(fp);

    printf("Number of characters: %d\n", characters);
    printf("Number of words: %d\n", words);
    printf("Number of lines: %d\n", lines);

    return 0;
}