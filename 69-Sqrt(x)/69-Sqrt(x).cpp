// Last updated: 6/24/2026, 6:18:09 PM
1class Solution {
2public:
3    int mySqrt(int x) {
4        if (x == 0)
5            return 0;
6
7        long t = x; // Start with x as our initial guess
8
9        // While our guess squared is greater than x, keep refining
10        while (t * t > x) {
11            t = (t + x / t) / 2;
12        }
13
14        return t;
15    }
16};