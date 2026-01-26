// Last updated: 1/26/2026, 5:49:20 PM
1class Solution {
2public:
3    vector<int> getConcatenation(vector<int>& nums) {
4        if (nums.empty())
5            return {};
6        int n = nums.size();
7        vector<int> ans;
8        for(int i=0;i<n;i++)
9            ans.push_back(nums[i]);
10        for(int i=0;i<n;i++)
11            ans.push_back(nums[i]);
12        return ans;
13    }
14};