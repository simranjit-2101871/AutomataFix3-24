//Simply we have to repace the values of the array with max value present in the array
#include<iostream>
using namespace std;
void max_replace(int a[],int size){
    int i,max=0;
    if(size>0){
        for(i=0;i<size;i++){
            if(max<a[i]){
                max=a[i];
            }
        }
    }
    else{
        return;
    }
    for(i=0;i<size;i++){
        a[i]=max;
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[4]={1,2,3,4};
    int n=4;
    max_replace(arr,n);
}










//with edge case if all elements are neagtive
#include<iostream>
using namespace std;

void max_replace(int a[], int size) {
    if (size <= 0) {
        return; // Nothing to replace if size is 0 or negative
    }

    int max = a[0]; // Initialize max with the first element of the array

    // Find the maximum element in the array
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    // Replace all elements with the maximum value found
    for (int i = 0; i < size; i++) {
        a[i] = max;
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test with an array with positive and negative numbers
    int arr1[4] = {1, -2, 3, -4};
    int n1 = 4;
    cout << "Original array: ";
    max_replace(arr1, n1);

    // Test with an array where all elements are negative
    int arr2[5] = {-5, -2, -5, -1, -7};
    int n2 = 5;
    cout << "Original array: ";
    max_replace(arr2, n2);

    return 0;
}
