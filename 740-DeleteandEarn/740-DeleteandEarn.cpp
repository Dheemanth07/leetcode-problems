// Last updated: 7/8/2026, 11:08:46 PM
1class Solution {
2public:
3    int deleteAndEarn(vector<int>& nums) {
4        if (nums.empty())
5            return 0;
6
7        // 1. Find the maximum number so we know how long our street needs to be
8        int max_val = 0;
9        for (int num : nums) 
10            max_val = max(max_val, num);
11
12        // 2. Build the "Street of Houses"
13        // The index is the number itself, the value is the total points you'd
14        // earn taking it
15        vector<int> street(max_val + 1, 0);
16        for (int num : nums) 
17            street[num] += num; // Summing up all occurrences natively!
18
19        // 3. Exactly House Robber 1 logic
20        int prev2 = 0;
21        int prev1 = 0;
22
23        for (int i = 0; i <= max_val; i++) {
24            // max(Rob It, Skip It)
25            int current = max(street[i] + prev2, prev1);
26            prev2 = prev1;
27            prev1 = current;
28        }
29
30        return prev1;
31    }
32};