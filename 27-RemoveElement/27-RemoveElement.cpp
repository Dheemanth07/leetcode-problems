// Last updated: 1/28/2026, 8:09:53 PM
1class Solution {
2public:
3    int removeElement(vector<int>& nums, int val) {
4        if(nums.empty()) return 0;
5
6        int j=0;
7        for(int i=0;i<nums.size();i++)
8            if(nums[i]!=val)
9                nums[j++]=nums[i];
10        return j;
11    }
12};