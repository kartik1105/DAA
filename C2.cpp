#include <iostream>
using namespace std;

// Function to find the number of ways to make sum using given coins
int coinChange(int coins[], int N, int sum) {
    // Create a table to store results of subproblems
    int dp[sum + 1];

    // Initialize dp[0] as 1 because there is 1 way to make sum 0 (by choosing no coins)
    dp[0] = 1;

    // Initialize all other dp[] values as 0
    for (int i = 1; i <= sum; i++) {
        dp[i] = 0;
    }

    // Iterate over all coins
    for (int i = 0; i < N; i++) {
        // Update the dp[] table by considering each coin
        for (int j = coins[i]; j <= sum; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    // The answer will be stored in dp[sum]
    return dp[sum];
}

int main() {
    // Input: sum and coins array
    int sum = 4;
    int coins[] = {1, 2, 3};
    int N = sizeof(coins) / sizeof(coins[0]);

    // Call the coinChange function and print the result
    int result = coinChange(coins, N, sum);
    cout << "Number of ways to make sum " << sum << " is: " << result << endl;

    return 0;
}
