// Last updated: 6/22/2026, 6:29:49 PM
class Solution {
public:
    int concatenatedBinary(int n) {
        long long res = 0;
        int MOD = 1e9 + 7;
        int bitLength = 0;

        for (int i = 1; i <= n; ++i) {
            // If i is a power of 2, the number of bits increases
            // Example: 2 (10), 4 (100), 8 (1000)
            if ((i & (i - 1)) == 0) {
                bitLength++;
            }

            // Shift res by the length of i and add i
            res = ((res << bitLength) | i) % MOD;
        }

        return (int)res;
    }
};