// Last updated: 7/5/2026, 7:25:28 PM
1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4        if (nums.empty())
5            return {};
6
7        int n = nums.size();
8        unordered_map<int, int> mp;
9
10        for (int num : nums)
11            mp[num]++;
12
13        vector<vector<int>> bucket(n + 1);
14
15        for (auto& p : mp)
16            bucket[p.second].push_back(p.first);
17
18        vector<int> res;
19
20        for (int i = bucket.size() - 1; i >= 0 && res.size() < k; i--) {
21            for (int num : bucket[i]) {
22                res.push_back(num);
23
24                if (res.size() == k)
25                    break;
26            }
27        }
28
29        return res;
30    }
31};