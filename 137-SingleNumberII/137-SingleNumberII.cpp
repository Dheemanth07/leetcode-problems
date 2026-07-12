// Last updated: 7/12/2026, 8:43:07 PM
1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4
5        int ans = 0;
6
7        for (int bit = 0; bit < 32; bit++) {
8
9            int count = 0;
10
11            for (int num : nums) {
12
13                if ((num >> bit) & 1)
14                    count++;
15            }
16
17            if (count % 3)
18                ans |= (1 << bit);
19        }
20
21        return ans;
22    }
23};