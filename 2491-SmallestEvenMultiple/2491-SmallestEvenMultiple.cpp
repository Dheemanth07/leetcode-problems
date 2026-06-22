// Last updated: 6/22/2026, 6:29:18 PM
class Solution {
public:
    int smallestEvenMultiple(int n) {
        while(n%2!=0)
            n*=2;
        return n;
    }
};