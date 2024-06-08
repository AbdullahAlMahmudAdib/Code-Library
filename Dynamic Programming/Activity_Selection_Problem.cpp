#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 20

using namespace std;

int n;

struct Activity {
    int index;
    int s; // start time
    int f; // finish time
} A[MAX], temp;

// Function to select activities that are mutually compatible
void activity_selector() {
    int i = 0; // The first activity always gets selected
    cout << "A" << A[i].index << " ";
    for (int j = 1; j < n; j++) {
        // If this activity's start time is greater than or equal to the finish time of the last selected activity
        if (A[j].s >= A[i].f) {
            cout << "A" << A[j].index + 1 << " ";
            i = j; // Update i to the current activity
        }
    }
}

// Function to take input for activities
void input_activity() {
    for (int i = 0; i < n; i++) {
        cout << "Enter index of activity/activity no. :";
        cin >> A[i].index;
        cout << "Enter start time:";
        cin >> A[i].s;
        cout << "Enter finish time:";
        cin >> A[i].f;
    }
}

// Function to sort activities based on their finish times
void sort_activity() {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j].f < A[min].f) {
                min = j;
            }
        }
        // Swap the activities
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

int main() {
    cout << "Enter number of activities:";
    cin >> n;
    
    input_activity(); // Read activity details from user
    
    sort_activity(); // Sort activities based on finish time
    
    cout << "\nMaximum size mutually compatible activities are:\n\n";
    activity_selector(); // Print the selected activities
    
    return 0;
}
