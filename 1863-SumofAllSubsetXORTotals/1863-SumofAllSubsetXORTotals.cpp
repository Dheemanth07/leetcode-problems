// Last updated: 1/18/2026, 7:54:57 PM
1class Solution {
2public:
3    int totalSums=0;
4
5    void dfs(int index,int curXor,vector<int>&nums){
6        if(index==nums.size()){
7            totalSums+=curXor;
8            return;
9        }
10        dfs(index+1,curXor^nums[index],nums);
11        dfs(index+1,curXor,nums);
12    }
13
14    int subsetXORSum(vector<int>& nums) {
15        dfs(0,0,nums);
16        return totalSums;
17    }
18};