// Last updated: 2/19/2026, 6:31:16 PM
1class Solution {
2public:
3    int countBinarySubstrings(string s) {
4        int ans = 0;
5        int prevGroup = 0; // Length of the previous block of same characters
6        int curGroup = 1;  // Length of the current block
7
8        for (int i = 1; i < s.length(); i++) {
9            if (s[i] == s[i - 1]) {
10                curGroup++;
11            } else {
12                // We reached a boundary (e.g., from 0 to 1)
13                // The number of valid substrings between these two groups
14                ans += min(prevGroup, curGroup);
15                prevGroup = curGroup;
16                curGroup = 1;
17            }
18        }
19
20        // Add the last comparison
21        return ans + min(prevGroup, curGroup);
22    }
23};