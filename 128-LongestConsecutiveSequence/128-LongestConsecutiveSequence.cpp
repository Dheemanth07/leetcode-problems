// Last updated: 1/27/2026, 10:21:51 PM
1class Solution {
2public:
3    int longestConsecutive(vector<int>& nums) {
4        unordered_set<int>s(nums.begin(),nums.end());
5        int longest=0;
6        for(int num:s){
7            if(s.find(num-1)==s.end()){
8                int current=num;
9                int length=1;
10                while(s.find(current+1)!=s.end()){
11                    current++;
12                    length++;
13                }
14                longest=max(longest,length);
15            }
16        }
17        return longest;
18    }
19};
20