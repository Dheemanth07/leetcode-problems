// Last updated: 2/2/2026, 5:52:51 PM
1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4        int maxcount = 0, left = 0, maxlen = 0;
5        vector<int> count(26, 0);
6        for (int right = 0; right < s.length(); right++) {
7            count[s[right] - 'A']++;
8            maxcount = max(maxcount, count[s[right] - 'A']);
9
10            while ((right - left + 1) - maxcount > k) {
11                count[s[left] - 'A']--;
12                left++;
13            }
14            maxlen = max(maxlen, right - left + 1);
15        }
16        return maxlen;
17    }
18};