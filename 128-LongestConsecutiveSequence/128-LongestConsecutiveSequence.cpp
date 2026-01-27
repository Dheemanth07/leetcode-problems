// Last updated: 1/27/2026, 10:21:17 PM
1class Solution {
2public:
3    int longestConsecutive(vector<int>& nums) {
4        unordered_set<int>numset(nums.begin(),nums.end());
5        int longest=0;
6        for(int num:numset){
7            if(numset.find(num-1)==numset.end()){
8                int currentnum=num;
9                int currentstreak=1;
10                while(numset.find(currentnum+1)!=numset.end()){
11                    currentnum++;
12                    currentstreak++;
13                }
14                longest=max(longest,currentstreak);
15            }
16        }
17        return longest;
18    }
19};