#include <iostream>
using namespace std;

// Function to count the number of 0s in the array
int countZeroes(int arr[], int n) {
    int low = 0, high = n - 1;
    
    // Binary search to find the first occurrence of 0
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // If we find 0, check if it's the first 0
        if (arr[mid] == 0) {
            // If mid is 0 and either it's the first element or the previous element is 1
            if (mid == 0 || arr[mid - 1] == 1) {
                return n - mid;  // The number of zeros is the difference from mid to the end
            }
            high = mid - 1;  // Keep searching in the left half
        } else {
            low = mid + 1;  // Keep searching in the right half
        }
    }
    
    // If no zero found, return 0
    return 0;
}

int main() {
    // Test case 1
    int arr1[] = {1, 1, 1, 1, 0, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Number of zeroes in arr1: " << countZeroes(arr1, n1) << endl;  // Output: 2
    
    // Test case 2
    int arr2[] = {1, 0, 0, 0, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Number of zeroes in arr2: " << countZeroes(arr2, n2) << endl;  // Output: 4
    
    return 0;
}
//O(logn)
