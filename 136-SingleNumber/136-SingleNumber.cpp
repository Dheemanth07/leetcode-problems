// Last updated: 1/27/2026, 7:59:13 PM
1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int res = 0;
5        for (int i = 0; i < nums.size(); i++)
6            res ^= nums[i];
7        return res;
8    }
9};