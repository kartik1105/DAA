#include <iostream>
using namespace std;

// Function to move all zeros to the end of the array
void moveZeroesToEnd(int arr[], int n) {
    int nonZeroIndex = 0; // Index to keep track of the position of the last non-zero element

    // Traverse through the array
    for (int i = 0; i < n; i++) {
        // If the current element is non-zero, move it to the nonZeroIndex position
        if (arr[i] != 0) {
            arr[nonZeroIndex] = arr[i]; // Place the non-zero element at the nonZeroIndex
            // Increment the nonZeroIndex
            nonZeroIndex++;
        }
    }

    // After placing all non-zero elements, fill the remaining positions with zeros
    for (int i = nonZeroIndex; i < n; i++) {
        arr[i] = 0; // Place zero at the remaining positions
    }
}

int main() {
    // Test case 1
    int arr1[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    moveZeroesToEnd(arr1, n1);
    
    // Output the result for test case 1
    cout << "Modified array (Test case 1): ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // Test case 2
    int arr2[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    moveZeroesToEnd(arr2, n2);
    
    // Output the result for test case 2
    cout << "Modified array (Test case 2): ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
