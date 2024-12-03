#include <iostream>
using namespace std;

// Function to check if there's a subset with the given sum
bool isSubsetSum(int set[], int n, int sum) {
    // Create a DP table with dimensions (n+1) x (sum+1)
    bool dp[n + 1][sum + 1];

    // Initialize the DP table
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true; // A sum of 0 is always possible (by selecting no elements)
    }
    for (int j = 1; j <= sum; j++) {
        dp[0][j] = false; // A non-zero sum is not possible with 0 elements
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]]; // Include or exclude the current element
            } else {
                dp[i][j] = dp[i - 1][j]; // Exclude the current element
            }
        }
    }

    // Return the value in the bottom-right corner of the DP table
    return dp[n][sum];
}

int main() {
    int set1[] = {3, 34, 4, 12, 5, 2};
    int sum1 = 9;
    int n1 = sizeof(set1) / sizeof(set1[0]);
    cout << "Is there a subset with sum " << sum1 << ": " << (isSubsetSum(set1, n1, sum1) ? "True" : "False") << endl;

    int set2[] = {3, 34, 4, 12, 5, 2};
    int sum2 = 30;
    int n2 = sizeof(set2) / sizeof(set2[0]);
    cout << "Is there a subset with sum " << sum2 << ": " << (isSubsetSum(set2, n2, sum2) ? "True" : "False") << endl;

    return 0;
}
