#include <stdio.h>
#include <stdlib.h>

int main() {
    char file1[100], file2[100], merged_file[100];
    FILE *fp1, *fp2, *fp3;
    char ch;

    printf("Enter the name of the first file: ");
    scanf("%s", file1);

    printf("Enter the name of the second file: ");
    scanf("%s", file2);

    printf("Enter the name of the 1  merged file: ");
    scanf("%s", merged_file);

    fp1 = fopen(file1, "r");
    if (fp1 == NULL) {
        printf("Error opening file 1.\n");
        return 1;
    }

    fp2 = fopen(file2, "r");
    if (fp2 == NULL) {
        fclose(fp1);
        printf("Error opening file 2.\n");
        return 1;
    }

    fp3 = fopen(merged_file, "w");
    if (fp3 == NULL) {
        fclose(fp1);
        fclose(fp2);
        printf("Error creating merged file.\n");
        return 1;
    }

    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp3);
    }

 
    while ((ch = fgetc(fp2)) != EOF) {
        fputc(ch, fp3);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("Files merged successfully.\n");

    return 0;
}