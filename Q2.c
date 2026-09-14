// Write a program to count the frequency of each distinct element in an array.

#include <stdio.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int a[n], visited[n];

    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        visited[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        int count = 1;
        for(int j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                count++;
                visited[j] = 1;
            }
        }
        printf("Element %d: %d times\n", a[i], count);
    }
    return 0;
}