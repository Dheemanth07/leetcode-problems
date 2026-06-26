// Last updated: 6/26/2026, 10:35:56 AM
1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4        int n1 = s1.length(), n2 = s2.length();
5
6        vector<int> freq1(26, 0), freq2(26, 0);
7
8        if (n1 > n2)
9            return false;
10
11        for (int i = 0; i < n1; i++) {
12            freq1[s1[i] - 'a']++;
13            freq2[s2[i] - 'a']++;
14        }
15
16        if (freq1 == freq2)
17            return true;
18
19        int left = 0;
20
21        for (int right = n1; right < n2; right++) {
22            freq2[s2[right] - 'a']++;
23            freq2[s2[left] - 'a']--;
24            left++;
25
26            if (freq1 == freq2)
27                return true;
28        }
29
30        return false;
31    }
32};