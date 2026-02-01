// Last updated: 2/1/2026, 7:19:06 PM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        unordered_set<char> st;
5        int l = 0, r = 0;
6        int maxc = 0;
7        int n = s.length();
8        while (r < n) {
9            if (!st.count(s[r])) {
10                st.insert(s[r++]);
11                maxc = max(maxc, r - l);
12            } else {
13                st.erase(s[l]);
14                l++;
15            }
16        }
17        return maxc;
18    }
19};