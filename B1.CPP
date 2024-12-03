#include <iostream>
#include <algorithm>
using namespace std;

// Structure to store a shop's start and end time
struct Shop {
    int start;
    int end;
};

// Comparator function to sort shops based on end time
bool compare(Shop a, Shop b) {
    return a.end < b.end;
}

// Function to find the maximum number of shops that can be visited
int activitySelection(Shop arr[], int N, int K) {
    // Sort the activities by end time
    sort(arr, arr + N, compare);
    
    // Array to keep track of the next available time for each person
    int personEndTimes[K];
    for (int i = 0; i < K; i++) {
        personEndTimes[i] = 0;  // Initialize each person's last visited time to 0
    }

    int count = 0; // To count the number of shops visited
    
    for (int i = 0; i < N; i++) {
        // Try to assign the current shop to a person
        bool assigned = false;
        for (int j = 0; j < K; j++) {
            // If the person can visit this shop (no overlap)
            if (arr[i].start >= personEndTimes[j]) {
                // Assign this shop to the person and update their last visited time
                personEndTimes[j] = arr[i].end;
                assigned = true;
                count++;
                break;
            }
        }
        if (!assigned) {
            break; // No more people available to assign this shop
        }
    }
    
    return count;
}

int main() {
    int N, K;
    cout << "Enter the number of shops (N): ";
    cin >> N;
    cout << "Enter the number of persons (K): ";
    cin >> K;

    Shop arr[N];
    cout << "Enter the start and end times for each shop:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Shop " << i + 1 << ": ";
        cin >> arr[i].start >> arr[i].end;
    }

    int result = activitySelection(arr, N, K);
    cout << "Maximum number of shops they can visit: " << result << endl;

    return 0;
}
