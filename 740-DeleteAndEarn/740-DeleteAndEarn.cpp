// Last updated: 7/17/2026, 2:02:13 PM
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty())
            return 0;

        // 1. Find the maximum number so we know how long our street needs to be
        int max_val = 0;
        for (int num : nums) 
            max_val = max(max_val, num);

        // 2. Build the "Street of Houses"
        // The index is the number itself, the value is the total points you'd
        // earn taking it
        vector<int> street(max_val + 1, 0);
        for (int num : nums) 
            street[num] += num; // Summing up all occurrences natively!

        // 3. Exactly House Robber 1 logic
        int prev2 = 0;
        int prev1 = 0;

        for (int i = 0; i <= max_val; i++) {
            // max(Rob It, Skip It)
            int current = max(street[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};