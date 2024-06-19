#include <stdio.h>
#include <stdlib.h>

// Global arrays to store weights and values
int *weights;
int *values;

// Comparator function to sort items by value-to-weight ratio
int cmp(const void *a, const void *b) {
    int idx1 = *(const int *)a;
    int idx2 = *(const int *)b;
    double ratio1 = (double)values[idx1] / weights[idx1];
    double ratio2 = (double)values[idx2] / weights[idx2];
    return (ratio1 > ratio2) ? -1 : (ratio1 < ratio2) ? 1 : 0;
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int W, int n) {
    // Array to store indices of items
    int *indices = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    // Sort indices based on value-to-weight ratio
    qsort(indices, n, sizeof(int), cmp);

    int curWeight = 0;  // Current weight in knapsack
    double finalValue = 0.0;  // Result (total value in knapsack)

    // Loop through all items
    for (int i = 0; i < n; i++) {
        int idx = indices[i];
        // If adding the whole item doesn't exceed capacity, add it
        if (curWeight + weights[idx] <= W) {
            curWeight += weights[idx];
            finalValue += values[idx];
        } else {
            // If we can't add the whole item, add fractional part
            int remain = W - curWeight;
            finalValue += values[idx] * ((double)remain / weights[idx]);
            break;  // Knapsack is full
        }
    }

    free(indices);
    return finalValue;
}

int main() {
    int W = 50;  // Knapsack capacity
    int w[] = {60, 100, 120};  // Weights of items
    int v[] = {190, 150, 160};  // Values of items
    int n = sizeof(w) / sizeof(w[0]);

    // Assign global arrays
    weights = w;
    values = v;

    double maxValue = fractionalKnapsack(W, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
