// Last updated: 7/12/2026, 9:03:31 PM
1class Solution {
2public:
3    int missingNumber(vector<int>& nums) {
4
5        int n = nums.size();
6
7        int expected = n * (n + 1) / 2;
8
9        int actual = 0;
10
11        for (int num : nums)
12            actual += num;
13
14        return expected - actual;
15    }
16};