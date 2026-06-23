// Last updated: 6/23/2026, 4:38:35 PM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        unordered_set<char> st;
5        int l = 0, r = 0;
6        int max_length = 0;
7        int n = s.length();
8        while (r < n) {
9            if (!st.count(s[r])) {
10                st.insert(s[r++]);
11                max_length = max(max_length, r - l);
12            } else
13                st.erase(s[l++]);
14        }
15
16        return max_length;
17    }
18};