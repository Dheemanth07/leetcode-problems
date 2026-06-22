// Last updated: 6/22/2026, 6:29:32 PM
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        if (nums.empty())
            return {};
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
            ans.push_back(nums[i]);
        for(int i=0;i<n;i++)
            ans.push_back(nums[i]);
        return ans;
    }
};