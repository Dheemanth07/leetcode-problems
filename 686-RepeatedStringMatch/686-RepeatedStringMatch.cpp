// Last updated: 5/3/2026, 3:48:40 PM
1class Solution {
2public:
3    int repeatedStringMatch(string a, string b) {
4        string haystack = a;
5        int count = 1;
6
7        // Step 1: Build the haystack until it is at least the size of the
8        // needle (b)
9        while (haystack.length() < b.length()) {
10            haystack += a;
11            count++;
12        }
13
14        // Step 2: Run KMP Phase 2
15        if (kmpSearch(haystack, b)) {
16            return count;
17        }
18
19        // Step 3: The Buffer Check.
20        // Add one more repetition just in case the pattern crosses the final
21        // boundary.
22        haystack += a;
23        if (kmpSearch(haystack, b)) {
24            return count + 1;
25        }
26
27        // Step 4: If it's still not found, it's impossible.
28        return -1;
29    }
30
31private:
32    // This is your exact KMP Template!
33    bool kmpSearch(string haystack, string needle) {
34        int n = haystack.length();
35        int m = needle.length();
36        if (m == 0)
37            return true;
38
39        // ==========================================
40        // PHASE 1: Build LPS Array
41        // ==========================================
42        vector<int> lps(m, 0);
43        int len = 0;
44        int i = 1;
45
46        while (i < m) {
47            if (needle[i] == needle[len]) {
48                len++;
49                lps[i] = len;
50                i++;
51            } else {
52                if (len != 0) {
53                    len = lps[len - 1];
54                } else {
55                    lps[i] = 0;
56                    i++;
57                }
58            }
59        }
60
61        // ==========================================
62        // PHASE 2: The KMP Search
63        // ==========================================
64        int text_ptr = 0;
65        int pat_ptr = 0;
66
67        while (text_ptr < n) {
68            if (haystack[text_ptr] == needle[pat_ptr]) {
69                text_ptr++;
70                pat_ptr++;
71            }
72
73            if (pat_ptr == m) {
74                return true; // We only need to know IF it exists, not where.
75            } else if (text_ptr < n && haystack[text_ptr] != needle[pat_ptr]) {
76                if (pat_ptr > 0) {
77                    pat_ptr = lps[pat_ptr - 1]; // KMP Fallback
78                } else {
79                    text_ptr++;
80                }
81            }
82        }
83
84        return false;
85    }
86};