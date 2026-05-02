// Last updated: 5/2/2026, 6:10:58 PM
1class Solution {
2public:
3    int searchInsert(vector<int>& nums, int target) {
4        int left = 0, right = nums.size() - 1;
5        while (left <= right) {
6            int mid = left + (right - left + 1) / 2;
7            if (nums[mid] == target)
8                return mid;
9            else if (target < nums[mid])
10                right = mid - 1;
11            else
12                left = mid + 1;
13        }
14        return left;
15    }
16};