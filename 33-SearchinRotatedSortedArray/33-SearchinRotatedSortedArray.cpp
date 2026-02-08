// Last updated: 2/8/2026, 8:56:03 AM
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int l = 0, r = nums.size() - 1;
5        while (l <= r) {
6            int mid = (l + r) / 2;
7            if (nums[mid] == target)
8                return mid;
9            if (nums[l] <= nums[mid]) {
10                if (target >= nums[l] && target < nums[mid])
11                    r = mid - 1;
12                else
13                    l = mid + 1;
14            } else {
15                if (target > nums[mid] && target <= nums[r])
16                    l = mid + 1;
17                else
18                    r = mid - 1;
19            }
20        }
21        return -1;
22    }
23};
24