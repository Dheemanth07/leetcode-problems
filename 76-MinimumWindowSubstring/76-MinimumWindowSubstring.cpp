// Last updated: 6/23/2026, 5:52:01 PM
1class Solution {
2public:
3    string minWindow(string s, string t) {
4        if (t.empty() || s.length() < t.length())
5            return "";
6
7        unordered_map<char, int> target, window;
8        for (char c : t)
9            target[c]++;
10
11        int left = 0, right = 0, startIdx = 0;
12        int required = target.size();
13        int formed = 0;
14        int minLen = INT_MAX;
15
16        while (right < s.length()) {
17            char c = s[right];
18            window[c]++;
19
20            if (target.count(c) && window[c] == target[c])
21                formed++;
22
23            while (left <= right && formed == required) {
24                char c = s[left];
25
26                if (right - left + 1 < minLen) {
27                    minLen = right - left + 1;
28                    startIdx = left;
29                }
30
31                window[c]--;
32
33                if (target.count(c) && window[c] < target[c])
34                    formed--;
35                left++;
36            }
37
38            right++;
39        }
40
41        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
42    }
43};
44