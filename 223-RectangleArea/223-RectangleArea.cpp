// Last updated: 7/15/2026, 12:48:42 PM
1class Solution {
2public:
3    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
4                    int bx2, int by2) {
5        // 1. Calculate areas of both rectangles
6        int area1 = (ax2 - ax1) * (ay2 - ay1);
7        int area2 = (bx2 - bx1) * (by2 - by1);
8
9        // 2. Calculate overlap width and height
10        // Using max(0, ...) ensures that if they don't overlap, the dimension
11        // is 0.
12        int overlapWidth = max(0, min(ax2, bx2) - max(ax1, bx1));
13        int overlapHeight = max(0, min(ay2, by2) - max(ay1, by1));
14
15        // 3. Calculate overlap area
16        int overlapArea = overlapWidth * overlapHeight;
17
18        // 4. Return total area
19        return area1 + area2 - overlapArea;
20    }
21};