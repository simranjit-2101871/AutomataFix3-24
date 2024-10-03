//Clcualte median for all the element in iput list, but the problem is that it only works for the lsit  of odd lengthdo some modification in the 
//code and make it work for the lsit of even length as well

/*float median(int size, int *inputlist){
    int start_index=0;
    int end_index=size-1;
    float res=-1;
    if(size%2!=0){//odd size input
        int median_order=((size+1)/2);
        res=(float)quick_select(inputlist,start_index,end_index,median_order);

    }
    else{
        //even size list
        int median_order1=((size)/2);
        int res1=(float)quick_select(inputlist,start_index,end_index,median_order1);
        int median_order2=((size)+1)/2;
        int res2=(float)quick_select(inputlist,start_index,end_index,median_order2);

        res=(res1+res2)/2.0;

    }
}
*/

#include <iostream>
#include <cstdlib> // for rand and malloc
#include <ctime>   // for seeding rand

using namespace std;

// Partition function for Quickselect
int partition(int *arr, int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]); // Move pivot to end
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[right]); // Move pivot to its final place
    return storeIndex;
}

// Quickselect function to find the k-th smallest element
int quick_select(int *arr, int left, int right, int k) {
    if (left == right) { // If the list contains only one element
        return arr[left];
    }

    int pivotIndex = left + rand() % (right - left + 1); // Pick a random pivot
    pivotIndex = partition(arr, left, right, pivotIndex);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quick_select(arr, left, pivotIndex - 1, k);
    } else {
        return quick_select(arr, pivotIndex + 1, right, k);
    }
}

// Function to calculate the median
float median(int size, int *inputlist) {
    int start_index = 0;
    int end_index = size - 1;
    float res;

    if (size % 2 != 0) { // Odd size input
        int median_order = size / 2; // middle element for odd size (0-indexed)
        res = (float)quick_select(inputlist, start_index, end_index, median_order);
    } else { // Even size input
        int median_order1 = size / 2 - 1; // middle element (0-indexed) for the lower half
        int median_order2 = size / 2; // middle element (0-indexed) for the upper half

        int res1 = quick_select(inputlist, start_index, end_index, median_order1);
        int res2 = quick_select(inputlist, start_index, end_index, median_order2);

        res = (res1 + res2) / 2.0;
    }

    return res;
}

int main() {
    srand(time(0)); // Seed the random number generator

    int arr[] = {7, 1, 3, 2, 5, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Median: " << median(size, arr) << endl;

    int arr2[] = {7, 1, 3, 2, 5, 4};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Median: " << median(size2, arr2) << endl;

    return 0;
}


/*Randomness in Pivot Selection:

The Quickselect algorithm involves selecting a pivot randomly to partition the array. Using a fixed seed (or not seeding at all) would result in the same sequence of "random" numbers each time the program runs.
By seeding with the current time (which changes every second), we ensure that the sequence of pivots chosen is different each time, leading to a more robust and unpredictable partitioning process.
Avoiding Worst-Case Scenarios:

If the pivot selection is not truly random, certain input arrays might consistently cause the Quickselect algorithm to perform poorly, leading to its worst-case time complexity of 
𝑂
(
𝑛
2
)
O(n 
2
 ).
Randomizing the pivot helps distribute the elements more evenly and reduces the likelihood of consistently hitting worst-case performance.
Testing and Debugging:

For testing purposes, using srand(time(0)) makes the behavior of the algorithm vary with each run, helping to ensure that the algorithm handles different scenarios and inputs robustly.
If you need to reproduce a specific sequence for debugging, you can use a fixed seed value (e.g., srand(42);) instead of the current time. This way, the same sequence of random numbers (and thus pivots) will be generated each time.*/