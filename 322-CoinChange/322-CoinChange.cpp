// Last updated: 7/12/2026, 7:50:31 PM
1class Solution {
2public:
3    int coinChange(vector<int>& coins, int amount) {
4        int n = coins.size();
5        int max_val = amount + 1; // Our "Infinity"
6
7        // 1. DECLARING THE 2D ARRAY
8        // Rows = (n + 1) for the coin types
9        // Cols = (amount + 1) for capacities 0 to amount
10        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, max_val));
11
12        // 2. THE BASE CASES
13        // Amount 0 takes 0 coins, regardless of which coins we are allowed to
14        // use
15        for (int i = 0; i <= n; i++)
16            dp[i][0] = 0;
17
18        // 3. THE NESTED LOOPS
19        for (int i = 1; i <= n; i++) {
20            for (int j = 1; j <= amount; j++) {
21
22                int current_coin = coins[i - 1];
23
24                // Choice A: Take It (Look LEFT on the SAME ROW!)
25                if (coins[i - 1] <= j)
26                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
27
28                // Choice B: Skip It (Look straight UP)
29                else
30                    dp[i][j] = dp[i - 1][j];
31            }
32        }
33
34        // Return the bottom-right corner. If it's still infinity, it was
35        // impossible.
36        if (dp[n][amount] == max_val)
37            return -1;
38
39        return dp[n][amount];
40    }
41};