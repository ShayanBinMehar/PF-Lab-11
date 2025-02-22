#include <stdio.h>

#define MAX_NAME_LENGTH 50
#define MAX_DNAME_LENGTH 30

struct Employee_Detail {
    char name[MAX_NAME_LENGTH];
    int id;
    char dname[MAX_DNAME_LENGTH];
    char mname[MAX_NAME_LENGTH];
    float salary;
};

void addEmployee(struct Employee_Detail *employee) {
    printf("Enter the details of the Employee:\n");
    printf("Enter the name of the employee: \n");
    scanf("%s", employee->name);   
    printf("Enter the ID of the employee: \n");
    scanf("%d", &employee->id);     
    printf("Enter the department name of the employee: \n");
    scanf("%s", employee->dname);
    printf("Enter the manager name of the employee: \n");
    scanf("%s", employee->mname);
    printf("Enter the salary of the employee: \n");
    scanf("%f", &employee->salary);
}

void displayEmployee(struct Employee_Detail employee) {
    printf("\nEmployee Detail\n");
    printf("Employee name = %s\n", employee.name);
    printf("Employee ID = %d\n", employee.id);
    printf("Employee department name = %s\n", employee.dname);
    printf("Employee manager name = %s\n", employee.mname);
    printf("Employee salary = %.2f\n", employee.salary);  
}

void findHighestPaidEmployee(struct Employee_Detail employee[], int numEmployees) {
    int highestPaidIndex = 0;  


    for (int i = 1; i < numEmployees; i++) {
        if (employee[i].salary > employee[highestPaidIndex].salary) {
            highestPaidIndex = i;
        }
    }

    printf("\nEmployee with the Highest Salary:\n");
    displayEmployee(employee[highestPaidIndex]);
}

int main() {
    int numOfEmployees = 0, choice;
    struct Employee_Detail employees[100];

    while (choice != 4) {  
        printf("1. Add Employee\n2. Display Employees\n3. Find Highest Paid Employee\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees + numOfEmployees); 
                numOfEmployees++;
                break;
            case 2:
                if (numOfEmployees == 0) {
                    printf("No employees added yet!\n");
                } else {
                    for (int i = 0; i < numOfEmployees; i++) {
                        displayEmployee(employees[i]);
                    }
                }
                break;
            case 3:
                if (numOfEmployees == 0) {
                    printf("No employees added yet!\n");
                } else {
                    findHighestPaidEmployee(employees, numOfEmployees);
                }
                break;
            case 4:
                break;
            default:
                printf("Enter a valid choice.\n");
                break;
        }
    }

    return 0;
}