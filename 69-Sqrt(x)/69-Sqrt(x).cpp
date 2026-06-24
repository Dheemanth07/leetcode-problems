// Last updated: 6/24/2026, 6:16:09 PM
1class Solution {
2public:
3    int mySqrt(int x) {
4        int l = 1;
5        int r = x;
6        while (l <= r) {
7            int m = (r - l) / 2 + l;
8            if (m > x / m)
9                r = m - 1;
10            else if (m < x / m)
11                l = m + 1;
12            else
13                return m;
14        }
15        return r;
16    }
17};