// Last updated: 7/8/2026, 9:18:36 PM
1class Solution {
2public:
3    int rob(vector<int>& nums) {
4        // rob1 tracks the max money we could make up to 2 houses ago
5        int rob1 = 0;
6
7        // rob2 tracks the max money we could make up to 1 house ago
8        int rob2 = 0;
9
10        // Walk down the street, house by house
11        for (int i = 0; i < nums.size(); i++) {
12            // THE CORE DP DECISION:
13            // max( Rob this house + money from 2 houses ago,  Skip this house
14            // and keep money from 1 house ago )
15            int currentMax = max(nums[i] + rob1, rob2);
16
17            // Shift our sliding window forward for the next house!
18            rob1 = rob2;
19            rob2 = currentMax;
20        }
21
22        // By the time we reach the end of the street, rob2 holds the absolute
23        // maximum
24        return rob2;
25    }
26};