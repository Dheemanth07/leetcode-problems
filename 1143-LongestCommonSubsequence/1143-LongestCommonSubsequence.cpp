// Last updated: 7/15/2026, 11:05:19 AM
1class Solution {
2public:
3    int longestCommonSubsequence(string text1, string text2) {
4        int s1 = text1.length(), s2 = text2.length();
5
6        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
7
8        for (int i = 1; i <= s1; i++) {
9            for (int j = 1; j <= s2; j++) {
10                if (text1[i - 1] == text2[j - 1])
11                    dp[i][j] = 1 + dp[i - 1][j - 1];
12                else
13                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
14            }
15        }
16
17        return dp[s1][s2];
18    }
19};