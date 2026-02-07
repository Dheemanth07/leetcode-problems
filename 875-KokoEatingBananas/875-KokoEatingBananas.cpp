// Last updated: 2/7/2026, 8:18:37 PM
1class Solution {
2public:
3    int minEatingSpeed(vector<int>& piles, int h) {
4        int left = 1;
5        int right = *max_element(piles.begin(), piles.end());
6        while (left < right) {
7            int mid = left + (right - left) / 2;
8            long total = 0;
9            for (int p : piles)
10                total += (p + mid - 1) / mid;
11            if (total <= h)
12                right = mid;
13            else
14                left = mid + 1;
15        }
16        return left;
17    }
18};
19