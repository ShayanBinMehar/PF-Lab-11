#include <stdio.h>

#define MAX_NAME_LENGTH 50
#define MAX_QUESTIONS 100

struct Question {
    int number;
    float timeTaken;
    int isCorrect;
};

struct Student {
    char name[MAX_NAME_LENGTH];
    struct Question scorecard[MAX_QUESTIONS];
    int numQuestions;
    int correctAnswers;
    float averageTime;
};

void inputStudentDetails(struct Student *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);
    printf("Enter number of questions: ");
    scanf("%d", &student->numQuestions);

    for (int i = 0; i < student->numQuestions; i++) {
        printf("Question %d:\n", i + 1);
        printf("  Answer time: ");
        scanf("%f", &student->scorecard[i].timeTaken);
        printf("  Correct/Incorrect (1/0): ");
        scanf("%d", &student->scorecard[i].isCorrect);
    }
}

int calculateCorrectAnswers(struct Student student) {
    int correctCount = 0;
    for (int i = 0; i < student.numQuestions; i++) {
        if (student.scorecard[i].isCorrect) {
            correctCount++;
        }
    }
    return correctCount;
}

float calculateAverageTime(struct Student student, int correctCount) {
    float totalTime = 0.0;
    for (int i = 0; i < student.numQuestions; i++) {
        if (student.scorecard[i].isCorrect) {
            totalTime += student.scorecard[i].timeTaken;
        }
    }
    return totalTime / correctCount;
}

void rankStudents(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].averageTime > students[j + 1].averageTime) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\nStudent Rankings:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s (Average Time: %.2f seconds)\n", i + 1, students[i].name, students[i].averageTime);
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student students[numStudents];

    for (int i = 0; i < numStudents; i++) 1  {
        inputStudentDetails(&students[i]);
        students[i].correctAnswers = calculateCorrectAnswers(students[i]);
        students[i].averageTime = calculateAverageTime(students[i], students[i].correctAnswers);
    }

    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Correct Answers: %d\n", students[i].correctAnswers);
        printf("Average Time per Correct Answer: %.2f seconds\n", students[i].averageTime);
    }

    struct Student fastestStudent = findFastestStudent(students, numStudents);
    printf("\nFastest Student:\n");
    printf("Name: %s\n", fastestStudent.name);
    printf("Average Time: %.2f seconds\n", fastestStudent.averageTime);

    rankStudents(students, numStudents);

    return 0;
}