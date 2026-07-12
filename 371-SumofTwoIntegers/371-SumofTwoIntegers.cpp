// Last updated: 7/12/2026, 9:05:29 PM
1class Solution {
2public:
3    int getSum(int a, int b) {
4
5        while (b != 0) {
6
7            unsigned int carry = (unsigned int)(a & b);
8
9            a = a ^ b;
10
11            b = carry << 1;
12        }
13
14        return a;
15    }
16};