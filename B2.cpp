#include <iostream>
using namespace std;

// Function to calculate maximum profit using a greedy approach
int maximizeProfit(int arr[], int N) {
    int profit = 0;

    // Traverse through the array and accumulate profit
    // by buying at lower prices and selling at higher prices.
    for (int i = 1; i < N; i++) {
        // If the current day's price is greater than the previous day's price,
        // we simulate selling the stock on the current day and buying on the previous day
        if (arr[i] > arr[i - 1]) {
            profit += arr[i] - arr[i - 1];
        }
    }

    return profit;
}

int main() {
    // Input array
    int arr[] = {2, 3, 5};
    int N = sizeof(arr) / sizeof(arr[0]); // Number of days

    // Call the maximizeProfit function
    int result = maximizeProfit(arr, N);

    // Output the result
    cout << "Maximum profit: " << result << endl;

    return 0;
}
