// Last updated: 2/3/2026, 8:02:07 PM
1class Solution {
2public:
3    int romanToInt(string s) {
4        unordered_map<char,int>mp={
5            {'I',1},{'V',5},{'X',10},
6            {'L',50},{'C',100},{'D',500},{'M',1000}
7        };
8        int total=0;
9        int n=s.length();
10        for(int i=0;i<n;i++){
11            if(i<n-1 && mp[s[i]]<mp[s[i+1]])
12                total-=mp[s[i]];
13            else
14                total+=mp[s[i]];
15        }
16        return total;
17
18    }
19};