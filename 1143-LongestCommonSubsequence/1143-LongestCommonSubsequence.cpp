// Last updated: 7/15/2026, 10:54:23 AM
1class Solution {
2public:
3    int longestCommonSubsequence(string text1, string text2) {
4        int s1 = text1.length(), s2 = text2.length();
5
6        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
7
8        for (int i = 0; i <= s1; i++) {
9            for (int j = 0; j <= s2; j++) {
10                if (!i || !j)
11                    dp[i][j] = 0;
12                else if (text1[i - 1] == text2[j - 1])
13                    dp[i][j] = 1 + dp[i - 1][j - 1];
14                else
15                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
16            }
17        }
18
19        return dp[s1][s2];
20    }
21};