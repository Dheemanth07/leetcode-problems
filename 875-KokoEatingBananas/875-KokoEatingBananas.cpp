// Last updated: 6/24/2026, 12:50:29 PM
1class Solution {
2public:
3    int minEatingSpeed(vector<int>& piles, int h) {
4        // Pillar 1: The Search Space
5        int left = 1;
6
7        // Find the maximum pile to set our upper bound
8        int right = *max_element(piles.begin(), piles.end());
9
10        int best_speed = right; // Store the best valid answer we find
11
12        while (left <= right) {
13            int mid = left + (right - left) / 2;
14
15            // Pillar 2: The Test
16            long long total_hours = 0;
17            for (int p : piles)
18                // Integer math trick for Ceiling Division: ceil(a/b) = (a + b -
19                // 1) / b
20                total_hours += (p + mid - 1) / mid;
21
22            // Pillar 3: The Decision
23            if (total_hours <= h) {
24                // Fast enough! Record it, but try to find a slower valid speed
25                best_speed = mid;
26                right = mid - 1;
27            } else
28                // Too slow! We must eat faster
29                left = mid + 1;
30        }
31
32        return best_speed;
33    }
34};
35