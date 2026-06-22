// Last updated: 6/22/2026, 6:28:58 PM
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxi = 0;
        int n=nums.size();
        for (int i = 0; i < n; i++) {
            set<int> s1, s2;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2)
                    s2.insert(nums[j]);
                else
                    s1.insert(nums[j]);
            if (s1.size() == s2.size())
                maxi = max(maxi, j - i + 1);
            }
        }
        return maxi;
    }
};