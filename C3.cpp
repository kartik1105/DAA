#include <iostream>
#include <cstring>
using namespace std;

// Function to check if we can transform s1 into s2
bool canTransformToAnother(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    // Create a DP table to store the results
    bool dp[len1 + 1][len2 + 1];

    // Initialize the DP table
    memset(dp, false, sizeof(dp));

    // An empty s2 can always be obtained from any s1 by deleting all characters
    dp[0][0] = true;

    // If s2 is empty, we can delete all characters from s1 to match s2
    for (int i = 1; i <= len1; i++) {
        dp[i][0] = dp[i - 1][0] && (s1[i - 1] >= 'a' && s1[i - 1] <= 'z');
    }

    // Fill the DP table
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            // If current characters match, or we can make the s1 character uppercase to match s2
            if (s1[i - 1] == s2[j - 1] || (s1[i - 1] >= 'a' && s1[i - 1] <= 'z' && toupper(s1[i - 1]) == s2[j - 1])) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            // If current character of s1 is lowercase, we can delete it
            if (s1[i - 1] >= 'a' && s1[i - 1] <= 'z') {
                dp[i][j] = dp[i][j] || dp[i - 1][j];
            }
        }
    }

    // Return the result from the bottom-right corner of the DP table
    return dp[len1][len2];
}

int main() {
    // Input strings s1 and s2
    string s1 = "daBcd";
    string s2 = "ABC";

    // Call the function to check if transformation is possible
    if (canTransformToAnother(s1, s2)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
