// Last updated: 5/3/2026, 10:45:43 AM
1class Solution {
2public:
3    vector<int> findAnagrams(string s, string p) {
4
5        int n1 = s.length(), n2 = p.length();
6
7        vector<int> freq1(26, 0), freq2(26, 0);
8
9        if (n2 > n1)
10            return {};
11
12        vector<int> res;
13
14        for (int i = 0; i < n2; i++) {
15            freq1[s[i] - 'a']++;
16            freq2[p[i] - 'a']++;
17        }
18
19        if (freq1 == freq2)
20            res.push_back(0);
21
22        int left = 0;
23
24        for (int right = n2; right < n1; right++) {
25
26            freq1[s[right] - 'a']++;
27            freq1[s[left] - 'a']--;
28            left++;
29
30            if (freq1 == freq2)
31                res.push_back(left);
32        }
33        return res;
34    }
35};