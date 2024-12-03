#include <iostream>
using namespace std;

// Function to move all zeroes to the end
void moveZeroesToEnd(int arr[], int left, int right) {
    // Base case: Single element
    if (left == right) return;

    // Divide: Find the middle index
    int mid = left + (right - left) / 2;

    // Recur for left and right halves
    moveZeroesToEnd(arr, left, mid);
    moveZeroesToEnd(arr, mid + 1, right);

    // Conquer: Merge the two halves and move zeroes
    int temp[right - left + 1];
    int idx = 0;

    // Add non-zero elements from left to right
    for (int i = left; i <= right; i++) {
        if (arr[i] != 0) {
            temp[idx++] = arr[i];
        }
    }

    // Add zeroes at the end
    for (int i = left; i <= right; i++) {
        if (arr[i] == 0) {
            temp[idx++] = 0;
        }
    }

    // Copy sorted elements back to the original array
    for (int i = 0; i < idx; i++) {
        arr[left + i] = temp[i];
    }
}

int main() {
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZeroesToEnd(arr, 0, n - 1);

    cout << "Array after moving zeroes to end: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
