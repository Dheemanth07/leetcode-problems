// Last updated: 1/29/2026, 6:53:08 PM
1class Solution {
2public:
3    bool isPalindrome(string s) {
4        int l = 0, r = s.size() - 1;
5        while (l < r) {
6            while (l < r && !isalnum(s[l]))
7                l++;
8            while (l < r && !isalnum(s[r]))
9                r--;
10            if (tolower(s[l]) != tolower(s[r]))
11                return false;
12            l++;
13            r--;
14        }
15        return true;
16    }
17};