// Last updated: 2/18/2026, 4:48:37 PM
1class Solution {
2public:
3    bool hasAlternatingBits(int n) {
4        // Step 1: XOR n with itself shifted right by 1
5        // Using 'long' to prevent overflow when doing x + 1
6        long x = n ^ (n >> 1);
7
8        // Step 2: Check if x is a number consisting of all 1s
9        // Trick: (x & (x + 1)) == 0 only works for numbers like 3(11), 7(111), 15(1111)
10        return (x & (x + 1)) == 0;
11    }
12};