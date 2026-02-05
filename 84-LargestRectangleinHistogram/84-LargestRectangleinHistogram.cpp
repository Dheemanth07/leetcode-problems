// Last updated: 2/5/2026, 7:58:00 PM
1class Solution {
2public:
3    int largestRectangleArea(vector<int>& heights) {
4        int n = heights.size();
5        stack<int> st; // Stores indices
6        int maxArea = 0;
7
8        for (int i = 0; i <= n; i++) {
9            // Use 0 as a sentinel value for the end of the histogram
10            int currentHeight = (i == n) ? 0 : heights[i];
11
12            // While current height is smaller than the height at stack top
13            while (!st.empty() && currentHeight < heights[st.top()]) {
14                int h = heights[st.top()];
15                st.pop();
16
17                // Width is the distance between current index i and
18                // the new top of the stack (the previous smaller element)
19                int w = st.empty() ? i : (i - st.top() - 1);
20
21                maxArea = max(maxArea, h * w);
22            }
23            st.push(i);
24        }
25
26        return maxArea;
27    }
28};