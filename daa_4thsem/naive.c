#include <stdio.h>
#include <string.h>

// Function to perform naive pattern search
void naiveSearch(char* pattern, char* text) {
    int M = strlen(pattern);
    int N = strlen(text);

    // A loop to slide pattern one by one
    for (int i = 0; i <= N - M; i++) {
        int j;

        // For current index i, check for pattern match
        for (j = 0; j < M; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        // If pattern is found
        if (j == M) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABA";

    naiveSearch(pattern, text);

    return 0;
}
