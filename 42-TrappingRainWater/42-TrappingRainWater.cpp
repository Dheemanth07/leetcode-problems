// Last updated: 6/25/2026, 11:34:11 AM
1class Solution {
2public:
3    int trap(vector<int>& height) {
4        int left = 0, right = height.size() - 1;
5        int leftmax = 0, rightmax = 0, water = 0;
6
7        while (left < right) {
8
9            // Step 1: Identify the bottleneck.
10            // If the block at 'left' is shorter than the block at 'right',
11            // the right side provides a safe boundary. Left is our bottleneck.
12            if (height[left] < height[right]) {
13
14                // Step 2: Process the left side using the ternary operator.
15                // Condition: Is our current block taller than our historical
16                // leftmax? True (?): It can't trap water. It becomes the new
17                // leftmax boundary. False (:): It is a valley! It traps water
18                // equal to (leftmax - its height).
19                height[left] >= leftmax ? (leftmax = height[left])
20                                        : water += (leftmax - height[left]);
21
22                // Step 3: Move the bottleneck pointer inward.
23                left++;
24            }
25            // Step 1 (Alternate): The right side is the bottleneck.
26            else {
27
28                // Step 2: Process the right side using the exact mirrored
29                // logic.
30                height[right] >= rightmax ? (rightmax = height[right])
31                                          : water += (rightmax - height[right]);
32
33                // Step 3: Move the bottleneck pointer inward.
34                right--;
35            }
36        }
37
38        return water;
39    }
40};