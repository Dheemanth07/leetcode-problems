// Last updated: 2/28/2026, 8:19:34 PM
1class Solution {
2public:
3    int concatenatedBinary(int n) {
4        long long res = 0;
5        int MOD = 1e9 + 7;
6        int bitLength = 0;
7
8        for (int i = 1; i <= n; ++i) {
9            // If i is a power of 2, the number of bits increases
10            // Example: 2 (10), 4 (100), 8 (1000)
11            if ((i & (i - 1)) == 0) {
12                bitLength++;
13            }
14
15            // Shift res by the length of i and add i
16            res = ((res << bitLength) | i) % MOD;
17        }
18
19        return (int)res;
20    }
21};