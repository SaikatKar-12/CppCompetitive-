#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to create the longest prefix suffix (LPS) array
void computeLPSArray(char* pattern, int M, int* lps) {
    int length = 0;  // length of the previous longest prefix suffix
    int i;

    lps[0] = 0;  // lps[0] is always 0
    i = 1;

    while (i < M) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        }
        else {
            if (length != 0) {
                length = lps[length - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to perform KMP search
void KMPSearch(char* pattern, char* text) {
    int M = strlen(pattern);
    int N = strlen(text);

    // Dynamically allocate memory for lps array
    int* lps = (int*)malloc(M * sizeof(int));
    if (!lps) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pattern, M, lps);

    int i = 0;  // index for text[]
    int j = 0;  // index for pattern[]

    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    // Free the dynamically allocated memory
    free(lps);
}

int main() {
    char text[] = "The challenges include change of skin disease color according to skin natures, elevated and depressed surface of skin lesions";
    char pattern[] = "skin disease color according to skin natures";

    KMPSearch(pattern, text);

    return 0;
}
