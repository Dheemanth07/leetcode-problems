// Last updated: 7/17/2026, 2:00:32 PM
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        int count = 0;

        while (x) {
            count++;
            x &= (x - 1);
        }

        return count;
    }
};