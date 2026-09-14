/*
Student Result Analysis
• Store the roll number, name, and marks in five subjects for N students using structures.
• Calculate the total, percentage, and grade of each student.
• Display the class topper, students who failed in one or more subjects, and the class average.
*/

#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    int marks[5];
    int total;
    float percentage;
};

int main() {
    int n;
    printf("Enter number of students: "); scanf("%d", &n);
    struct Student s[n];
    float classTotal = 0;
    int topperIdx = 0;

    for(int i = 0; i < n; i++) {
        printf("\nEnter Roll and Name: ");
        scanf("%d %s", &s[i].roll, s[i].name);
        s[i].total = 0;
        printf("Enter 5 subject marks: ");
        for(int j = 0; j < 5; j++) {
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }
        s[i].percentage = s[i].total / 5.0;
        classTotal += s[i].total;

        if(s[i].total > s[topperIdx].total) topperIdx = i;
    }

    printf("\n--- Class Topper ---\n%s (Roll: %d) | Total: %d | Percentage: %.2f%%\n",
           s[topperIdx].name, s[topperIdx].roll, s[topperIdx].total, s[topperIdx].percentage);

    printf("\n--- Students Failed in 1 or More Subjects ---\n");
    for(int i = 0; i < n; i++) {
        int failed = 0;
        for(int j = 0; j < 5; j++) if(s[i].marks[j] < 40) failed = 1;
        if(failed) printf("%s (Roll: %d)\n", s[i].name, s[i].roll);
    }

    printf("\nClass Average Marks: %.2f\n", classTotal / (n * 5.0));
    return 0;
}