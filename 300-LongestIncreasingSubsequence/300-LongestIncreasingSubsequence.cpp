// Last updated: 7/15/2026, 2:41:29 PM
1class Solution {
2public:
3    int lengthOfLIS(vector<int>& nums) {
4        int n = nums.size();
5
6        if(!n) return 0;
7        
8        vector<int> dp(n + 1, 1);
9
10        int maxLIS = 1;
11
12        for (int i = 1; i < n; i++) {
13            for (int j = 0; j < i; j++)
14                if (nums[i] > nums[j])
15                    dp[i] = max(dp[i], 1 + dp[j]);
16                    
17            maxLIS = max(maxLIS, dp[i]);
18        }
19
20        return maxLIS;
21    }
22};