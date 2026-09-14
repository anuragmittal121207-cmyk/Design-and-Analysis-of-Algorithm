/*
Write a C program to find all pairs of elements in an array whose sum is equal to a given target
value. Each pair should be displayed only once.

Array: 2 7 4 5 1 3 Target: 6
Output: (2, 4), (5, 1)

*/

#include <stdio.h>

int main() {
    int n, target;
    printf("Enter size of array: "); scanf("%d", &n);
    int a[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter target sum: "); scanf("%d", &target);

    printf("Output: ");
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] + a[j] == target) {
                int isDup = 0;
                for(int k = 0; k < i; k++) {
                    if(a[k] == a[i] || a[k] == a[j]) isDup = 1;
                }
                if(!isDup) printf("(%d, %d) ", a[i], a[j]);
            }
        }
    }
    printf("\n");
    return 0;
}