// Last updated: 6/24/2026, 8:50:19 PM
1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int left = 0, right = nums.size() - 1;
5
6        while (left < right) {
7            int mid = left + (right - left) / 2;
8
9            if (nums[mid] > nums[right])
10                // Minimum must be in the right half
11                left = mid + 1;
12            else if (nums[mid] < nums[right])
13                // Right half is sorted, minimum is in the left half (or is mid)
14                right = mid;
15            else
16                // THE BLIND SPOT: nums[mid] == nums[right]
17                // We don't know which way to go, but it is safe to drop the
18                // rightmost duplicate.
19                right--;
20        }
21
22        return nums[left];
23    }
24};