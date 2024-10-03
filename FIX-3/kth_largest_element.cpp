#include <iostream>
#include <algorithm>  // For std::sort

using namespace std;

// Function to find the K-th largest element in the array
int kLargestElement(int length, int K, int arr[]) {
    if (K > length) {
        return -1; // Out of bounds
    }
    // Sort the array in descending order
    sort(arr, arr + length, greater<int>());
    return arr[K-1];
}

// Function to remove the K-th largest element from the array
void removeKLargestElement(int length, int K, int arr[]) {
    int largest = kLargestElement(length, K, arr);
    if (largest != -1) {
        // Find the position of the K-th largest element
        int pos = -1;
        for (int i = 0; i < length; ++i) {
            if (arr[i] == largest) {
                pos = i;
                break;
            }
        }
        // Remove the element by shifting the remaining elements left
        if (pos != -1) {
            for (int i = pos; i < length - 1; ++i) {
                arr[i] = arr[i + 1];
            }
            --length; // Decrease the length of the array
        }
    }
    // Print the remaining elements
    for (int i = 0; i < length; ++i) {
        cout << arr[i];
        if (i < length - 1) {
            cout << " ";
        }
    }
}

int main() {
    int arr[] = {3, 6, 8, 2, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    removeKLargestElement(len, 2, arr);
    return 0;
}
