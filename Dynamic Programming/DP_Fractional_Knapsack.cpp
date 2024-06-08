#include <iostream>
#include <algorithm> // for sort

using namespace std;

// Struct to represent each item
struct Item {
    int value;
    int weight;
};

// Comparator function to sort items based on their value-to-weight ratio in descending order
bool comp(Item& a, Item& b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int w, Item arr[], int n) {
    // Sort items based on value-to-weight ratio
    sort(arr, arr + n, comp);

    double totalValue = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= w) {
            // If the current item can be fully added to the knapsack
            totalValue += arr[i].value;
            w -= arr[i].weight;
        } else {
            // If only a fraction of the current item can be added
            totalValue += (double)arr[i].value / arr[i].weight * w;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    Item *arr = new Item[n];

    // Input items
    for (int i = 0; i < n; i++) {
        cout << "Enter value of item " << i + 1 << ": ";
        cin >> arr[i].value;
        cout << "Enter weight of item " << i + 1 << ": ";
        cin >> arr[i].weight;
    }

    int w;
    cout << "Enter the knapsack capacity: ";
    cin >> w;

    // Calculate and print the maximum total value in the knapsack
    double maxValue = fractionalKnapsack(w, arr, n);
    cout << "Maximum total value in the knapsack: " << maxValue << endl;

    delete[] arr; // Free dynamically allocated memory
    return 0;
}
