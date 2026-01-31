// Last updated: 1/31/2026, 10:33:36 PM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        int maxlen=0,start=0;
5        vector<int>lastindex(256,-1);
6        for(int i=0;i<s.length();i++){
7            if(lastindex[s[i]]>=start){
8                start=lastindex[s[i]]+1;
9            }
10            lastindex[s[i]]=i;
11            maxlen=max(maxlen,i-start+1);
12        }
13        return maxlen;
14    }
15};