// Last updated: 5/2/2026, 4:26:38 PM
1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4        int n1 = s1.length(), n2 = s2.length();
5        vector<int> freq1(26, 0), freq2(26, 0);
6        if (n1 > n2)
7            return false;
8        for (int i = 0; i < n1; i++) {
9            freq1[s1[i] - 'a']++;
10            freq2[s2[i] - 'a']++;
11        }
12        if (freq1 == freq2)
13            return true;
14
15        int left = 0;
16        for (int right = n1; right < n2; right++) {
17            freq2[s2[right] - 'a']++;
18            freq2[s2[left] - 'a']--;
19            left++;
20
21            if (freq1 == freq2)
22                return true;
23        }
24        return false;
25    }
26};