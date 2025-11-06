#include <bits/stdc++.h>
using namespace std;

// Recursive approach
bool subsetSumRecursive(vector<int>& arr, int n, int sum) {
    if (sum == 0) return true;
    if (n == 0 && sum != 0) return false;
    if (arr[n - 1] > sum) return subsetSumRecursive(arr, n - 1, sum);
    return subsetSumRecursive(arr, n - 1, sum) || subsetSumRecursive(arr, n - 1, sum - arr[n - 1]);
}

// Dynamic Programming approach
bool subsetSumDP(vector<int>& arr, int sum, vector<vector<bool>>& dp) {
    int n = arr.size();
    for (int i = 0; i <= n; i++) dp[i][0] = true;
    for (int j = 1; j <= sum; j++) dp[0][j] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }
    return dp[n][sum];
}

// Track subset elements
vector<int> getSubsetElements(vector<int>& arr, vector<vector<bool>>& dp, int sum) {
    vector<int> subset;
    int n = arr.size(), i = n, j = sum;
    while (i > 0 && j > 0) {
        if (dp[i][j] && !dp[i - 1][j]) {
            subset.push_back(arr[i - 1]);
            j -= arr[i - 1];
        }
        i--;
    }
    reverse(subset.begin(), subset.end());
    return subset;
}

int main() {
    vector<int> arr = {3, 2, 7, 1};
    int sum = 6;
    int n = arr.size();

    cout << "Subset Sum Problem using Dynamic Programming\n";
    cout << "Set = { ";
    for (int x : arr) cout << x << " ";
    cout << "}, Target Sum = " << sum << "\n\n";

    bool recResult = subsetSumRecursive(arr, n, sum);
    cout << "Recursive Approach: " << (recResult ? "Subset Exists" : "Subset Does Not Exist") << "\n";
    cout << "Time Complexity: O(2^n)\n\n";

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    bool dpResult = subsetSumDP(arr, sum, dp);
    cout << "Dynamic Programming Approach: " << (dpResult ? "Subset Exists" : "Subset Does Not Exist") << "\n";
    cout << "Time Complexity: O(n * sum)\n";
    cout << "Space Complexity: O(n * sum)\n\n";

    if (dpResult) {
        vector<int> subset = getSubsetElements(arr, dp, sum);
        cout << "Subset with sum " << sum << " is: { ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
    } else {
        cout << "No subset found with the given sum.\n";
    }

    return 0;
}