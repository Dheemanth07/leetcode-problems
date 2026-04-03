// Last updated: 4/3/2026, 9:47:00 PM
1class Solution {
2public:
3    bool containsNearbyDuplicate(vector<int>& nums, int k) {
4        unordered_map<int, int> mp;
5        bool res = false;
6        for (int i = 0; i < nums.size(); i++) {
7            if (mp.count(nums[i]) && abs(mp[nums[i]] - i) <= k)
8                res = true;
9            mp[nums[i]] = i;
10        }
11        return res;
12    }
13};