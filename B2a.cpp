#include <iostream>
using namespace std;

// Function to calculate the maximum profit
int maximizeProfit(int arr[], int n) {
    if (n == 0) return 0;

    int minPrice = arr[0]; // Initialize the minimum price
    int maxProfit = 0;     // Initialize the maximum profit

    for (int i = 1; i < n; i++) {
        // Update the minimum price if a lower price is found
        if (arr[i] < minPrice) {
            minPrice = arr[i];
        }

        // Calculate the profit if sold on the current day
        int profit = arr[i] - minPrice;

        // Update the maximum profit
        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }

    return maxProfit;
}

int main() {
    int arr1[] = {2, 3, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Maximum Profit: " << maximizeProfit(arr1, n1) << endl;

    int arr2[] = {8, 5, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Maximum Profit: " << maximizeProfit(arr2, n2) << endl;

    return 0;
}
