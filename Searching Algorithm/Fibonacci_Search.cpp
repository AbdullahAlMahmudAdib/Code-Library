#include <iostream>
#include <vector>
using namespace std;

// Utility function to find the minimum of two numbers
int min(int x, int y) {
    return (x <= y) ? x : y;
}

// Function to perform Fibonacci search on a sorted array
int fibMonaccianSearch(vector<int>& arr, int x, int n) {
    // Initialize Fibonacci numbers
    int fibMMm2 = 0; // (m-2)th Fibonacci number
    int fibMMm1 = 1; // (m-1)th Fibonacci number
    int fibM = fibMMm2 + fibMMm1; // mth Fibonacci number

    // Find the smallest Fibonacci number greater than or equal to n
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1; // Marks the eliminated range from the front

    // While there are elements to inspect
    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);

        // If x is greater than the value at index fibMMm2, cut the subarray from offset to i
        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        // If x is less than the value at index fibMMm2, cut the subarray after i+1
        else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        // Element found
        else {
            return i;
        }
    }

    // Comparing the last element with x
    if (fibMMm1 && arr[offset + 1] == x) {
        return offset + 1;
    }

    // Element not found
    return -1;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements in array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the element you want to search in the array using Fibonacci search: ";
    cin >> x;

    int result = fibMonaccianSearch(arr, x, n);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}