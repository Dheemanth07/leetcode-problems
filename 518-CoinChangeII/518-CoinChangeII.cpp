// Last updated: 7/12/2026, 8:26:45 PM
1class Solution {
2public:
3    int change(int amount, vector<int>& coins) {
4        int n = coins.size();
5
6        // 1. DECLARING THE 2D ARRAY
7        // Rows = (n + 1) for the coin types
8        // Cols = (amount + 1) for capacities 0 to amount
9        vector<vector<unsigned int>> dp(n + 1,
10                                        vector<unsigned int>(amount + 1, 0));
11
12        // 2. THE BASE CASES
13        // There is exactly 1 way to make amount 0: pick no coins
14        for (int i = 0; i <= n; i++)
15            dp[i][0] = 1;
16
17        // 3. THE NESTED LOOPS
18        for (int i = 1; i <= n; i++) {
19            for (int j = 1; j <= amount; j++) {
20
21                int current_coin = coins[i - 1];
22
23                // Choice A: Skip It (Look straight UP)
24                dp[i][j] = dp[i - 1][j];
25
26                // Choice B: Take It (Look LEFT on the SAME ROW)
27                if (j >= current_coin) {
28                    // ADD the paths together!
29                    dp[i][j] = dp[i][j] + dp[i][j - current_coin];
30                }
31            }
32        }
33
34        // Return the bottom-right corner
35        return (int)dp[n][amount];
36    }
37};