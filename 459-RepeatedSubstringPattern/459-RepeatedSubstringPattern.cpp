// Last updated: 5/3/2026, 3:46:10 PM
1class Solution {
2public:
3    bool repeatedSubstringPattern(string s) {
4        int n = s.length();
5
6        // ==========================================
7        // PHASE 1: Build the LPS Array
8        // ==========================================
9        vector<int> lps(n, 0);
10        int len = 0;
11        int i = 1;
12
13        while (i < n) {
14            if (s[i] == s[len]) {
15                len++;
16                lps[i] = len;
17                i++;
18            } else {
19                if (len != 0) {
20                    len = lps[len - 1]; // KMP Fallback rule
21                } else {
22                    lps[i] = 0;
23                    i++;
24                }
25            }
26        }
27
28        // ==========================================
29        // PHASE 2: The Magic Math Trick
30        // ==========================================
31        int last_lps = lps[n - 1];
32
33        // Let's break down the two conditions:
34        // 1. `last_lps > 0`: There must actually be a matching prefix and
35        // suffix!
36        //    (If the string is "abc", last_lps is 0. It's obviously not
37        //    repeating).
38        // 2. `n % (n - last_lps) == 0`: Does the core block divide perfectly
39        // into the total length?
40
41        if (last_lps > 0 && n % (n - last_lps) == 0) {
42            return true;
43        }
44
45        return false;
46    }
47};