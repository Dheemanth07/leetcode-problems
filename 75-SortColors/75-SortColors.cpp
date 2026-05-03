// Last updated: 5/3/2026, 9:33:32 AM
1class Solution {
2public:
3    void sortColors(vector<int>& nums) {
4        int low = 0;
5        int mid = 0;
6        int high = nums.size() - 1;
7
8        while (mid <= high) {
9            if (nums[mid] == 0) {
10                swap(nums[mid], nums[low]);
11                low++;
12                mid++;
13            } else if (nums[mid] == 1) {
14                mid++;
15            } else {
16                // nums[mid] == 2
17                swap(nums[mid], nums[high]);
18                high--;
19                // we do NOT increment mid here!
20            }
21        }
22    }
23};