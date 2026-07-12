// Last updated: 7/12/2026, 8:45:10 PM
1class Solution {
2public:
3    vector<int> singleNumber(vector<int>& nums) {
4
5        int xr = 0;
6
7        for (int num : nums)
8            xr ^= num;
9
10        unsigned int mask = (unsigned int)xr & (-(unsigned int)xr);
11
12        int a = 0, b = 0;
13
14        for (int num : nums) {
15            if ((unsigned int)num & mask)
16                a ^= num;
17            else
18                b ^= num;
19        }
20
21        return {a, b};
22    }
23};