// Last updated: 6/22/2026, 6:29:01 PM
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());       
        for(size_t i=0;i<nums.size();i+=2)
            swap(nums[i],nums[i+1]);
        return nums;
    }
};