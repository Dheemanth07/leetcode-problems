// Last updated: 6/22/2026, 6:30:46 PM
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto i=0;i<nums.size();i++)
            nums[i]=pow(nums[i],2);
        sort(nums.begin(),nums.end());
        return nums;
    }
};