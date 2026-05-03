// Last updated: 5/3/2026, 8:58:31 AM
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
15                // Condition: Is our current block taller than our historical leftmax?
16                // True (?): It can't trap water. It becomes the new leftmax boundary.
17                // False (:): It is a valley! It traps water equal to (leftmax - its height).
18                height[left] >= leftmax ? (leftmax = height[left]) 
19                                        : water += (leftmax - height[left]);
20                
21                // Step 3: Move the bottleneck pointer inward.
22                left++;
23            } 
24            // Step 1 (Alternate): The right side is the bottleneck.
25            else {
26                
27                // Step 2: Process the right side using the exact mirrored logic.
28                height[right] >= rightmax ? (rightmax = height[right]) 
29                                          : water += (rightmax - height[right]);
30                
31                // Step 3: Move the bottleneck pointer inward.
32                right--;
33            }
34        }
35        
36        return water;
37    }
38};