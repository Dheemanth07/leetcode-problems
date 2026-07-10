// Last updated: 7/10/2026, 6:33:02 PM
1class Solution {
2public:
3    string longestPalindrome(string s) {
4        int len = s.length();
5        if (len <= 1)
6            return s;
7
8        int maxLen = 0;
9        int start = 0;      // We will track the start index instead of the string itself
10
11        for (int i = 0; i < len; i++) {
12
13            // ==========================================
14            // 1. Check for ODD length palindromes
15            // ==========================================
16            int left = i, right = i;
17
18            while (left >= 0 && right < len && s[left] == s[right]) {
19                int curLen = right - left + 1;
20
21                if (curLen > maxLen) {
22                    maxLen = curLen;
23                    start = left; // Just save where the palindrome starts!
24                }
25                
26                left--;
27                right++;
28            }
29
30            // ==========================================
31            // 2. Check for EVEN length palindromes
32            // ==========================================
33            left = i, right = i + 1; // Center is between i and i+1
34
35            while (left >= 0 && right < len && s[left] == s[right]) {
36                int curLen = right - left + 1;
37
38                if (curLen > maxLen) {
39                    maxLen = curLen;
40                    start = left; // Just save where the palindrome starts!
41                }
42
43                left--;
44                right++;
45            }
46        }
47
48        // Only create the substring once at the very end. This is much faster!
49        return s.substr(start, maxLen);
50    }
51};