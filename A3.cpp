#include <iostream>
using namespace std;

// Function to count the number of trailing zeroes in factorial of x
int countTrailingZeroes(int x) {
    int count = 0;
    while (x >= 5) {
        count += x / 5;
        x /= 5;
    }
    return count;
}

// Function to find the smallest number whose factorial has at least n trailing zeroes
int findSmallestNumberWithNTrailingZeroes(int n) {
    int left = 0, right = 5 * n; // An upper bound for the search
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int zeroes = countTrailingZeroes(mid);
        
        if (zeroes >= n) {
            result = mid;
            right = mid - 1; // We try to find a smaller number
        } else {
            left = mid + 1; // We need to try a larger number
        }
    }
    
    return result;
}

int main() {
    int n;
    cout << "Enter the number of trailing zeroes: ";
    cin >> n;

    int result = findSmallestNumberWithNTrailingZeroes(n);
    cout << "The smallest number whose factorial has at least " << n << " trailing zeroes is: " << result << endl;

    return 0;
}
