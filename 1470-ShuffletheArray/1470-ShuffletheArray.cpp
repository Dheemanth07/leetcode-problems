// Last updated: 1/26/2026, 6:02:26 PM
1class Solution {
2public:
3    vector<int> shuffle(vector<int>& nums, int n) {
4        if(nums.empty()) return {};
5        vector<int>res;
6        int l=0,r=n;
7        while(l<n && r<2*n){
8            res.push_back(nums[l++]);
9            res.push_back(nums[r++]);
10        }
11        return res;
12    }
13};