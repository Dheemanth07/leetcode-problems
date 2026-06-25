// Last updated: 6/25/2026, 12:15:38 PM
1class Solution {
2public:
3    void sortColors(vector<int>& nums) {
4        int low = 0;
5        int mid = 0;
6        int high = nums.size() - 1;
7
8        while (mid <= high) {
9            if (!nums[mid])
10                swap(nums[mid++], nums[low++]);
11            else if (nums[mid] == 1)
12                mid++;
13            else
14                // nums[mid] == 2
15                swap(nums[mid], nums[high--]);
16            // we do NOT increment mid here!
17        }
18    }
19};