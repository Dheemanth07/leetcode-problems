// Last updated: 6/24/2026, 6:19:38 PM
1class Solution {
2public:
3    int mySqrt(int x) {
4        if (!x)
5            return 0;
6
7        // Apply the formula: e^(0.5 * ln(x))
8        int ans = exp(0.5 * log(x));
9
10        // The safety check for floating point precision
11        // If (ans + 1) squared is still <= x, we know the math undershot.
12        if ((long long)(ans + 1) * (ans + 1) <= x) 
13            return ans + 1;
14
15        return ans;
16    }
17};