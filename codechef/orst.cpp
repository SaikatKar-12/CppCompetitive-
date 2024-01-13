#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortVectorBetweenIndices(vector<int> &vec, int startIndex, int endIndex) {
    if (startIndex < 0 || endIndex >= vec.size() || startIndex >= endIndex) {
        cout << "Invalid indices for sorting.\n";
        return;
    }

    // Create a sub-vector between the specified indices
    vector<int>::iterator startIter = vec.begin() + startIndex;
    vector<int>::iterator endIter = vec.begin() + endIndex + 1;

    // Sorting the sub-vector
    sort(startIter, endIter);
}

int main() {
    // Example usage
    vector<int> myVector = {3, 1, 4, 1, 5,};
    
    // Indices for sorting (0-based indexing)
    int startIndex = 4;
    int endIndex = 4;

    // Sorting the vector between the specified indices
    sortVectorBetweenIndices(myVector, startIndex, endIndex);

    // Output the sorted vector
    cout << "Sorted vector between indices " << startIndex << " and " << endIndex << ":\n";
    for (int num : myVector) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
