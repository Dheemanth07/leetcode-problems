// Last updated: 2/3/2026, 7:58:23 PM
1class Solution {
2public:
3    string minWindow(string s, string t) {
4        if (s.empty() || t.empty())
5            return "";
6        unordered_map<char, int> target, window;
7        for (char c : t)
8            target[c]++;
9        int left = 0, right = 0, startIdx = 0;
10        int required = target.size();
11        int formed = 0;
12        int minLen = INT_MAX;
13        while (right < s.length()) {
14            char c = s[right];
15            window[c]++;
16            if (target.count(c) && window[c] == target[c])
17                formed++;
18            while (left <= right && formed == required) {
19                char c = s[left];
20                if (right - left + 1 < minLen) {
21                    minLen = right - left + 1;
22                    startIdx = left;
23                }
24                window[c]--;
25                if (target.count(c) && window[c] < target[c])
26                    formed--;
27                left++;
28            }
29            right++;
30        }
31        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
32    }
33};
34