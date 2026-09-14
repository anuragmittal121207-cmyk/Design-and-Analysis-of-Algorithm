/*
Write a C program to rotate an array to the right by K positions without using another array.
Array: 1 2 3 4 5 6 K = 2
Output: 5 6 1 2 3 4
*/

#include <stdio.h>

void reverse(int a[], int start, int end) {
    while(start < end) {
        int temp = a[start];
        a[start++] = a[end];
        a[end--] = temp;
    }
}

int main() {
    int n, k;
    printf("Enter size of array: "); scanf("%d", &n);
    int a[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter K: "); scanf("%d", &k);

    k = k % n;
    reverse(a, 0, n - 1);
    reverse(a, 0, k - 1);
    reverse(a, k, n - 1);

    printf("Output: ");
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}