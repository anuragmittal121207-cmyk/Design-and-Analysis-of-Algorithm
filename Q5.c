/*
Write a program to multiply two matrices. Before multiplication, verify whether the given matrices are
compatible.
*/

#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    printf("Enter rows and cols for Matrix 1: "); scanf("%d %d", &r1, &c1);
    printf("Enter rows and cols for Matrix 2: "); scanf("%d %d", &r2, &c2);

    if(c1 != r2) {
        printf("Matrix multiplication not compatible!\n");
        return 0;
    }

    int a[r1][c1], b[r2][c2], res[r1][c2];
    printf("Enter Matrix 1 elements:\n");
    for(int i = 0; i < r1; i++) for(int j = 0; j < c1; j++) scanf("%d", &a[i][j]);

    printf("Enter Matrix 2 elements:\n");
    for(int i = 0; i < r2; i++) for(int j = 0; j < c2; j++) scanf("%d", &b[i][j]);

    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for(int k = 0; k < c1; k++) res[i][j] += a[i][k] * b[k][j];
        }
    }

    printf("Resultant Matrix:\n");
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}