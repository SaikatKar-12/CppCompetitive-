#include <stdio.h>

int maxi(int a, int b) {
    return (a > b) ? a : b;
}

// Define dp array size based on the problem constraints
#define MAX_W 50
#define MAX_N 3  // Since there are 3 items

int dp[MAX_W + 1][MAX_N + 1];  // dp array size adjusted for 0 to MAX_W and 0 to MAX_N

int knapsack(int W, int val[], int wt[], int n) {
    // Base Case
    if (W == 0 || n == 0)
        return 0;

    // Memoization check
    if (dp[W][n] != -1)
        return dp[W][n];

    // If the weight of the nth item is more than the Knapsack capacity W
    if (wt[n - 1] > W)
        return dp[W][n] = knapsack(W, val, wt, n - 1);
    else
        return dp[W][n] = maxi(val[n - 1] + knapsack(W - wt[n - 1], val, wt, n - 1),
                               knapsack(W, val, wt, n - 1));
}

int main() {
    int val[] = {60, 100, 120};  // Values of the items
    int wt[] = {10, 20, 30};     // Weights of the items
    int W = 50;                  // Capacity of the knapsack
    int n = sizeof(val) / sizeof(val[0]);  // Number of items

    // Initialize dp array with -1
    for (int i = 0; i <= W; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }

    printf("Maximum value in Knapsack = %d\n", knapsack(W, val, wt, n));
    return 0;
}
