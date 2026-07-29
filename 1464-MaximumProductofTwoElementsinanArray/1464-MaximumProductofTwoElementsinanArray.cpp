// Last updated: 7/29/2026, 5:42:32 PM
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5
6        return (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
7    }
8};