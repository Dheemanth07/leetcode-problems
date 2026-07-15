// Last updated: 7/15/2026, 3:52:25 PM
1class Solution {
2public:
3    int uniquePaths(int m, int n) {
4        // Create a single 1D array representing a row, filled with 1s.
5        vector<int> dp(n, 1);
6
7        // Loop through the remaining rows (1 to m-1)
8        for (int r = 1; r < m; r++) {
9            // Loop through the columns (1 to n-1)
10            for (int c = 1; c < n; c++) {
11                // The magic of in-place updates:
12                // dp[c] is the old value (from the row above)
13                // dp[c - 1] is the new value (from the cell to the left)
14                dp[c] += dp[c - 1];
15
16                // You can also just write: dp[c] += dp[c - 1];
17            }
18        }
19
20        // The last element of our 1D array holds the final answer
21        return dp[n - 1];
22    }
23};