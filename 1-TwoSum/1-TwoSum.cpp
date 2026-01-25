// Last updated: 1/25/2026, 1:40:43 PM
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target) {
4        unordered_map<int,int> mp;
5        for(int i=0;i<nums.size();i++){
6            int temp=target-nums[i];
7            if(mp.find(temp)!=mp.end())
8                return{mp[temp],i};
9            mp[nums[i]]=i;
10        }
11        return {};
12    }
13};