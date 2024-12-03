#include <iostream>
#include <algorithm> // For max() function

using namespace std;

// Function to check if it's possible to complete tasks with a given work per day
bool canCompleteTasks(int tasks[], int N, int D, int workPerDay) {
    int daysRequired = 1;  // We start with the first day
    int currentWork = 0;

    for (int i = 0; i < N; i++) {
        // If adding the current task exceeds the allowed work per day
        if (currentWork + tasks[i] > workPerDay) {
            daysRequired++;  // We need another day
            currentWork = tasks[i];  // Start a new day with the current task
        } else {
            currentWork += tasks[i];  // Add the current task to today's work
        }

        // If the days required exceeds D, we return false
        if (daysRequired > D) {
            return false;
        }
    }
    return true;
}

// Function to find the minimum work per day using binary search
int findMinimumWork(int tasks[], int N, int D) {
    int left = *max_element(tasks, tasks + N);  // The work per day cannot be less than the largest task
    int right = 0;
    for (int i = 0; i < N; i++) {
        right += tasks[i];  // The maximum work per day is the sum of all tasks
    }

    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if it's possible to complete tasks with 'mid' work per day
        if (canCompleteTasks(tasks, N, D, mid)) {
            result = mid;  // If it's possible, try for a lower work per day
            right = mid - 1;
        } else {
            left = mid + 1;  // If it's not possible, we need more work per day
        }
    }
    return result;
}

int main() {
    // Input task array and the number of days
    int tasks[] = {3, 4, 7, 15};
    int N = sizeof(tasks) / sizeof(tasks[0]);  // Number of tasks
    int D = 10;  // Number of days

    // Call the function to find the minimum work per day
    int result = findMinimumWork(tasks, N, D);

    // Output the result
    cout << "The minimum amount of work to be done each day is: " << result << endl;

    return 0;
}
