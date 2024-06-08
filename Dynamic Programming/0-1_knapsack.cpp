#include <bits/stdc++.h>
using namespace std;

const int MAX_ITEMS = 1000; // Define a constant for the maximum number of items
int itemWeights[MAX_ITEMS]; // Array to store weights of the items
int itemValues[MAX_ITEMS];  // Array to store values of the items
int dp[MAX_ITEMS][MAX_ITEMS]; // DP table to store intermediate results
int numberOfItems, maxCapacity; // 'numberOfItems' is the number of items, 'maxCapacity' is the maximum weight capacity of the knapsack

// Function to solve the knapsack problem using recursion and memoization
int knapsack(int currentItem = 0, int remainingCapacity = maxCapacity) {
    // Base case: if we've considered all items or the capacity is zero, return 0
    if (currentItem == numberOfItems || remainingCapacity == 0)
        return 0;
    
    // If the result is already computed, return it
    if (~dp[currentItem][remainingCapacity])
        return dp[currentItem][remainingCapacity];

    int includeCurrentValue = 0, excludeCurrentValue = 0;

    // Choice 1: Include the current item if its weight is within the current capacity
    if (itemWeights[currentItem] <= remainingCapacity) {
        includeCurrentValue = itemValues[currentItem] + knapsack(currentItem + 1, remainingCapacity - itemWeights[currentItem]);
    }

    // Choice 2: Skip the current item
    excludeCurrentValue = knapsack(currentItem + 1, remainingCapacity);

    // Store the maximum of the two choices in the dp table and return it
    return dp[currentItem][remainingCapacity] = max(includeCurrentValue, excludeCurrentValue);
}

int main() {
    ios::sync_with_stdio(false); // Disable synchronization between C and C++ standard streams
    cin.tie(0); // Untie cin from cout to speed up I/O
    cout.tie(0); // Untie cout from cin to speed up I/O
    memset(dp, -1, sizeof dp); // Initialize the dp table with -1 (indicating uncomputed states)
    
    cin >> numberOfItems >> maxCapacity; // Read the number of items and the maximum capacity of the knapsack
    
    for (int i = 0; i < numberOfItems; ++i)
        cin >> itemValues[i]; // Read the values of the items
    
    for (int i = 0; i < numberOfItems; ++i)
        cin >> itemWeights[i]; // Read the weights of the items

    cout << knapsack() << endl; // Call the knapsack function and print the result

    return 0;
}