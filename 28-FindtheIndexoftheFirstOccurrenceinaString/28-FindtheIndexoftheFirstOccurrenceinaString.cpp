// Last updated: 6/26/2026, 1:45:33 PM
1class Solution {
2public:
3    vector<int> computeLPS(string pattern) {
4        int m = pattern.size();
5        vector<int> lps(m, 0);
6
7        int len = 0;
8        int i = 1;
9
10        while (i < m) {
11            if (pattern[i] == pattern[len])
12                lps[i++] = ++len;
13            else {
14                if (len != 0)
15                    len = lps[len - 1];
16                else
17                    lps[i++] = 0;
18            }
19        }
20        return lps;
21    }
22
23    int strStr(string haystack, string needle) {
24        int n = haystack.size(), m = needle.size();
25        if (m == 0)
26            return 0;
27
28        vector<int> lps = computeLPS(needle);
29
30        int i = 0, j = 0;
31
32        while (i < n) {
33            if (haystack[i] == needle[j]) {
34                i++;
35                j++;
36            }
37
38            if (j == m)
39                return i - j;
40            else if (i < n && haystack[i] != needle[j]) {
41                if (j != 0)
42                    j = lps[j - 1];
43                else
44                    i++;
45            }
46        }
47
48        return -1;
49    }
50};