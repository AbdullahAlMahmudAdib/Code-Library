#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int end = n-1;
    int start = 0;

    while(start <= end){
        int mid = start + (end - start) / 2;  // To avoid overflow for large `start` and `end` values

        if(arr[mid] < key){
            start = mid + 1;
        }
        else if(arr[mid] > key) {
            end = mid - 1;
        }
        else {
            return mid;  // Return the position where the element is found
        }
    }
    return -1;  // Return -1 if the element is not found
}

int main() {
    int n, key;
    
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array in sorted order: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << "Enter the element to search: ";
    cin >> key;
    
    int result = binarySearch(arr, n, key);
    
    if(result != -1){
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
