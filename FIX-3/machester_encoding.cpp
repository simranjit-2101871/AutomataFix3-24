//the machester encoding ficntion will give 0 as outout list element if a[i] and a[i-1] are same and 1 as an answere if the elements are differnet ,consider the first bit  of the input list consider its previous bit to be 0
#include <iostream>
#include <cstdlib> // for malloc and free

using namespace std;

void manchester(int len, int *arr){
    int *res = (int*)malloc(sizeof(int) * len);
    if (res == nullptr) {
        cerr << "Memory allocation failed" << endl;
        return;
    }
    
    res[0] = arr[0]; // Initialize the first bit based on arr[0]

    for (int i = 1; i < len; i++) {
        res[i] = (arr[i] != arr[i-1]) ? 1 : 0; // Check if current bit is different from previous bit
    }

    for (int i = 0; i < len; i++) {
        cout << res[i] << " ";
    }
    cout << endl; // To add a new line after the output

    free(res); // Deallocate the memory
}

int main() {
    int arr[] = {1, 0, 0, 1, 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    manchester(len, arr);

    return 0;
}