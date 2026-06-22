// Last updated: 6/22/2026, 6:30:04 PM
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            int count=0;
            for(int j=0;j<nums.size();j++){
                if(i==j) continue;
                if(nums[j]<nums[i]) count++;
            }
            res.push_back(count);
        }
        return res;
    }
};