// Last updated: 7/6/2026, 11:27:23 AM
1class Solution {
2public:
3    int findContentChildren(vector<int>& g, vector<int>& s) {
4        sort(g.begin(), g.end());
5        sort(s.begin(), s.end());
6
7        int i = 0, j = 0;
8
9        while (i < g.size() && j < s.size()) {
10            if (s[j] >= g[i])
11                i++;
12            j++;
13        }
14
15        return i;
16    }
17};