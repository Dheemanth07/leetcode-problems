// Last updated: 7/22/2026, 2:09:08 PM
1class Solution {
2public:
3    int jump(vector<int>& nums) {
4        // Base case: If the array has only 1 element, we are already at the
5        // end.
6        if (nums.size() <= 1)
7            return 0;
8
9        int jumps = 0;
10        int current_end = 0;
11        int farthest = 0;
12
13        // Notice we stop at nums.size() - 1 (the second to last element)
14        for (int i = 0; i < nums.size() - 1; i++) {
15
16            // 1. Always scout for the best possible future jump
17            farthest = max(farthest, i + nums[i]);
18
19            // 2. If we have hit the boundary of our current jump's range...
20            if (i == current_end) {
21                jumps++;                // We are forced to jump!
22                current_end = farthest; // Our new boundary is the best
23                                        // projection we found
24
25                // Early exit: If our new boundary already reaches the end, we
26                // can stop early!
27                if (current_end >= nums.size() - 1)
28                    break;
29            }
30        }
31
32        return jumps;
33    }
34};