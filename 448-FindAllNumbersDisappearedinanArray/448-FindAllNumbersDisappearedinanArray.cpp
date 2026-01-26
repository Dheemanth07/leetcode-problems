// Last updated: 1/26/2026, 6:43:07 PM
1class Solution {
2public:
3    vector<int> findDisappearedNumbers(vector<int>& nums) {
4        if(nums.empty()) return {};
5        int n=nums.size();
6        vector<int>res;
7        unordered_map<int,int>mp;
8        for(int num:nums)
9            mp[num]++;
10        for(int i=1;i<=n;i++)
11            if(mp.find(i)==mp.end())
12                res.push_back(i);
13        return res;
14    }
15};