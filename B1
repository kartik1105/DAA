#include <iostream>
#include <algorithm>
using namespace std;

// Structure to represent a shop with start and end times
struct Shop {
    int start, end;
};

// Comparator to sort shops based on their ending times
bool compareShops(Shop a, Shop b) {
    return a.end < b.end;
}

// Function to find the maximum number of shops that can be visited
int maxShopsVisited(int S[], int E[], int N, int K) {
    Shop shops[N];

    // Create a list of shops with start and end times
    for (int i = 0; i < N; i++) {
        shops[i] = {S[i], E[i]};
    }

    // Sort shops by their ending times
    sort(shops, shops + N, compareShops);

    // Array to track the end times of K people
    int people[K];
    for (int i = 0; i < K; i++) {
        people[i] = 0; // Initialize end times as 0 (no shops visited yet)
    }

    int count = 0; // Count of shops visited

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            // If the current person can visit this shop
            if (people[j] <= shops[i].start) {
                people[j] = shops[i].end; // Update the end time for this person
                count++; // Increment the count of shops visited
                break; // Move to the next shop
            }
        }
    }

    return count;
}

int main() {
    int S1[] = {1, 8, 3, 2, 6};
    int E1[] = {5, 10, 6, 5, 9};
    int K1 = 2;
    int N1 = sizeof(S1) / sizeof(S1[0]);
    cout << "Maximum shops visited: " << maxShopsVisited(S1, E1, N1, K1) << endl;

    int S2[] = {1, 2, 3};
    int E2[] = {3, 4, 5};
    int K2 = 2;
    int N2 = sizeof(S2) / sizeof(S2[0]);
    cout << "Maximum shops visited: " << maxShopsVisited(S2, E2, N2, K2) << endl;

    return 0;
}
