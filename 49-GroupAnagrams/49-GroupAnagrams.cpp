// Last updated: 6/26/2026, 10:19:36 AM
1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4        unordered_map<string, vector<string>> mp;
5
6        for (string s : strs) {
7            vector<int> freq(26, 0);
8            for (char c : s)
9                freq[c - 'a']++;
10
11            string key;
12            for (int i = 0; i < 26; i++)
13                key += "#" + to_string(freq[i]);
14
15            mp[key].push_back(s);
16        }
17
18        vector<vector<string>> ans;
19        for (auto& p : mp)
20            ans.push_back(p.second);
21
22        return ans;
23    }
24};
25