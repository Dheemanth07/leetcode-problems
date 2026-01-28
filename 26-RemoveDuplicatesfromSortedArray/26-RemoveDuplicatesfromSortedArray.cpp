// Last updated: 1/28/2026, 8:23:04 PM
1class Solution {
2public:
3    int removeDuplicates(vector<int>& nums) {
4        if (nums.empty()) return 0;
5        
6        int slow = 0;
7        for (int fast = 1; fast < nums.size(); fast++) {
8            if (nums[fast] != nums[slow]) {
9                slow++;
10                nums[slow] = nums[fast];
11            }
12        }
13        return slow + 1;
14    }
15};