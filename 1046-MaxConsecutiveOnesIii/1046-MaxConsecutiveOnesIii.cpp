// Last updated: 6/22/2026, 6:30:39 PM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int max_len = 0;
        int zero_budget = k;

        for (int right = 0; right < nums.size(); right++) {
            if (!nums[right])
                zero_budget--;

            while (zero_budget < 0) {
                if (!nums[left])
                    zero_budget++;
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};