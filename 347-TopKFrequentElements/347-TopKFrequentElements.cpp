// Last updated: 4/3/2026, 9:49:12 PM
1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4        if (nums.empty())
5            return {};
6        int n = nums.size();
7        unordered_map<int, int> mp;
8        for (int num : nums)
9            mp[num]++;
10        vector<vector<int>> bucket(n + 1);
11        for (auto& p : mp)
12            bucket[p.second].push_back(p.first);
13        vector<int> res;
14        for (int i = bucket.size() - 1; i >= 0 && res.size() < k; i--) {
15            for (int num : bucket[i]) {
16                res.push_back(num);
17                if (res.size() == k)
18                    break;
19            }
20        }
21        return res;
22    }
23};