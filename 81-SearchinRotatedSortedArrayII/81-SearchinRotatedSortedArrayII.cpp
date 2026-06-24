// Last updated: 6/24/2026, 6:36:48 PM
1class Solution {
2public:
3    bool search(vector<int>& nums, int target) {
4        int left = 0, right = nums.size() - 1;
5
6        while (left <= right) {
7            int mid = left + (right - left) / 2;
8
9            if (nums[mid] == target)
10                return true;
11
12            // Handle the blind spot
13            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
14                left++;
15                right--;
16                continue; // Skip the rest of the loop and recalculate mid
17            }
18
19            // ... The rest is identical to Part 1 ...
20            if (nums[left] <= nums[mid]) {
21                if (nums[left] <= target && target < nums[mid])
22                    right = mid - 1;
23                else
24                    left = mid + 1;
25            } else {
26                if (nums[mid] < target && target <= nums[right])
27                    left = mid + 1;
28                else
29                    right = mid - 1;
30            }
31        }
32        return false;
33    }
34};