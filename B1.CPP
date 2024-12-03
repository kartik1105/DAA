#include <iostream>
#include <algorithm> // for sorting

using namespace std;

// Activity Selection Problem with K persons using Greedy approach
// Function to sort activities based on their ending times
bool compare(int a, int b, int S[], int E[]) {
    return E[a] < E[b]; // Compare the end times of activities
}

int activitySelection(int S[], int E[], int N, int K) {
    int count = 0;  // To keep track of the number of activities selected
    bool visited[N] = {false};  // To track if an activity has been assigned to a person

    // Array to store the indices of activities, based on end times
    int order[N];
    for (int i = 0; i < N; i++) {
        order[i] = i;  // Initialize with the activity indices
    }

    // Sort activities based on their end times using the compare function
    sort(order, order + N, [&](int a, int b) { return compare(a, b, S, E); });

    // For each activity, check if it can be attended by a person
    int personsUsed = 0;
    for (int i = 0; i < N; i++) {
        // Check if the activity can be attended by a person
        bool assigned = false;
        for (int j = 0; j < K; j++) {
            if (!visited[j]) {
                visited[j] = true; // Mark this person as busy
                assigned = true;
                count++; // Activity can be attended, so increment the count
                break;
            }
        }

        // Stop if we have allocated activities to all people
        if (personsUsed == K) {
            break;
        }
    }

    // Return the total count of selected activities
    return count;
}

int main() {
    // Input arrays
    int S[] = {1, 8, 3, 2, 6};
    int E[] = {5, 10, 6, 5, 9};
    int N = sizeof(S) / sizeof(S[0]); // Number of activities
    int K = 2; // Number of persons

    int result = activitySelection(S, E, N, K);
    cout << "Maximum number of shops they can visit: " << result << endl;

    return 0;
}
