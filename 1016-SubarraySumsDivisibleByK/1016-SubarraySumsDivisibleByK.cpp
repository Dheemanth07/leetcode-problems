// Last updated: 6/22/2026, 6:30:47 PM
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> remCount(k,0);
        int prefixSum = 0, count = 0, rem;
        remCount[0] = 1;
        for (int num : nums) {
            prefixSum += num;
            rem = ((prefixSum % k) + k) % k;
            count += remCount[rem]++;
        }
        return count;
    }
};