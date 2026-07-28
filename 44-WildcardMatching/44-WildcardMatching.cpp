// Last updated: 7/28/2026, 4:53:36 PM
1class Solution {
2public:
3    bool isMatch(string s, string p) {
4        int slen = s.length(), plen = p.length();
5
6        vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
7
8        dp[0][0] = true;
9
10        for (int i = 1; i <= plen; i++)
11            if (p[i - 1] == '*')
12                dp[0][i] = dp[0][i - 1];
13
14        for (int i = 1; i <= slen; i++) {
15            for (int j = 1; j <= plen; j++) {
16                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
17                    dp[i][j] = dp[i - 1][j - 1];
18                else if (p[j - 1] == '*')
19                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
20            }
21        }
22
23        return dp[slen][plen];
24    }
25};