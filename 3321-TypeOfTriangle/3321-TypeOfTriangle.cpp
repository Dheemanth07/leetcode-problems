// Last updated: 6/22/2026, 6:28:54 PM
class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(!nums.empty() && (nums[0]+nums[1]>nums[2]) && (nums[0]+nums[2]>nums[1]) && (nums[1]+nums[2]>nums[0])){
            if(nums[0]==nums[1] && nums[1]==nums[2])
                return "equilateral";
            else if(nums[0]==nums[1] || nums[0]==nums[2] || nums[1]==nums[2])
                return "isosceles";         
            else
                return "scalene";
        }
        else
            return "none";
    }
};