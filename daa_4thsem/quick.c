#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50

// Structure to represent a product
typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} Product;

// Function to swap two products
void swap(Product *a, Product *b) {
    Product temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(Product arr[], int low, int high) {
    float pivot = arr[high].price; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j].price <= pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array of products
void printProducts(Product arr[], int size) {
    printf("Products sorted by price (low to high):\n");
    for (int i = 0; i < size; i++) {
        printf("%s: $%.2f\n", arr[i].name, arr[i].price);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int n;

    printf("Enter the number of products: ");
    scanf("%d", &n);

    // Input product names and prices
    for (int i = 0; i < n; i++) {
        printf("Enter product name: ");
        scanf("%s", products[i].name);
        printf("Enter price of %s: $", products[i].name);
        scanf("%f", &products[i].price);
    }

    // Sort products using Quick Sort
    quickSort(products, 0, n - 1);

    // Print sorted products
    printProducts(products, n);

    return 0;
}
