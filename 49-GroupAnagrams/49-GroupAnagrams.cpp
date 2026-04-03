// Last updated: 4/3/2026, 9:48:34 PM
1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4        unordered_map<string,vector<string>>mp;
5        for(const string &str:strs){
6            string sortedword=str;
7            sort(sortedword.begin(),sortedword.end());
8            mp[sortedword].push_back(str);
9        }
10        vector<vector<string>>result;
11        for(auto &i:mp)
12            result.push_back(move(i.second));
13        return result;
14    }
15};