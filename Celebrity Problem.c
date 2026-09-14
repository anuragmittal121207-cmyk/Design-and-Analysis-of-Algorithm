#include <stdio.h>
#define N 4

// Function to check if person a knows person b
int knows(int M[N][N], int a, int b) {
    return M[a][b];
}

// Function to find celebrity
int findCelebrity(int M[N][N], int n) {
    int candidate = 0;

    // Step 1: Find candidate
    for(int i=1; i<n; i++) {
        if(knows(M, candidate, i)) {
            candidate = i; // candidate cannot be celeb if he knows someone
        }
    }

    // Step 2: Verify candidate
    for(int i=0; i<n; i++) {
        if(i != candidate) {
            if(knows(M, candidate, i) || !knows(M, i, candidate)) {
                return -1; // Not a celebrity
            }
        }
    }
    return candidate;
}

int main() {
    int M[N][N] = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}, // Person 2 is celebrity
        {0, 1, 1, 0}
    };

    int celeb = findCelebrity(M, N);
    if(celeb == -1) printf("No Celebrity Found\n");
    else printf("Celebrity is Person %d\n", celeb);

    return 0;
}
