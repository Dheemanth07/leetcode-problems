// Last updated: 6/22/2026, 6:29:34 PM
class Solution {
public:
    int totalSums=0;

    void dfs(int index,int curXor,vector<int>&nums){
        if(index==nums.size()){
            totalSums+=curXor;
            return;
        }
        dfs(index+1,curXor^nums[index],nums);
        dfs(index+1,curXor,nums);
    }

    int subsetXORSum(vector<int>& nums) {
        dfs(0,0,nums);
        return totalSums;
    }
};