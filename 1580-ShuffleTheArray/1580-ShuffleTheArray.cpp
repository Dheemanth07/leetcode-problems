// Last updated: 6/22/2026, 6:30:00 PM
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        if(nums.empty()) return {};
        vector<int>res;
        int l=0,r=n;
        while(l<n && r<2*n){
            res.push_back(nums[l++]);
            res.push_back(nums[r++]);
        }
        return res;
    }
};