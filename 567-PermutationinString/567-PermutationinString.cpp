// Last updated: 2/2/2026, 7:15:50 PM
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
14        for (int i = n1; i < n2; i++) {
15            freq2[s2[i] - 'a']++;
16            freq2[s2[i - n1] - 'a']--;
17            if (freq1 == freq2)
18                return true;
19        }
20        return false;
21    }
22};