// Last updated: 7/17/2026, 2:02:20 PM
class Solution {
public:
    bool hasAlternatingBits(int n) {
        // Step 1: XOR n with itself shifted right by 1
        // Using 'long' to prevent overflow when doing x + 1
        long x = n ^ (n >> 1);

        // Step 2: Check if x is a number consisting of all 1s
        // Trick: (x & (x + 1)) == 0 only works for numbers like 3(11), 7(111), 15(1111)
        return (x & (x + 1)) == 0;
    }
};