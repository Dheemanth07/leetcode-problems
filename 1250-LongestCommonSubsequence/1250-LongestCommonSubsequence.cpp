// Last updated: 7/16/2026, 9:42:03 PM
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.length(), s2 = text2.length();

        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));

        for (int i = 1; i <= s1; i++) {
            for (int j = 1; j <= s2; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[s1][s2];
    }
};