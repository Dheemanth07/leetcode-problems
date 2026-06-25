// Last updated: 6/25/2026, 11:07:38 AM
1class Solution {
2public:
3    int removeElement(vector<int>& nums, int val) {
4        if (nums.empty())
5            return 0;
6
7        int j = 0;
8        for (int i = 0; i < nums.size(); i++)
9            if (nums[i] != val)
10                nums[j++] = nums[i];
11        return j;
12    }
13};