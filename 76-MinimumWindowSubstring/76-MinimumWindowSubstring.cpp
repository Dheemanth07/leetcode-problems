// Last updated: 5/2/2026, 4:18:38 PM
1class Solution {
2public:
3    string minWindow(string s, string t) {
4        if (t.empty() || s.length() < t.length())
5            return "";
6
7        unordered_map<char, int> target, window;
8        for (char c : t)
9            target[c]++;
10        int left = 0, right = 0, startIdx = 0;
11        int required = target.size();
12        int formed = 0;
13        int minLen = INT_MAX;
14        while (right < s.length()) {
15            char c = s[right];
16            window[c]++;
17            if (target.count(c) && window[c] == target[c])
18                formed++;
19            while (left <= right && formed == required) {
20                char c = s[left];
21                if (right - left + 1 < minLen) {
22                    minLen = right - left + 1;
23                    startIdx = left;
24                }
25                window[c]--;
26                if (target.count(c) && window[c] < target[c])
27                    formed--;
28                left++;
29            }
30            right++;
31        }
32        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
33    }
34};
35