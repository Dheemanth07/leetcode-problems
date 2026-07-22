// Last updated: 7/22/2026, 9:13:35 PM
1class Solution {
2public:
3    int deleteAndEarn(vector<int>& nums) {
4        if (nums.empty())
5            return 0;
6
7        // 1. Find the maximum number so we know how long our street needs to be
8        int max_val = *max_element(nums.begin(),nums.end());
9
10        // 2. Build the "Street of Houses"
11        // The index is the number itself, the value is the total points you'd
12        // earn taking it
13        vector<int> street(max_val + 1, 0);
14        for (int num : nums) 
15            street[num] += num; // Summing up all occurrences natively!
16
17        // 3. Exactly House Robber 1 logic
18        int prev2 = 0;
19        int prev1 = 0;
20
21        for (int i = 0; i <= max_val; i++) {
22            // max(Rob It, Skip It)
23            int current = max(street[i] + prev2, prev1);
24            prev2 = prev1;
25            prev1 = current;
26        }
27
28        return prev1;
29    }
30};