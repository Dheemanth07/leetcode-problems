// Last updated: 5/2/2026, 7:32:06 AM
1class Solution {
2public:
3    int firstMissingPositive(vector<int>& nums) {
4        if (!nums.size())
5            return 1;
6
7        int n = nums.size();
8
9        for (int i = 0; i < n; i++)
10            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
11                swap(nums[nums[i] - 1], nums[i]);
12
13        for (int i = 0; i < n; i++)
14            if (nums[i] != i + 1)
15                return i + 1;
16
17        return n + 1;
18    }
19};