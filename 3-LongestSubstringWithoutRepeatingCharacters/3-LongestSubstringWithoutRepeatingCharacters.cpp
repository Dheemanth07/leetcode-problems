// Last updated: 6/23/2026, 4:39:34 PM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        int n = s.length();
5
6        unordered_set<char> st;
7
8        int l = 0, r = 0;
9        int max_length = 0;
10
11        while (r < n) {
12            if (!st.count(s[r])) {
13                st.insert(s[r++]);
14                max_length = max(max_length, r - l);
15            } else
16                st.erase(s[l++]);
17        }
18
19        return max_length;
20    }
21};