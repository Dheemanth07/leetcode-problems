// Last updated: 6/23/2026, 4:26:57 PM
1class Solution {
2public:
3    int subarraysDivByK(vector<int>& nums, int k) {
4        vector<int> remCount(k, 0);
5        remCount[0] = 1;
6
7        int prefixSum = 0, count = 0, rem;
8
9        for (int num : nums) {
10            prefixSum += num;
11            rem = ((prefixSum % k) + k) % k;
12            count += remCount[rem]++;
13        }
14
15        return count;
16    }
17};