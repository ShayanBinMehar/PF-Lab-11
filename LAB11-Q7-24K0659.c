#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_PRODUCT_NAME_LEN 50

struct Product {
    int id;
    char name[MAX_PRODUCT_NAME_LEN];
    float price;
    int quantity;
};

void addProduct(FILE *fp, struct Product product) {
    fprintf(fp, "%d,%s,%.2f,%d\n", product.id, product.name, product.price, product.quantity);
}

void appendData(FILE *fp, int productId, char *extraData) {
    char line[100];
    FILE *tempFile = fopen("temp.txt", "w");

    while (fgets(line, 100, fp) != NULL) {
        if (sscanf(line, "%d,%[^,],%f,%d", &product.id, product.name, &product.price, &product.quantity) == 4) {
            if (product.id == productId) {
                fprintf(tempFile, "%d,%s,%s,%.2f,%d\n", product.id, product.name, extraData, product.price, product.quantity);
            } else {
                fprintf(tempFile, "%s", line);
            }
        }
    }

    fclose(fp);
    fclose(tempFile);
    remove(filename);
    rename("temp.txt", filename);
}

void removeProduct(FILE *fp, int productId) {
    char line[100];
    FILE *tempFile = fopen("temp.txt", "w");

    while (fgets(line, 100, fp) != NULL) {
        if (sscanf(line, "%d,%[^,],%f,%d", &product.id, product.name, &product.price, &product.quantity) == 4) {
            if (product.id != productId) {
                fprintf(tempFile, "%s", line);
            }
        }
    }

    fclose(fp);
    fclose(tempFile);
    remove(filename);
    rename("temp.txt", filename);
}

void searchProduct(FILE *fp, char initial) {
    char line[100];

    while (fgets(line, 100, fp) != NULL) {
        if (line[0] == initial) {
            printf("%s", line);
        }
    }
}

int main() {
    FILE *fp;
    char filename[50];
    int choice, productId;
    char extraData[100];
    char initial;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "a+"); 

    while (1) {
        printf("\n1. Add Product\n2. Append Data\n3. Remove Product\n4. Search Product\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
           
                break;
            case 2:
                printf("Enter product ID to append data: ");
                scanf("%d", &productId);
                printf("Enter extra data: ");
                scanf("%s", extraData);
                appendData(fp, productId, extraData);
                break;
            case 3:
                printf("Enter product ID to remove: ");
                scanf("%d", &productId);
                removeProduct(fp, productId);
                break;
            case 4:
                printf("Enter initial character to search: ");
                scanf(" %c", &initial);
                searchProduct(fp, initial);
                break;
            case 5:
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}