#include <stdio.h>
#include <limits.h>

// Function to print the optimal parenthesization
void printOptimalParens(int i, int j, int n, int *bracket, char *name) {
    // If only one matrix left in current segment
    if (i == j) {
        printf("%c", (*name)++);
        return;
    }

    printf("(");

    // Recursively put brackets around subexpression
    // from i to bracket[i][j].
    printOptimalParens(i, *((bracket + i * n) + j), n, bracket, name);

    // Recursively put brackets around subexpression
    // from bracket[i][j] + 1 to j.
    printOptimalParens(*((bracket + i * n) + j) + 1, j, n, bracket, name);

    printf(")");
}

// Function for matrix chain multiplication
void matrixChainOrder(int p[], int n) {
    // m[i][j] is the minimum number of scalar multiplications needed
    // to compute the matrix A[i]A[i+1]...A[j] = A[i..j]
    int m[n][n];
    int bracket[n][n];

    // cost is zero when multiplying one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                // q = cost/scalar multiplications
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;

                    // put parenthesis at position k results in
                    // subproblem i..k and k+1..j
                    bracket[i][j] = k;
                }
            }
        }
    }

    // Name the matrices as A, B, C, etc.
    char name = 'A';

    printf("Optimal Parenthesization is : ");
    printOptimalParens(1, n - 1, n, (int *)bracket, &name);
    printf("\nOptimal Cost is : %d\n", m[1][n - 1]);
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    matrixChainOrder(arr, n);

    return 0;
}
