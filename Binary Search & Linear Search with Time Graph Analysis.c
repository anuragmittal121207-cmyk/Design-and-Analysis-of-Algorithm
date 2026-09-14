#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int n, int key) {
    for(int i=0; i<n; i++) {
        if(arr[i] == key) return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low=0, high=n-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main() {
    int n = 100000;
    int *arr = malloc(n * sizeof(int));
    for(int i=0; i<n; i++) arr[i] = i;  // sorted array

    clock_t start, end;
    double time_taken;

    // Linear Search
    start = clock();
    linearSearch(arr, n, n-1);
    end = clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Linear Search Time: %f\n", time_taken);

    // Binary Search
    start = clock();
    binarySearch(arr, n, n-1);
    end = clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Binary Search Time: %f\n", time_taken);

    free(arr);
    return 0;
}
