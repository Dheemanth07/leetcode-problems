// Last updated: 1/25/2026, 1:40:01 PM
1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4        if(s.size()!=t.size())
5            return false;
6        unordered_map<char,int>count;
7        for(char c:s) count[c]++;
8        for(char c:t)
9            if(--count[c]<0) return false;
10        return true;
11    }
12
13    /*Below code only if input strings are lower case 
14        if (s.length() != t.length()) return false;
15        vector<int>count(26,0);
16        for (char c : s) count[c - 'a']++;
17        for (char c : t) {
18            if (--count[c - 'a'] < 0) return false;
19        }
20        return true;
21    }*/
22};