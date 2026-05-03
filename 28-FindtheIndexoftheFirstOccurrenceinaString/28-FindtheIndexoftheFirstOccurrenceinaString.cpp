// Last updated: 5/3/2026, 11:34:07 AM
1#include <string>
2
3class Solution {
4public:
5    int strStr(std::string haystack, std::string needle) {
6        int n = haystack.length();
7        int m = needle.length();
8
9        // Edge case: An empty needle is technically always found at index 0
10        if (m == 0)
11            return 0;
12
13        // Loop 'i' is our Starting Line.
14        // We only go up to (n - m) because anything after that is too short to
15        // hold the needle.
16        for (int i = 0; i <= n - m; i++) {
17
18            int j = 0;
19
20            // Loop 'j' is our Runner.
21            // It checks if the characters match, offset by our starting line
22            // 'i'.
23            while (j < m && haystack[i + j] == needle[j]) {
24                j++; // Match! Take another step.
25            }
26
27            // If the Runner made it to the very end of the needle, we found it!
28            if (j == m) {
29                return i;
30            }
31
32            // If we didn't return, the while loop broke early due to a
33            // mismatch. The outer 'for' loop will automatically increment 'i'
34            // and we try again.
35        }
36
37        // If we check every single valid starting line and never return, it
38        // doesn't exist.
39        return -1;
40    }
41};