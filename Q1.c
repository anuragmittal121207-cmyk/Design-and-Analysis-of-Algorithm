// Write a C program to find the second-largest distinct element in an array without sorting it.

#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n], m1 = INT_MIN, m2 = INT_MIN;

    printf("Enter array elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] > m1) { 
            m2 = m1; 
            m1 = a[i]; 
        } else if(a[i] > m2 && a[i] < m1) { 
            m2 = a[i]; 
        }
    }

    if(m2 == INT_MIN) printf("No second largest distinct element.\n");
    else printf("Second largest distinct element: %d\n", m2);
    return 0;
}