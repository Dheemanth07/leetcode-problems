// Last updated: 5/2/2026, 6:30:48 PM
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int left = 0, right = nums.size() - 1;
5
6        while (left <= right) {
7            int mid = left + (right - left) / 2;
8
9            if (nums[mid] == target)
10                return mid;
11
12            // Step 1: Is the LEFT half strictly sorted?
13            if (nums[left] <= nums[mid]) {
14
15                // Step 2: Is the target inside this sorted left half?
16                if (target >= nums[left] && target < nums[mid]) {
17                    right = mid - 1; // Yes! Throw away the right half.
18                } else {
19                    left = mid + 1; // No! Throw away the left half.
20                }
21
22            }
23            // Step 1 Alternative: The RIGHT half must be strictly sorted.
24            else {
25
26                // Step 2: Is the target inside this sorted right half?
27                if (target > nums[mid] && target <= nums[right]) {
28                    left = mid + 1; // Yes! Throw away the left half.
29                } else {
30                    right = mid - 1; // No! Throw away the right half.
31                }
32            }
33        }
34        return -1;
35    }
36};
37