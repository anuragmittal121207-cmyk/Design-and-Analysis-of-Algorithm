#include <stdio.h>
#include <stdbool.h>

#define N 5

// Celebrity names
const char *celebrities[N] = {
    "Taylor Swift",
    "Leonardo DiCaprio",
    "Zendaya",
    "Robert Downey Jr.",
    "Keanu Reeves"
};

// Matrix: knows[i][j] = true if person i knows person j
bool knows[N][N] = {
    {false, true,  true,  true,  true},   // Taylor knows everyone
    {false, false, true,  true,  true},   // Leo knows Zendaya, RDJ, Keanu
    {false, false, false, false, false},  // Zendaya knows no one
    {false, false, true,  false, true},   // RDJ knows Zendaya, Keanu
    {false, false, true,  true,  false}   // Keanu knows Zendaya, RDJ
};

// Function to check if person a knows person b
bool knowsFunc(int a, int b) {
    return knows[a][b];
}

// Function to find celebrity
int findCelebrity(int n) {
    int candidate = 0;
    for (int i = 1; i < n; i++) {
        if (knowsFunc(candidate, i)) {
            candidate = i;
        }
    }
    // Verify candidate
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knowsFunc(candidate, i) || !knowsFunc(i, candidate)) {
                return -1;
            }
        }
    }
    return candidate;
}

int main() {
    int celebIndex = findCelebrity(N);
    if (celebIndex == -1) {
        printf("No celebrity found.\n");
    } else {
        printf("Celebrity is: %s\n", celebrities[celebIndex]);
    }
    return 0;
}

