// Problem Statement No.03
// Implement a problem of smallest number with at least n trailing 0s in factorial.
// Given a number n. The task is to find the smallest number whose factorial contains at least n trailing 0s.
// Input: n=1       Output: 5
// Input: n=6       Output: 25

#include <iostream>
using namespace std;

// Function to find the smallest number whose factorial has at least 'n' trailing zeroes
int findNum(int n)
{
    int num = 1; // Start from 1
    int cnt = 0; // Variable to count the number of trailing zeroes

    // Infinite loop to check each number's factorial for trailing zeroes
    while (true)
    {
        int temp = num; // Temporary variable to hold the current number
        // Count how many times the number is divisible by 5 (this determines the number of trailing zeroes)
        while (temp % 5 == 0)
        {
            cnt++; // Increment the count of trailing zeroes
            temp /= 5; // Divide by 5 to check the next factor of 5
        }
        
        // If the number of trailing zeroes is greater than or equal to 'n', return the current number
        if (cnt >= n)
        {
            return num;
        }
        
        num++; // Increment the number to check the next number
    }
}

int main()
{
    int n;
    // Prompt the user to enter the number of trailing zeroes
    cout << "Enter the number of trailing zeroes" << endl;
    cin >> n;

    // Call the function and display the result
    cout << findNum(n) << " is the smallest number having " << n << " number of trailing zeroes" << endl;
    
    return 0;
}

