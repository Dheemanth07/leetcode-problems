// Last updated: 7/6/2026, 11:21:35 AM
1class Solution {
2public:
3    int findContentChildren(vector<int>& g, vector<int>& s) {
4        sort(g.begin(), g.end());
5        sort(s.begin(), s.end());
6
7        int i = 0, j = 0;
8        int count = 0;
9
10        while (i < g.size() && j < s.size()) {
11            if (s[j] >= g[i]) {
12                count++;
13                i++;
14                j++;
15            } else
16                j++;
17        }
18
19        return count;
20    }
21};