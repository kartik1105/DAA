#include <iostream>
#include <algorithm>
using namespace std;

// Function to check if it's possible to complete the tasks within D days
// given the maximum work allowed per day.
bool canComplete(int task[], int n, int D, int maxWork) {
    int daysRequired = 1; // We start with one day
    int currentWork = 0;  // Track work done on the current day

    for (int i = 0; i < n; i++) {
        // If the task itself is greater than maxWork, it's impossible
        if (task[i] > maxWork) {
            return false;
        }

        // If adding this task exceeds maxWork, assign it to the next day
        if (currentWork + task[i] > maxWork) {
            daysRequired++;
            currentWork = task[i]; // Start a new day with the current task
        } else {
            currentWork += task[i]; // Add this task to the current day
        }
    }

    // If we can complete within D days, return true
    return daysRequired <= D;
}

// Function to find the minimum work per day to complete tasks in D days
int minWorkPerDay(int task[], int n, int D) {
    int low = *max_element(task, task + n);  // Max task is the minimum work we must allow per day
    int high = 0;
    for (int i = 0; i < n; i++) {
        high += task[i];  // The maximum work can be the sum of all tasks
    }

    int result = high;

    // Binary search for the minimum maximum work per day
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canComplete(task, n, D, mid)) {
            result = mid;   // Update result as we try to minimize the work per day
            high = mid - 1; // Try to reduce the maximum work
        } else {
            low = mid + 1;  // Increase the work per day to fit within D days
        }
    }

    return result;
}

int main() {
    int task1[] = {3, 4, 7, 15};
    int D1 = 10;
    int n1 = sizeof(task1) / sizeof(task1[0]);
    cout << "Minimum work per day: " << minWorkPerDay(task1, n1, D1) << endl;

    int task2[] = {30, 20, 22, 4, 21};
    int D2 = 6;
    int n2 = sizeof(task2) / sizeof(task2[0]);
    cout << "Minimum work per day: " << minWorkPerDay(task2, n2, D2) << endl;

    return 0;
}
