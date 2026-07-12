// Last updated: 7/12/2026, 7:07:42 PM
1class Solution {
2public:
3    int findTargetSumWays(vector<int>& nums, int target) {
4        int total_sum = 0;
5        for (int num : nums)
6            total_sum += num;
7
8        // Mathematical Impossibility Checks
9        if (abs(target) > total_sum || (total_sum + target) % 2 != 0) 
10            return 0;
11
12        // Calculate our positive subset target (S1)
13        int s1 = (total_sum + target) / 2;
14        int n = nums.size();
15
16        // 1. DECLARING THE 2D ARRAY
17        // Rows = (n + 1) for items
18        // Cols = (s1 + 1) for capacities 0 to target
19        vector<vector<int>> dp(n + 1, vector<int>(s1 + 1, 0));
20
21        // 2. THE BASE CASE
22        // There is exactly 1 way to make a sum of 0 using 0 items: pick
23        // nothing.
24        dp[0][0] = 1;
25
26        // 3. THE NESTED LOOPS
27        for (int i = 1; i <= n; i++) {
28            for (int j = 0; j <= s1; j++) {
29
30                int current_num = nums[i - 1];
31
32                // Choice A: Take It (Look up and left... if it fits!)
33                if (j >= current_num)
34                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - current_num];
35
36                // Choice A: Skip It (Look straight up)
37                else
38                    dp[i][j] = dp[i - 1][j];
39            }
40        }
41
42        // The total number of ways is sitting in the bottom-right corner
43        return dp[n][s1];
44    }
45};