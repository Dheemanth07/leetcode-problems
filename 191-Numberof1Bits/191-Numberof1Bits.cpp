// Last updated: 7/12/2026, 8:51:12 PM
1class Solution {
2public:
3    int hammingWeight(int n) {
4        int count = 0;
5
6        while (n) {
7            count++;
8            n = n & (n - 1);
9        }
10
11        return count;
12    }
13};