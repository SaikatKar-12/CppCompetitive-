#include <stdio.h>
#include <stdlib.h>

// Structure for an item which stores weight and corresponding value
typedef struct {
    int value;
    int weight;
} Item;

// Comparison function to sort items by value-to-weight ratio
int compare(const void *a, const void *b) {
    double r1 = (double)((Item *)a)->value / ((Item *)a)->weight;
    double r2 = (double)((Item *)b)->value / ((Item *)b)->weight;
    return (r1 > r2) ? -1 : (r1 < r2) ? 1 : 0;
}

// Function to calculate the maximum value we can obtain
double fractionalKnapsack(int W, Item arr[], int n) {
    // Sort items by value-to-weight ratio
    qsort(arr, n, sizeof(Item), compare);

    double totalValue = 0.0; // Total value in knapsack
    int currentWeight = 0;   // Current weight in knapsack

    for (int i = 0; i < n; i++) {
        // If adding Item[i] won't overflow, add it completely
        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            totalValue += arr[i].value;
        } else {
            // If we can't add current Item[i], add fractional part of it
            int remain = W - currentWeight;
            totalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int W = 50; // Weight of knapsack
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum value we can obtain = %.2f\n", fractionalKnapsack(W, arr, n));
    return 0;
}
