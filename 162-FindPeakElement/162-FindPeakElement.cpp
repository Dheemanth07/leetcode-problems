// Last updated: 6/24/2026, 2:39:31 PM
1class Solution {
2public:
3    int findPeakElement(std::vector<int>& nums) {
4        int left = 0;
5        int right = nums.size() - 1;
6
7        while (left < right) {
8            int mid = left + (right - left) / 2;
9
10            // Look at the slope exactly one step to the right
11            if (nums[mid] < nums[mid + 1]) 
12                // The slope is going UP. A peak MUST exist to the right.
13                left = mid + 1;
14            else 
15                // The slope is going DOWN. A peak MUST exist to the left
16                // (or we are currently standing on the peak).
17                right = mid;
18        }
19
20        // When left == right, we have narrowed our search to exactly one peak
21        return left;
22    }
23};