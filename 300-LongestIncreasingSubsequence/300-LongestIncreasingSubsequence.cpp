// Last updated: 7/15/2026, 2:43:18 PM
1class Solution {
2public:
3    int lengthOfLIS(vector<int>& nums) {
4        int n = nums.size();
5
6        if (!n)
7            return 0;
8
9        vector<int> dp(n, 1);
10
11        int maxLIS = 1;
12
13        for (int i = 1; i < n; i++) {
14            for (int j = 0; j < i; j++)
15                if (nums[i] > nums[j])
16                    dp[i] = max(dp[i], 1 + dp[j]);
17
18            maxLIS = max(maxLIS, dp[i]);
19        }
20
21        return maxLIS;
22    }
23};