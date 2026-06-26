// Last updated: 6/26/2026, 10:18:56 AM
1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4        unordered_map<string, vector<string>> mp;
5
6        for (string str : strs) {
7            vector<int> freq(26, 0);
8            for (char c : str)
9                freq[c - 'a']++;
10
11            string key = "";
12            for (int i = 0; i < 26; i++)
13                key += "#" + to_string(freq[i]);
14
15            mp[key].push_back(str);
16        }
17
18        vector<vector<string>> result;
19
20        for (auto& i : mp)
21            result.push_back(move(i.second));
22
23        return result;
24    }
25};