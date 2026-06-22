// Last updated: 6/22/2026, 7:40:59 PM
1class Solution {
2public:
3    int firstMissingPositive(vector<int>& nums) {
4        int n = nums.size();
5
6        for (int i = 0; i < n; i++)
7            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
8                swap(nums[i], nums[nums[i] - 1]);
9
10        for (int i = 0; i < n; i++)
11            if (i + 1 != nums[i])
12                return i + 1;
13
14        return n + 1;
15    }
16};