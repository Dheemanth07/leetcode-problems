// Last updated: 7/6/2026, 2:01:11 PM
1class Solution {
2public:
3    int findMinArrowShots(vector<vector<int>>& points) {
4        if (points.empty())
5            return 0;
6
7        // 1. Sort by END coordinate (Ascending)
8        sort(points.begin(), points.end(),
9             [](const vector<int>& a, const vector<int>& b) {
10                 return a[1] < b[1];
11             });
12
13        // 2. We always need at least 1 arrow for the first balloon
14        int arrows = 1;
15        int last_arrow_x = points[0][1];
16
17        // 3. Sweep through the rest of the balloons
18        for (int i = 1; i < points.size(); i++) {
19            // If the current balloon starts AFTER the last arrow position,
20            // the old arrow cannot pop it. We need a new one!
21            if (points[i][0] > last_arrow_x) {
22                arrows++;
23                last_arrow_x =
24                    points[i][1]; // Update arrow to the end of this balloon
25            }
26            // Otherwise, it starts before or at the arrow position,
27            // so it is automatically burst by the existing arrow!
28        }
29
30        return arrows;
31    }
32};