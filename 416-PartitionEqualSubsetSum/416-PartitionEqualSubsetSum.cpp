// Last updated: 7/9/2026, 12:23:58 PM
1class Solution {
2public:
3    bool canPartition(vector<int>& nums) {
4        int total_sum = 0;
5
6        for (int num : nums)
7            total_sum += num;
8
9        if (total_sum % 2)
10            return false;
11
12        int target = total_sum / 2;
13
14        int n = nums.size();
15        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
16
17        for (int i = 0; i <= n; i++)
18            dp[i][0] = true;
19
20        for (int i = 1; i <= n; i++) {
21            for (int j = 1; j <= target; j++) {
22                if (nums[i - 1] <= j)
23                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
24                else
25                    dp[i][j] = dp[i - 1][j];
26            }
27        }
28
29        return dp[n][target];
30    }
31};
32