#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// Function to find all distinct subsets
void findSubsets(int arr[], int n) {
    // Use a set to store subsets as strings to avoid duplicates
    set<string> subsets;

    // Loop through all possible subsets using bitmasking
    for (int i = 0; i < (1 << n); i++) {
        string subset = "{ ";
        
        // Check each bit of i
        for (int j = 0; j < n; j++) {
            // If the j-th bit of i is set, include arr[j] in the subset
            if (i & (1 << j)) {
                subset += to_string(arr[j]) + " ";
            }
        }
        
        subset += "}";
        
        // Add the subset to the set (duplicates will be automatically removed)
        subsets.insert(subset);
    }

    // Print all distinct subsets
    for (auto subset : subsets) {
        cout << subset << endl;
    }
}

int main() {
    int arr[] = {1, 2, 2};  // Input set
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array to ensure subsets are generated in lexicographical order
    sort(arr, arr + n);

    // Find and print all distinct subsets
    findSubsets(arr, n);

    return 0;
}
