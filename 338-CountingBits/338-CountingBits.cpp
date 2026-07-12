// Last updated: 7/12/2026, 8:58:03 PM
1class Solution {
2public:
3    vector<int> countBits(int n) {
4        vector<int> dp(n + 1);
5
6        dp[0] = 0;
7
8        for (int i = 1; i <= n; i++)
9            dp[i] = dp[i >> 1] + (i & 1);
10
11        return dp;
12    }
13};