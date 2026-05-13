// Last updated: 5/13/2026, 10:45:28 PM
1class Solution {
2public:
3    int uniquePaths(int m, int n) {
4        // Create a 2D DP table of size m x n, filled with 1s.
5        // (Filling it with 1s automatically handles our top-row/left-column
6        // base cases!)
7        vector<vector<int>> dp(m, vector<int>(n, 1));
8
9        // Start at row 1, col 1 (skipping the borders we just filled)
10        for (int r = 1; r < m; r++) {
11            for (int c = 1; c < n; c++) {
12                // The Core DP Formula: Ways to get here = Ways from Above +
13                // Ways from Left
14                dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
15            }
16        }
17
18        // The bottom-right corner holds our final answer
19        return dp[m - 1][n - 1];
20    }
21};