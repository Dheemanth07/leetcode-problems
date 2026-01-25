// Last updated: 1/25/2026, 6:38:36 PM
1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4        if(nums.empty()) return {};
5        int n=nums.size();
6        unordered_map<int,int>mp;
7        for(int num:nums)
8            mp[num]++;
9        vector<vector<int>>bucket(n+1);
10        for(auto &p:mp)
11            bucket[p.second].push_back(p.first);
12        vector<int>res;
13        for(int i=bucket.size()-1;i>=0 && res.size()<k ;i--){
14            for(int num:bucket[i]){
15                res.push_back(num);
16                if(res.size()==k) break;
17            }
18        }
19        return res;
20    }
21};