// Last updated: 7/12/2026, 9:00:49 PM
1class Solution {
2public:
3    uint32_t reverseBits(uint32_t n) {
4
5        uint32_t ans = 0;
6
7        for (int i = 0; i < 32; i++) {
8
9            ans <<= 1;      // make room
10            ans |= (n & 1); // copy last bit
11            n >>= 1;        // remove last bit
12        }
13
14        return ans;
15    }
16};