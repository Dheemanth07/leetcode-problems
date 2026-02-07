// Last updated: 2/7/2026, 10:07:28 PM
1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int l = 0, r = nums.size() - 1;
5        while (l < r) {
6            int mid = (l + r) / 2;
7            if (nums[mid] > nums[r])
8                l = mid + 1;
9            else
10                r = mid;
11        }
12        return nums[l];
13    }
14};