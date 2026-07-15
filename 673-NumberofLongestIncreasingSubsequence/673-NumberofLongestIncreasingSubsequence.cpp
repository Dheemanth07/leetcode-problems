// Last updated: 7/15/2026, 3:46:46 PM
1class Solution {
2public:
3    int findNumberOfLIS(vector<int>& nums) {
4        int n = nums.size();
5        if (!n)
6            return 0;
7
8        vector<int> dp(n, 1), count(n, 1);
9
10        for (int i = 1; i < n; i++) {
11            for (int j = 0; j < i; j++) {
12                if (nums[i] > nums[j]) {
13                    if (dp[j] + 1 > dp[i]) {
14                        dp[i] = 1 + dp[j];
15                        count[i] = count[j];
16                    } else if (dp[j] + 1 == dp[i])
17                        count[i] += count[j];
18                }
19            }
20        }
21
22        int maxLen = *max_element(dp.begin(), dp.end());
23        int res = 0;
24
25        for (int i = 0; i < n; i++)
26            if (dp[i] == maxLen)
27                res += count[i];
28
29        return res;
30    }
31};