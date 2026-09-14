/* Write a program to merge two sorted arrays into a single sorted array without using any built-in
sorting function. */ 

#include <stdio.h>

int main() {
    int n1, n2;
    printf("Enter size of array 1: "); scanf("%d", &n1);
    int a[n1];
    printf("Enter sorted elements of array 1: ");
    for(int i = 0; i < n1; i++) scanf("%d", &a[i]);

    printf("Enter size of array 2: "); scanf("%d", &n2);
    int b[n2], c[n1 + n2];
    printf("Enter sorted elements of array 2: ");
    for(int i = 0; i < n2; i++) scanf("%d", &b[i]);

    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2) c[k++] = (a[i] < b[j]) ? a[i++] : b[j++];
    while(i < n1) c[k++] = a[i++];
    while(j < n2) c[k++] = b[j++];

    printf("Merged sorted array: ");
    for(i = 0; i < k; i++) printf("%d ", c[i]);
    printf("\n");
    return 0;
}