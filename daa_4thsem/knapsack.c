#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum enjoyment
int knapsack(int W, int n, int wt[], int val[]) {
    int i, w;

    // Dynamically allocate memory for the dp array
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((W + 1) * sizeof(int));
    }

    // Build the table dp[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = (val[i - 1] + dp[i - 1][w - wt[i - 1]] > dp[i - 1][w]) ? 
                            (val[i - 1] + dp[i - 1][w - wt[i - 1]]) : 
                            dp[i - 1][w];
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    int max_enjoyment = dp[n][W];

    // Free the dynamically allocated memory
    for (i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return max_enjoyment;
}

int main() {
    int total_time = 6; // Total available time (hours)
    int n = 4; // Number of events

    // Durations of the events
    int times[] = {3, 2, 4, 3};

    // Enjoyment values of the events
    int values[] = {4, 2, 5, 3};

    int max_enjoyment = knapsack(total_time, n, times, values);
    printf("Maximum enjoyment value: %d\n", max_enjoyment);

    return 0;
}
