// Last updated: 5/13/2026, 11:47:03 PM
1class Solution {
2public:
3    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
4        int m = obstacleGrid.size();
5        int n = obstacleGrid[0].size();
6
7        // Edge Case: If the starting block itself is an obstacle, we are dead
8        // instantly.
9        if (obstacleGrid[0][0])
10            return 0;
11
12        // Create our Space Optimized 1D Array, initialized to 0s
13        vector<int> dp(n, 0);
14
15        // Base Case: We are already standing on the first square.
16        // There is exactly 1 way to get to where we are currently standing.
17        dp[0] = 1;
18
19        for (int r = 0; r < m; r++) {
20            for (int c = 0; c < n; c++) {
21
22                // 1. The Bouncer: Are we on a boulder?
23                if (obstacleGrid[r][c] == 1)
24                    // There are ZERO ways to get here.
25                    dp[c] = 0;
26
27                // 2. The Accumulator: We are on a safe space!
28                else if (c > 0)
29                    // dp[c] currently holds the value from Above.
30                    // We add dp[c-1], which holds the value from the Left.
31                    dp[c] = dp[c] + dp[c - 1];
32                // (If c == 0, we are on the left wall, so there is no cell to
33                // our Left to add. We just keep the value from Above!)
34            }
35        }
36
37        return dp[n - 1];
38    }
39};