// Last updated: 1/25/2026, 7:58:22 PM
1class Solution {
2public:
3    string longestCommonPrefix(vector<string>& strs) {
4        if(strs.empty()) return "";
5        sort(strs.begin(),strs.end());
6        string first = strs.front();
7        string last = strs.back();
8        string s = "";
9        for(int i=0;i<min(first.length(),last.length());i++){
10            if(first[i]!=last[i])
11                return s;
12            s+=first[i];
13        }
14        return s;
15    }
16};