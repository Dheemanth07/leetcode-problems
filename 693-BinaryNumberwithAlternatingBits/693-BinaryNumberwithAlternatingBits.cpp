// Last updated: 2/18/2026, 4:47:42 PM
1class Solution {
2public:
3    bool hasAlternatingBits(int n) {
4        int prevBit = n % 2;
5        n >>= 1;
6        while (n) {
7            int currBit = n % 2;
8            if (currBit == prevBit)
9                return false;
10            prevBit = currBit;
11            n >>= 1;
12        }
13        return true;
14    }
15};