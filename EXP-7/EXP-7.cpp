#include <bits/stdc++.h>
using namespace std;

// Recursive approach
int knapsackRecursive(int W, vector<int>& wt, vector<int>& val, int n) {
    if (n == 0 || W == 0) return 0;
    if (wt[n - 1] > W)
        return knapsackRecursive(W, wt, val, n - 1);
    else
        return max(val[n - 1] + knapsackRecursive(W - wt[n - 1], wt, val, n - 1),
                   knapsackRecursive(W, wt, val, n - 1));
}

// Dynamic Programming approach
int knapsackDP(int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    int n = wt.size();
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

// Track selected items
vector<int> trackItems(vector<int>& wt, vector<int>& val, vector<vector<int>>& dp, int W) {
    int n = wt.size(), w = W;
    vector<int> selectedItems;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selectedItems.push_back(i);
            w -= wt[i - 1];
        }
    }
    reverse(selectedItems.begin(), selectedItems.end());
    return selectedItems;
}

int main() {
    vector<int> wt = {1, 2, 3};
    vector<int> val = {10, 15, 40};
    int W = 6;
    int n = wt.size();

    cout << "0-1 Knapsack Problem using Dynamic Programming\n";
    cout << "Weights: { ";
    for (int x : wt) cout << x << " ";
    cout << "}, Values: { ";
    for (int x : val) cout << x << " ";
    cout << "}, Capacity = " << W << "\n\n";

    int recResult = knapsackRecursive(W, wt, val, n);
    cout << "Recursive Approach (Exponential): Maximum Profit = " << recResult << "\n";
    cout << "Time Complexity: O(2^n)\n\n";

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    int dpResult = knapsackDP(W, wt, val, dp);
    cout << "Dynamic Programming Approach:\n";
    cout << "Maximum Profit = " << dpResult << "\n";
    cout << "Time Complexity: O(n * W)\n";
    cout << "Space Complexity: O(n * W)\n\n";

    vector<int> selected = trackItems(wt, val, dp, W);
    cout << "Selected items (1-indexed): ";
    for (int idx : selected) cout << "Item" << idx << " ";
    cout << "\n\n";

    cout << "DP Table (for visualization):\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++)
            cout << setw(3) << dp[i][j] << " ";
        cout << "\n";
    }

    return 0;
}