// Last updated: 6/25/2026, 11:10:25 AM
1class Solution {
2public:
3    int removeDuplicates(vector<int>& nums) {
4        if (nums.empty())
5            return 0;
6
7        int slow = 0;
8        for (int fast = 1; fast < nums.size(); fast++) {
9            if (nums[fast] != nums[slow]) 
10                nums[++slow] = nums[fast];
11        }
12        
13        return slow + 1;
14    }
15};