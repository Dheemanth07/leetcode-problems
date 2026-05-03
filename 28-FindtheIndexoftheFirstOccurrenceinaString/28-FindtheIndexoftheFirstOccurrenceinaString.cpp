// Last updated: 5/3/2026, 3:44:42 PM
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
11            if (pattern[i] == pattern[len]) {
12                len++;
13                lps[i] = len;
14                i++;
15            } else {
16                if (len != 0) {
17                    len = lps[len - 1];
18                } else {
19                    lps[i] = 0;
20                    i++;
21                }
22            }
23        }
24        return lps;
25    }
26
27    int strStr(string haystack, string needle) {
28        int n = haystack.size(), m = needle.size();
29        if (m == 0)
30            return 0;
31
32        vector<int> lps = computeLPS(needle);
33
34        int i = 0, j = 0;
35
36        while (i < n) {
37            if (haystack[i] == needle[j]) {
38                i++;
39                j++;
40            }
41
42            if (j == m) {
43                return i - j;
44            } else if (i < n && haystack[i] != needle[j]) {
45                if (j != 0)
46                    j = lps[j - 1];
47                else
48                    i++;
49            }
50        }
51
52        return -1;
53    }
54};