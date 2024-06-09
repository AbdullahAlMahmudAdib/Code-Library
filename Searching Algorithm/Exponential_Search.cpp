#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Binary search function to search for the element in the specified range
int binarySearch(const vector<int>& arr, int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Exponential search function to find the element in the array
int exponentialSearch(const vector<int>& arr, int x) {
    int n = arr.size();

    // Check if the element is at the first position
    if (arr[0] == x)
        return 0;

    // Find range for binary search by repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x)
        i *= 2;

    // Call binary search for the found range
    return binarySearch(arr, i / 2, min(i, n - 1), x);
}

int main() {
    int n, x;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements in sorted order:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the element you want to search: ";
    cin >> x;

    int result = exponentialSearch(arr, x);
    if (result == -1)
        cout << "Element is not present in array.\n";
    else
        cout << "Element is present at index " << result << ".\n";

    return 0;
}
