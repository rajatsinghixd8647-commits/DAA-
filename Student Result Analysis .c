#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
};

int main() {
    struct Student s[50];
    int n;
    int i, j;
    int topper = 0;
    float classTotal = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        s[i].total = 0;

        printf("Enter marks in 5 subjects:\n");

        for (j = 0; j < 5; j++) {
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 5.0;

        if (s[i].percentage >= 90)
            s[i].grade = 'A';
        else if (s[i].percentage >= 80)
            s[i].grade = 'B';
        else if (s[i].percentage >= 70)
            s[i].grade = 'C';
        else if (s[i].percentage >= 60)
            s[i].grade = 'D';
        else if (s[i].percentage >= 40)
            s[i].grade = 'E';
        else
            s[i].grade = 'F';

        classTotal += s[i].percentage;
    }

    for (i = 1; i < n; i++) {
        if (s[i].total > s[topper].total) {
            topper = i;
        }
    }

    printf("\n--- Student Results ---\n");

    for (i = 0; i < n; i++) {
        printf("\nRoll Number: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal: %d", s[i].total);
        printf("\nPercentage: %.2f", s[i].percentage);
        printf("\nGrade: %c\n", s[i].grade);
    }

    printf("\n--- Class Topper ---\n");
    printf("Name: %s\n", s[topper].name);
    printf("Roll Number: %d\n", s[topper].roll);
    printf("Total: %d\n", s[topper].total);

    printf("\n--- Students Who Failed ---\n");

    for (i = 0; i < n; i++) {
        int failed = 0;

        for (j = 0; j < 5; j++) {
            if (s[i].marks[j] < 40) {
                failed = 1;
            }
        }

        if (failed == 1) {
            printf("%s\n", s[i].name);
        }
    }

    printf("\nClass Average = %.2f\n", classTotal / n);

    return 0;
}
